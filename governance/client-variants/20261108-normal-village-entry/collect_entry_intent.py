"""Bounded offline resource/native audit; never executes the Client."""
from pathlib import Path
import hashlib, json, re, sys, xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[4]
sys.path[:0] = [str(ROOT/'anal/python_deps'), str(ROOT/'anal')]
from build_native_index import PE
from stp_resources import Archive
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

sha = lambda b: hashlib.sha256(b).hexdigest()
TARGET = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe = PE(ROOT/'Tartaros.bin')
assert sha(pe.data) == TARGET
md = Cs(CS_ARCH_X86, CS_MODE_32)
windows = []
for address, length in [(0x68e0d7, 0x43), (0x68fb40, 0x90), (0x4a3620, 0x90),
                        (0x5b7590, 0x50), (0x68c5b0, 0x200)]:
    raw = pe.read(address, length)
    instructions = list(md.disasm(raw, address))
    windows.append({'address': hex(address), 'length': length, 'sha256': sha(raw),
                    'instructions': [{'address': hex(i.address), 'text': i.mnemonic+' '+i.op_str}
                                     for i in instructions]})

resources = []
for carrier, member in [('UI/Component.stp', 'Component/Party_Matching_Wnd.FTC'),
                        ('UI/StringTable.stp', 'StringTable/Korean.FCS')]:
    original = ROOT.parent/'origin'/carrier
    working = ROOT/carrier
    original_bytes = Archive(original).read(member)
    working_bytes = Archive(working).read(member)
    assert original_bytes == working_bytes
    tree = ET.fromstring('<R>'+re.sub(r'<\?xml.*?\?>', '', original_bytes.decode('utf8'))+'</R>')
    if carrier.endswith('Component.stp'):
        labels = [{'eid': n.get('EID'), 'class': n.get('ClassName'),
                   'textLinkCodes': [c.get('Code') for c in n.iter('TextLink') if c.get('Code')]}
                  for n in tree.iter() if n.get('EID') in ('15000', '17000')]
    else:
        labels = [{'code': n.get('Code'), 'text': [c.get('Data') for c in n.iter('Contents')]}
                  for n in tree.iter('CHARSETITEM') if n.get('Code') in ('25', '128')]
    resources.append({'carrier': carrier, 'originalCarrierSha256': sha(original.read_bytes()),
                      'workingCarrierSha256': sha(working.read_bytes()), 'member': member,
                      'memberSha256': sha(original_bytes), 'originalWorkingMemberEqual': True,
                      'boundedLabels': labels})

sources = []
for address in [0x68e070,0x68fed0,0x68f9c0,0x68fb40,0x68c790,0x5b6250,0x4a3620,0x53a050,0x53a0a0,
                0x5b7750,0x5b7590,0x68c5b0]:
    p = ROOT/'anal-multi/kr-bulk-roy'/TARGET/'functions'/f'0x{address:x}.c'
    sources.append({'address': hex(address), 'path': str(p.relative_to(ROOT)), 'sha256': sha(p.read_bytes())})

out = {'schema': 'NORMAL_VILLAGE_ENTRY_INTENT_BOUNDED_V1', 'targetSha256': TARGET,
       'authority': 'BOUNDED_OFFLINE_EVIDENCE_NOT_FULL_FUNCTION_PASS_OR_CLIENT_RUNTIME',
       'resources': resources, 'windows': windows, 'bulkSources': sources,
       'claims': [
           'Matching EID17000 TextLink25 is Enter village; setup stores its control in panel+110.',
           'Matching EID15000 TextLink128 is Create party; setup stores its control in panel+118.',
           '68FED0 dispatches those controls to 68F9C0 and 68FB40 respectively.',
           'When no current party exists, 68F9C0 sends F42E1 bool1; generic create 68FB40 sends F42E1 bool0.',
           '5B7750 case F42E1 calls5B7590;5B7590 validates event type105C4 and passes event+14 to68C5B0 on page+238;68C5B0 stores that bool at dialog+110.',
           '68C790 sends create0053 then public005E/private0060; its dialog+110 and selected-kind branch can publish F4390.',
           '5B6250 consumes the entry intent; existing-party admission can call 4A3620, whose bounded bytes build003D.',
           '008E/008F publish affiliation/UI; they are not themselves an automatic scene transfer.'
       ],
       'openLinks': ['Switch-case association uses frozen decompilation; this is not a full dispatcher raw semantic pass.',
                     'Actual original Client click -> request sequence and rendering remain unverified.',
                     'TCP synthetic requests do not prove that the Client emits them.']}
dest = Path(__file__).with_name('entry-intent-bounded-v1.json')
dest.write_text(json.dumps(out, ensure_ascii=False, indent=2)+'\n', encoding='utf8')
print(json.dumps({'output': str(dest), 'sha256': sha(dest.read_bytes()), 'resourceMembers': len(resources)}))
