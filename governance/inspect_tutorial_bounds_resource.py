"""Read a pinned local STPD archive; emit metadata only, optionally extract town000
to a NEW caller-selected BND file. Never starts or attaches to a game process.
Static resource interpretation is not original Server policy or runtime proof.
"""
import argparse
import hashlib
import json
import struct
import zlib
from pathlib import Path

ARCHIVE_SHA = '07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8'
MEMBERS = {'BoundMap/town000.bnd': 'ee69d4ae60d468862761675f11f41c185f5810c7d1150e5876c4d9dd756ea776',
           'BoundMap/scenario_town000.bnd': '7c98d3d5c5512cfe20f2946abc27c1c94424474ee6450fa3593693a4c5139bfc'}

def members(raw):
    assert raw[:4] == b'STPD' and hashlib.sha256(raw).hexdigest() == ARCHIVE_SHA
    data = bytes(v ^ 255 for v in raw)
    index = struct.unpack_from('<I', data, 4)[0]
    assert raw[index:index+4] == b'STPI'
    position = index + 8
    files = {}
    def node(parent, depth=0):
        nonlocal position
        assert depth < 64
        length = struct.unpack_from('<H', data, position)[0]; position += 2
        name = data[position:position+length].decode('ascii').rstrip('\0'); position += length
        kind = data[position]; position += 1
        path = '/'.join(filter(None, (parent, name)))
        if kind in (1, 2):
            count = struct.unpack_from('<I', data, position)[0]; position += 12
            for _ in range(count): node(path, depth+1)
        elif kind == 0:
            _, identity = struct.unpack_from('<II', data, position); position += 16
            files[path] = identity
        else: raise ValueError('Unsupported STPD index node')
    node('')
    assert position == len(data)
    table = struct.unpack_from('>I', data, 12)[0]
    count = struct.unpack_from('<I', data, table)[0]
    blocks = {}
    for i in range(count):
        identity, size, first, last = struct.unpack_from('<4I', data, table+4+i*32)
        assert last >= first and size <= (last-first+1)*1024
        start = 16+first*1024
        assert start+size <= len(data)
        blocks[identity] = data[start:start+size]
    return {name: blocks[files[name]] for name in MEMBERS}

def inspect(name, data):
    assert hashlib.sha256(data).hexdigest() == MEMBERS[name]
    assert data[:21] == b'MapTool Reinforce 1.0'
    version, width, height, world_x, world_y = struct.unpack_from('<IIIff', data, 0x20)
    assert version == 0 and (width, height) == (768, 768) and (world_x, world_y) == (768., 768.)
    layers, records = [], []
    cursor = 0x234
    for i in range(32):
        offset, compressed, expanded, count = struct.unpack_from('<4I', data, 0x34+i*16)
        if count == 0: continue
        assert i < 2 and offset == cursor and count == width*height and expanded == count*4
        chunk = data[cursor:cursor+compressed]
        decoder = zlib.decompressobj()
        decoded = decoder.decompress(chunk)
        assert decoder.eof and not decoder.unused_data and len(decoded) == expanded
        layers.append(decoded)
        records.append(dict(layer=i, offset=offset, compressed=compressed, expanded=expanded, cells=count,
                            decoded_sha256=hashlib.sha256(decoded).hexdigest()))
        cursor += compressed
    assert len(layers) == 2 and cursor == len(data)
    samples = []
    for x, y in ((231,144), (275,144), (311,149), (360,170), (383,315), (440,394), (368,272)):
        values = [struct.unpack_from('<I', layer, (y*width+x)*4)[0] for layer in layers]
        samples.append(dict(x=x, y=y, layer_values=values, static_base_clear=all(v == 0 for v in values)))
    return dict(member=name, sha256=MEMBERS[name], bytes=len(data), header_version=version,
                dimensions=[width,height], world_extent=[world_x,world_y], layers=records, samples=samples)

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--extract-bnd', type=Path)
    args = parser.parse_args()
    assert args.output.suffix == '.json' and args.output.resolve() != args.archive.resolve()
    if args.extract_bnd:
        assert args.extract_bnd.suffix == '.bnd' and not args.extract_bnd.exists()
        assert args.extract_bnd.resolve() not in (args.archive.resolve(), args.output.resolve())
    extracted = members(args.archive.read_bytes())
    report = dict(schema='s00-static-tutorial-bounds-v1', archive_sha256=ARCHIVE_SHA,
                  authority='READ_ONLY_RESOURCE_INTERPRETATION', members=[inspect(n,d) for n,d in extracted.items()],
                  limitations=['Only pinned local archive; official BIN/resource pairing unproven',
                               'Static first two layers only, no dynamic MEF barriers/overrides',
                               'No game process, official spawn, world clock, or runtime movement proof'])
    if args.extract_bnd:
        args.extract_bnd.parent.mkdir(parents=True, exist_ok=True)
        with args.extract_bnd.open('xb') as f: f.write(extracted['BoundMap/town000.bnd'])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes((json.dumps(report, ensure_ascii=False, indent=2)+'\n').encode('utf8'))
    print(json.dumps({'members': len(report['members']), 'archive_sha256': ARCHIVE_SHA, 'result': 'PASS'}))

if __name__ == '__main__': main()
