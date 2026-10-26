"""Independent PE byte mapping, not a replacement disassembler."""
import hashlib
import json
from pathlib import Path
import struct
import platform

BASE = Path(__file__).resolve().parent
SOURCE = BASE.parents[2] / 'Tartaros.bin'
raw = SOURCE.read_bytes()
sha = hashlib.sha256(raw).hexdigest()
assert sha == '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe = struct.unpack_from('<I', raw, 0x3c)[0]
count = struct.unpack_from('<H', raw, pe + 6)[0]
optsize = struct.unpack_from('<H', raw, pe + 20)[0]
imagebase = struct.unpack_from('<I', raw, pe + 24 + 28)[0]
sections = []
for i in range(count):
    pos = pe + 24 + optsize + i * 40
    virtual_size, rva, size, offset = struct.unpack_from('<IIII', raw, pos + 8)
    sections.append((rva, size, offset))

def read(va, n):
    relative = va - imagebase
    matches = [(offset + relative - rva) for rva, size, offset in sections
               if rva <= relative and relative + n <= rva + size]
    assert len(matches) == 1
    off = matches[0]
    return off, raw[off:off+n]

# Exact instruction bytes independently bind the historical parser constants.
checks = [(0x807bbe, 'ba00100000'), (0x807bd8, 'ba33260000'),
          (0x807bfc, 'babb0b0000'), (0x807c18, 'ba681a0000'),
          (0x807c22, 'bad7220000'), (0x807d35, '34b6')]
records = []
for va, expected in checks:
    offset, data = read(va, len(bytes.fromhex(expected)))
    records.append({'va': hex(va), 'file_offset': offset, 'expected': expected,
                    'actual': data.hex(), 'ok': data.hex() == expected})
ranges = []
for start, end in [(0x807b40, 0x807e43), (0x807830, 0x807a70), (0x807a70, 0x807b40)]:
    offset, data = read(start, end-start)
    path = BASE / 'evidence' / f'raw-{start:x}-{end:x}.bin'
    if path.exists():
        assert path.read_bytes() == data
    else:
        path.write_bytes(data)
    ranges.append({'start': hex(start), 'end_exclusive': hex(end), 'file_offset': offset,
                   'sha256': hashlib.sha256(data).hexdigest(), 'path': path.name,
                   'limits': 'Byte window only; not a verified continuous function body'})
result = {'status': '待整合', 'source_sha256': sha, 'module': 'Tartaros.bin',
          'tool': 'Python ' + platform.python_version(), 'checks': records,
          'ranges': ranges, 'all_ok': all(r['ok'] for r in records),
          'limits': 'Constants and raw byte identity only; no runtime or semantic completion'}
(BASE/'evidence/byte-checks.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
print(json.dumps({'all_ok': result['all_ok'], 'checks': len(records)}))
