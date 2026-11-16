"""Bounded read-only resource/CAttackedState audit. No target execution."""
from pathlib import Path
import argparse, hashlib, json, re, struct, sys, xml.etree.ElementTree as E

p = argparse.ArgumentParser()
p.add_argument('workspace', type=Path)
p.add_argument('output', type=Path)
a = p.parse_args(); R = a.workspace
sys.path[:0] = [str(R/'anal/python_deps'), str(R/'anal')]
from stp_resources import Archive
from build_native_index import PE
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

sha = lambda b: hashlib.sha256(b).hexdigest()
index_path = R/'runtime-observations/2026-11-05-all-skills/all-role-motion-joins.json'
index_bytes = index_path.read_bytes(); index = json.loads(index_bytes)
cache = {}
def member(root, carrier, name):
    key = (str(root), carrier)
    if key not in cache: cache[key] = Archive(root/carrier)
    return cache[key].read(name)
def xml(data):
    text = data.decode('euc-kr')
    return E.fromstring('<ROOT>'+re.sub(r'<\?xml.*?\?>', '', text)+'</ROOT>')

roles = []
for role in index['roles']:
    m = next(n for n in role['motion_metadata'] if n['motion_id'] == 9)
    abf = member(R.parent/'origin', 'Character/Cha/Base.stp', role['abf_member'])
    assert abf == member(R, 'Character/Cha/Base.stp', role['abf_member'])
    entries = [n for n in xml(abf).iter() if n.get('ID') == '9' and n.get('File') == m['abf_file']]
    assert len(entries) == 1 and entries[0].get('Repeat') == 'false'
    data = member(R.parent/'origin', m['asd_carrier'], m['asd_member'])
    assert data == member(R, m['asd_carrier'], m['asd_member'])
    assert sha(data) == m['asd_sha256']
    header = xml(data).find('.//AnimationHeader'); assert header.get('ID') == '9'
    animation = header.find('AnimationData'); assert animation.get('Repeat') == 'false'
    splits = [dict(n.attrib) for n in header.findall('.//SpliteData')]
    assert splits == m['split_rows'] and len(splits) == 1
    assert {k:float(splits[0][k]) for k in ('FileID','FPS','StartFrame','EndFrame','Delay')} == {
        'FileID':9,'FPS':40,'StartFrame':0,'EndFrame':20,'Delay':0}
    roles.append({'role':role['role'], 'actorFile':role['actor_file'],
        'abfMember':role['abf_member'], 'abfSha256':sha(abf), 'abfEntry':dict(entries[0].attrib),
        'asdCarrier':m['asd_carrier'], 'asdMember':m['asd_member'], 'asdSha256':sha(data),
        'animation':dict(animation.attrib), 'splits':splits, 'originalWorkingMembersEqual':True})
assert [v['role'] for v in roles] == list(range(1,10))

pe = PE(R/'Tartaros.bin')
target = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert sha(pe.data) == target
for address, data in {
    0x4cd945:'b905000000', 0x4cd94f:'c7463809000000',
    0x4cd956:'c7462c01000000', 0x4cd95d:'c7069c79c000', 0x4cb242:'894e08',
    0x4cb870:'d9e88bc18b4804c781180400002c0100008b48048b118b40388b526851d91c2450ffd2c3'
}.items(): assert pe.read(address,len(bytes.fromhex(data))) == bytes.fromhex(data)
vtable = struct.unpack('<5I',pe.read(0xc0799c,20))
assert vtable == (0x4cb8e0,0x4cb870,0x476430,0x5f5d10,0x5f5d10)
md = Cs(CS_ARCH_X86,CS_MODE_32); windows = []
for root,end,start,stop in [(0x4cd6f0,0x4cdaa0,0x4cd943,0x4cd98f),
                           (0x4cb230,0x4cb2b0,0x4cb230,0x4cb28e),
                           (0x4cb870,0x4cb894,0x4cb870,0x4cb894)]:
    chosen = [i for i in md.disasm(pe.read(root,end-root),root) if start <= i.address < stop]
    assert chosen and chosen[0].address == start
    windows.append({'functionEntry':hex(root), 'range':[hex(start),hex(stop)],
        'sha256':sha(pe.read(start,stop-start)),
        'instructions':[f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in chosen]})
out = {'schema':'ALL_ROLE_HURT_SOURCE_BOUNDARY_V1','targetSha256':target,
    'priorMotionIndexSha256':sha(index_bytes),'roles':roles,'nativeWindows':windows,
    'state':5,'motion':9,'vtableAddress':'0xc0799c','vtable':[hex(v) for v in vtable],
    'claims':['Common character constructor passes state5 to base state constructor, sets motion9 and input flag+2C=1.',
              'Attacked Enter requests state motion through actor virtual+68 at speed1.',
              'All nine role ABF9/ASD9 members match original and working archives.'],
    'limits':['Bounded windows and resources only, not whole-function or all-role runtime FULL-PASS.',
              'Actor+418 raw300 units and downstream timing are unknown.',
              '20/40 nominal clip duration is not a native input lock or cancel window.',
              'Server 0.15-second reaction/0.9-second trigger cooldown and preserving active casts are provisional policies.',
              'No native armor, flinch probability, official packet timing, MEF or human acceptance is established.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print('9 roles and bounded state5 registration/entry verified; sha256='+sha(a.output.read_bytes()))
