#!/usr/bin/env python3
"""Pinned, read-only Town1 bounds/resource inspection. No game or Server execution.
Python 3.10+ standard library. Reuses the SHA-pinned W3-07 STPD/EX reader.
Topology/candidate positions are reconstruction aids, not official spawn evidence.
"""
from __future__ import annotations
import argparse
from array import array
from collections import Counter, deque
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import struct
import subprocess
import sys
from xml.etree import ElementTree as ET
import zlib

PINS = {
    'Tartaros.bin': '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91',
    'BoundMap.stp': '07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8',
    'Table.stp': '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442',
    'Event.stp': '2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b',
}
HELPER_SHA = '977a58b576122d7027e810c3ab0c91b727a5cb5cfe3b80636fcb58094666dc47'
BND_SHA = '30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6'
WINDOWS = [
    ('trigger-map-lookup', 0x4DF582, 0x4DF5BC),
    ('bound-resource-loader', 0x4DF1A0, 0x4DF490),
    ('v0-reader', 0x82F660, 0x82F84E),
    ('version-dispatch', 0x830040, 0x8300CD),
    ('cache-rebuild', 0x82FA80, 0x82FBE1),
    ('tile-build', 0x8330E0, 0x833271),
    ('tile-bitpack', 0x837BE0, 0x837D49),
    ('query-owner-ctor', 0x82CBC0, 0x82CD29),
    ('query-layer-bind', 0x82FF10, 0x830033),
    ('two-layer-point-query', 0x82CDF0, 0x82CE72),
    ('point-clamp', 0x82CE80, 0x82CED5),
    ('tile-cell-read', 0x832DA0, 0x832EB9),
    ('float-truncation', 0x8FED10, 0x8FEDBC),
]


def require(ok: bool, message: str) -> None:
    if not ok:
        raise ValueError(message)


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def archive_names(raw: bytes) -> list[str]:
    require(raw[:4] == b'STPD', 'Not STPD')
    data = raw.translate(bytes(i ^ 255 for i in range(256)))
    index = struct.unpack_from('<I', data, 4)[0]
    require(raw[index:index+4] == b'STPI', 'Not STPI')
    pos = index + 8
    names: list[str] = []

    def node(parent: str, depth: int = 0) -> None:
        nonlocal pos
        require(depth < 64, 'Index depth limit')
        size = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        name = data[pos:pos+size].decode('ascii').rstrip('\0')
        pos += size
        kind = data[pos]
        pos += 1
        path = '/'.join(filter(None, (parent, name)))
        if kind in (1, 2):
            count = struct.unpack_from('<I', data, pos)[0]
            pos += 12
            require(count < 100000, 'Index count limit')
            for _ in range(count):
                node(path, depth + 1)
        elif kind == 0:
            pos += 16
            names.append(path)
        else:
            raise ValueError(f'Unknown index kind {kind}')

    node('')
    require(pos == len(data) and len(names) == len(set(names)), 'Index mismatch')
    return names


def topology(mask: bytearray, width: int, height: int):
    """4-neighbor components; 8-neighbor distance to blocked/exterior. Analyst policy."""
    labels = array('I', [0]) * len(mask)
    components = []
    for start, is_free in enumerate(mask):
        if not is_free or labels[start]:
            continue
        number = len(components) + 1
        labels[start] = number
        queue = deque([start])
        count = 0
        xmin = xmax = start % width
        ymin = ymax = start // width
        while queue:
            i = queue.popleft()
            x, y = i % width, i // width
            count += 1
            xmin, xmax = min(xmin, x), max(xmax, x)
            ymin, ymax = min(ymin, y), max(ymax, y)
            for j in (i-1 if x else -1, i+1 if x+1 < width else -1,
                      i-width if y else -1, i+width if y+1 < height else -1):
                if j >= 0 and mask[j] and not labels[j]:
                    labels[j] = number
                    queue.append(j)
        components.append({'id': number, 'cells': count, 'cell_aabb_inclusive': [xmin,ymin,xmax,ymax]})
    distance = array('I', [0]) * len(mask)
    for i, is_free in enumerate(mask):
        if not is_free:
            continue
        x, y = i % width, i // width
        distance[i] = 1 if x == 0 or y == 0 or x == width-1 else 1 + min(
            distance[i-1], distance[i-width-1], distance[i-width], distance[i-width+1])
    for i in range(len(mask)-1, -1, -1):
        if not mask[i]:
            continue
        x, y = i % width, i // width
        d = 1 if x == width-1 or y == height-1 or x == 0 else 1 + min(
            distance[i+1], distance[i+width-1], distance[i+width], distance[i+width+1])
        distance[i] = min(distance[i], d)
    for c in components:
        best = max((i for i, label in enumerate(labels) if label == c['id']),
                   key=lambda i: (distance[i], -i))
        x, y, d = best % width, best // width, int(distance[best])
        c.update(candidate_cell=[x,y], candidate_world_xy=[2*x+1,2*y+1],
                 chebyshev_distance_to_blocked_or_exterior_cells=d,
                 verified_zero_square_side_cells=2*d-1)
    return labels, distance, sorted(components, key=lambda c: (-c['cells'], c['id']))


def inspect(root: Path, helper_path: Path, assembly: Path | None = None) -> dict:
    require(sha(helper_path.read_bytes()) == HELPER_SHA, 'W3-07 helper SHA mismatch')
    spec = importlib.util.spec_from_file_location('w3_07_pinned_reader', helper_path)
    require(spec is not None and spec.loader is not None, 'Cannot load helper')
    helper = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(helper)
    sources, raw, inventories = {}, {}, []
    for name, pin in PINS.items():
        raw[name] = (root/name).read_bytes()
        require(sha(raw[name]) == pin, name + ' SHA mismatch')
        sources[name] = {'bytes':len(raw[name]), 'sha256':pin}
        if name.endswith('.stp'):
            names = archive_names(raw[name])
            inventories.append({'archive':name, 'indexed_files':len(names),
                                'mef_member_names':[n for n in names if n.lower().endswith('.mef')]})
    bnd = helper.stp_selected(raw['BoundMap.stp'], {'BoundMap/town001.bnd'})['BoundMap/town001.bnd']
    require(sha(bnd) == BND_SHA and len(bnd) == 12044, 'Town1 member mismatch')
    version,w,h,wx,wy = struct.unpack_from('<IIIff', bnd, 0x20)
    require((version,w,h,wx,wy) == (0,768,768,1536.,1536.), 'Unsupported Town1 header')
    layer_info, layers, cursor, empty = [], [], 0x234, []
    for i in range(32):
        offset,comp,expanded,count = struct.unpack_from('<4I', bnd, 0x34+16*i)
        if not count:
            require((offset,comp,expanded) == (0xffffffff,0,0), 'Unexpected empty layer')
            empty.append(i)
            continue
        require(i == len(layers) and i < 2 and offset == cursor, 'Layer order/offset mismatch')
        require(expanded == count*4 == w*h*4 and offset+comp <= len(bnd), 'Layer bounds mismatch')
        dz = zlib.decompressobj()
        data = dz.decompress(bnd[offset:offset+comp], expanded+1)
        require(len(data) == expanded and dz.eof and not dz.unused_data and not dz.unconsumed_tail,
                'Layer zlib stream mismatch')
        a = array('I'); a.frombytes(data)
        require(a.itemsize == 4, 'Platform needs 32-bit unsigned int')
        if sys.byteorder != 'little': a.byteswap()
        require(set(a) <= {0,1}, 'Unexpected values for pinned Town1')
        layers.append(a)
        layer_info.append({'index':i,'offset':offset,'compressed_bytes':comp,'expanded_bytes':expanded,
                           'cells':count,'sha256':sha(data),'value_counts':dict(Counter(a))})
        cursor += comp
    require(len(layers) == 2 and cursor == len(bnd), 'Town1 layers/trailer mismatch')
    mask = bytearray(a == 0 and b == 0 for a,b in zip(*layers))
    labels,distance,components = topology(mask,w,h)
    samples = []
    for x,y in [components[0]['candidate_world_xy'], (900,900), (734,744)]:
        require(math.isfinite(x) and math.isfinite(y) and 0 <= x < wx and 0 <= y < wy, 'Invalid point')
        cx,cy = int(x*w/wx), int(y*h/wy); i = cy*w+cx
        samples.append({'xy':[x,y], 'cell':[cx,cy], 'layers':[int(a[i]) for a in layers],
                        'component':int(labels[i]), 'chebyshev_distance_cells':int(distance[i])})
    selected = {'Table/_MapList.xml','Table/_TownList.xml','Table/_ActorList.xml',
                'Table/npctable.xml','Table/QuestInfo.xml'}
    members = helper.stp_selected(raw['Table.stp'], selected)
    trees = {n:ET.fromstring(b.decode('utf-8-sig')) for n,b in members.items()}
    map_row = trees['Table/_MapList.xml'].find(".//*[@ID='182']")
    require(map_row is not None and map_row.get('TRIGGER') == 'town001.mef', 'Map row mismatch')
    town = trees['Table/_TownList.xml'].find("./TOWN[@ID='1']")
    require(town is not None, 'Town1 missing')
    npcs = []
    for entry in town.findall('./NPCLIST/NPC'):
        mid = entry.get('ID')
        actor = trees['Table/_ActorList.xml'].find(f".//ACTOR[@ID='{mid}'][@PRE='1']")
        npc = trees['Table/npctable.xml'].find(f"./NPC[@ID='{mid}']")
        require(actor is not None and npc is not None, 'NPC metadata missing')
        quests = [int(q.get('id')) for q in trees['Table/QuestInfo.xml'].iter('Quest')
                  if q.get('type') == '2' and q.get('town') == '1' and q.get('giver') == mid]
        npcs.append({'model_id':int(mid),'pre':1,'actor_file':actor.get('FILE'),
                     'table_scale_raw':actor.get('SCALE'),'npc_table_type':npc.get('TYPE'),
                     'mainline_giver_quest_ids':quests,'original_placement':None})
    binary = raw['Tartaros.bin']; sections = helper.pe_sections(binary)
    slices = []
    if assembly: require(not assembly.exists(), 'Assembly directory exists'); assembly.mkdir(parents=True)
    for label,a,z in WINDOWS:
        pos = helper.raw_offset(sections,a,z-a); data = binary[pos:pos+z-a]
        slices.append({'id':label,'va':hex(a),'end_exclusive':hex(z),'raw':hex(pos),
                       'bytes':len(data),'sha256':sha(data)})
        if assembly:
            result = subprocess.run(['objdump','-D','-b','binary','-m','i386','-M','intel',
                    f'--adjust-vma={a-pos:#x}',f'--start-address={a:#x}',f'--stop-address={z:#x}',
                    str(root/'Tartaros.bin')],check=True,capture_output=True,text=True)
            (assembly/(label+'.asm')).write_text(result.stdout,encoding='utf-8')
    return {'schema':'W3-08-town001-evidence-v1', 'sources':sources, 'archive_name_scan':inventories,
            'map182':dict(map_row.attrib), 'table_members':[
                {'name':n,'bytes':len(members[n]),'sha256':sha(members[n])} for n in sorted(members)],
            'town1_npcs':npcs, 'bounds':{'member':'BoundMap/town001.bnd','bytes':len(bnd),'sha256':sha(bnd),
                'version':version,'grid':[w,h],'world':[wx,wy],'layers':layer_info,'empty_layers':empty,
                'both_layers_zero_cells':sum(mask),'mask_sha256':sha(mask),
                'four_neighbor_component_count':len(components),
                'component_sizes':[{'id':c['id'],'cells':c['cells']} for c in components],
                'components_by_size':components[:3],
                'samples':samples}, 'native_slices':slices,
            'classification':{'bounds_decode':'PASS','native_semantic_full_pass':'NOT_CLAIMED',
                'topology':'analyst 4-neighbor policy, not native pathfinding',
                'spawn':'RECONSTRUCTION_CANDIDATE_NOT_APPROVED','original_mef_format':'UNKNOWN',
                'npc_placement':'UNKNOWN','game_and_server_execution':'NOT_RUN'}}


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--sources',type=Path,required=True)
    ap.add_argument('--prior-verifier',type=Path,
                    default=Path(__file__).resolve().parent.parent/'W3-07-normal-town'/'verify.py')
    ap.add_argument('--output',type=Path,required=True)
    ap.add_argument('--check',type=Path)
    ap.add_argument('--assembly-dir',type=Path)
    a = ap.parse_args()
    require(not a.output.exists(), 'Refusing to overwrite output')
    result = inspect(a.sources,a.prior_verifier,a.assembly_dir)
    normalized = json.loads(json.dumps(result))
    if a.check: require(normalized == json.loads(a.check.read_text(encoding='utf-8')), 'Evidence differs')
    a.output.parent.mkdir(parents=True,exist_ok=True)
    with a.output.open('x',encoding='utf-8',newline='\n') as f:
        f.write(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({'bounds_decode':'PASS','components':result['bounds']['four_neighbor_component_count'],
                      'candidate':result['bounds']['components_by_size'][0]['candidate_world_xy'],
                      'game_and_server_execution':'NOT_RUN','output':str(a.output)}))


if __name__ == '__main__':
    try: main()
    except (OSError,ValueError,KeyError,IndexError,struct.error,zlib.error,subprocess.SubprocessError,ET.ParseError) as e:
        print(f'W3-08 inspection failed: {e}',file=sys.stderr); sys.exit(1)
