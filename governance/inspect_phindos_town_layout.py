"""Read-only pinned static layout qualification; positions are Server policy only."""
import argparse
import hashlib
import json
import struct
import xml.etree.ElementTree as ET
import zlib
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--workspace', required=True, type=Path)
    p.add_argument('--output', required=True, type=Path)
    a = p.parse_args()
    assert not a.output.exists()
    town_name = 'Table/_TownList.xml'
    table_sha = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
    town = decode(members((a.workspace/'anal/backups/Table.original-kr.stp').read_bytes(), table_sha, [town_name])[town_name])
    town_sha = hashlib.sha256(town).hexdigest()
    assert town_sha == 'bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660'
    root = ET.fromstring(town.decode('utf-8-sig'))
    npc_ids = [int(e.get('ID')) for e in root.findall("./TOWN[@ID='1']/NPCLIST/NPC")]
    assert npc_ids == [10001,10002,10003,10008,10013,10014,10047,10048,10015]
    name = 'BoundMap/town001.bnd'
    b = members((a.workspace/'Map/BoundMap.stp').read_bytes(), selected_members=[name])[name]
    sha = hashlib.sha256(b).hexdigest()
    assert sha == '30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6'
    assert b[:21] == b'MapTool Reinforce 1.0'
    version,w,h,wx,wy = struct.unpack_from('<IIIff',b,0x20)
    assert (version,w,h,wx,wy) == (0,768,768,1536.,1536.)
    blocked = bytearray(w*h)
    for layer in range(32):
        off,compressed,expanded,count = struct.unpack_from('<4I',b,0x34+layer*16)
        if not count: continue
        assert layer < 2 and count == w*h and expanded == count*4
        raw = zlib.decompress(b[off:off+compressed]); assert len(raw) == expanded
        for i,(value,) in enumerate(struct.iter_unpack('<I',raw)):
            if value: blocked[i] = 1
    summed = [[0]*(w+1) for _ in range(h+1)]
    for y in range(h):
        row_sum = 0
        for x in range(w):
            row_sum += blocked[y*w+x]
            summed[y+1][x+1] = summed[y][x+1]+row_sum
    # Explicit reconstruction algorithm: nearest central 33-cell clear square,
    # not a claim this was the official entry region or a native default spawn.
    radius = 16
    candidates = []
    for y in range(radius,h-radius):
        for x in range(radius,w-radius):
            x1,y1,x2,y2 = x-radius,y-radius,x+radius+1,y+radius+1
            if summed[y2][x2]-summed[y1][x2]-summed[y2][x1]+summed[y1][x1] == 0:
                candidates.append(((x-w/2)**2+(y-h/2)**2,x*wx/w,y*wy/h))
    selected = min(candidates)
    assert selected == (554.,778.,722.)
    def can_stand(x,y):
        return 0 <= x < wx and 0 <= y < wy and not blocked[int(y*h/wy)*w+int(x*w/wx)]
    assert all(can_stand(x,y) for x in range(746,811) for y in range(690,755))
    positions = [(758,702),(778,702),(798,702),(758,714),(778,714),(798,714),(778,726),(758,726),(798,726)]
    assert can_stand(778,746) and all(can_stand(x,y) for x,y in positions)
    report = dict(classification='SERVER_RECONSTRUCTION_STATIC_LAYOUT_NOT_OFFICIAL_PLACEMENT',
        original_table_sha256=table_sha,town_member_sha256=town_sha,
        bounds_member=name,bounds_member_sha256=sha,
        static_dimensions=[w,h],world_extent=[wx,wy],clear_square_candidate_count=len(candidates),
        selection_rule='Nearest map-centre wholly clear square of radius16 cells; tie uses x then y.',
        selected_centre=[778,722],clear_rectangle=[746,690,810,754],
        clear_integer_samples=65*65,player_spawn=[778,746],direction=64,
        npcs=[dict(model=i,x=x,y=y) for i,(x,y) in zip(npc_ids,positions)],
        limits=['Map/controller pairing, direction and positions are Server candidate choices, not official trace.',
                'Both static layers are clear; dynamic MEF barriers, model overlap, camera and runtime appearance remain unverified.',
                'No cutscene actor or NPC position was copied into the player spawn.',
                'Normal Town1 entry must follow authorized mainline progression; this layout does not authorize travel or quest completion.',
                'No Client execution, source resource mutation, network capture or gameplay test.'])
    a.output.parent.mkdir(parents=True,exist_ok=True)
    with a.output.open('x',encoding='utf-8',newline='\n') as f:
        json.dump(report,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps(dict(result='PASS_STATIC_CANDIDATE_ONLY',npcs=len(npc_ids),clear_samples=65*65,spawn=[778,746])))


if __name__ == '__main__':
    main()
