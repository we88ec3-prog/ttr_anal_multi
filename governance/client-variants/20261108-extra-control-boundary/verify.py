from pathlib import Path
import argparse,hashlib,json,sys,struct
ap=argparse.ArgumentParser();ap.add_argument('--workspace-root',type=Path,required=True)
r=ap.parse_args().workspace_root.resolve();d=Path(__file__).resolve().parent
sys.path[:0]=[str(r/'anal'),str(r/'anal/python_deps')]
from build_native_index import PE
p=PE(r/'Tartaros.bin');m=json.loads((d/'metadata.json').read_text(encoding='utf-8'))
sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(p.data)==m['targetSha256']
for w in m['windows']:assert sha(p.read(int(w['va'],16),w['length']))==w['sha256'],w['purpose']
for s in m['savedBulkSources']:assert sha((r/s['path']).read_bytes())==s['sha256'],s['path']
for va in [0xc0facc,0xc0fa1c]:assert struct.unpack('<I',p.read(va,4))[0]==0x5451d0
for va in [0xc0fb08,0xc0fa58]:assert struct.unpack('<I',p.read(va,4))[0]==0x546ef0
assert struct.unpack('<f',p.read(0xc556c0,4))[0]==10
assert struct.unpack('<f',p.read(0xc55a3c,4))[0]==70
assert p.read(0x5451f7,5)==bytes.fromhex('e82474fbff')
assert p.read(0x5471a7,3)==bytes.fromhex('c20c00')
print('Verified9windows/4saved sources and selected bindings; not hostile-AI or MEF acceptance.')
