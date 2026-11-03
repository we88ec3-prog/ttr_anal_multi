"""Bound original category3 checkpoint fields to nested NPC-confirm notification."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', required=True, type=Path)
    p.add_argument('--capstone-path', required=True, type=Path)
    p.add_argument('--output', required=True, type=Path)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    sha, read = mapped(a.binary)
    assert sha == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for start, stop, scope in [
        (0x544070,0x54416c,'Function prologue through category3/NPC query branch'),
        (0x5441e7,0x54423e,'Mode and party gates; partial alternative path'),
        (0x5442cc,0x5443c0,'F43D9 I3 construction and modal helper path'),
        (0x5b9340,0x5b9498,'Function prologue and complete6A7 branch; other branch excluded'),
        (0x753b60,0x753b66,'I3 runtime type getter'),
    ]:
        raw = read(start,stop-start)
        ins = list(md.disasm(raw,start))
        assert sum(i.size for i in ins) == len(raw)
        boundaries = {i.address for i in ins}
        for i in ins:
            if i.mnemonic.startswith('j') and i.op_str.startswith('0x'):
                target = int(i.op_str,16)
                if start <= target < stop: assert target in boundaries
        windows.append(dict(start=hex(start),end_exclusive=hex(stop),scope=scope,
            sha256=hashlib.sha256(raw).hexdigest(),bytes=raw.hex(),
            instructions=[dict(va=hex(i.address),op=i.mnemonic+' '+i.op_str) for i in ins]))
    ops = {i['va']:i['op'] for w in windows for i in w['instructions']}
    expected = {
        '0x54409c':'mov esi, ecx',
        '0x54409e':'movzx eax, word ptr [esi + 0xf4]',
        '0x5440a5':'cmp ax, 3',
        '0x544127':'movzx eax, word ptr [esi + 0xf6]',
        '0x54412e':'movsx edi, ax',
        '0x54415c':'push edi',
        '0x544162':'call 0x500a80',
        '0x544167':'cmp eax, 5',
        '0x54416a':'je 0x5441e7',
        '0x5441f2':'cmp eax, 3',
        '0x5441f7':'cmp eax, 7',
        '0x5441fc':'cmp eax, 0x17',
        '0x544201':'cmp eax, 0x18',
        '0x544217':'je 0x5442cc',
        '0x544227':'je 0x5442cc',
        '0x5442e5':'movzx ecx, word ptr [esi + 0xf6]',
        '0x5442ec':'movzx edx, word ptr [esi + 0xf4]',
        '0x5442f3':'movsx edx, dx',
        '0x5442f6':'movsx ecx, cx',
        '0x544309':'mov dword ptr [eax + 0x10], 0xf43d9',
        '0x544310':'mov dword ptr [eax], 0xc47be4',
        '0x544316':'mov dword ptr [eax + 0x14], edi',
        '0x544319':'mov dword ptr [eax + 0x18], edx',
        '0x54431c':'mov dword ptr [eax + 0x1c], ecx',
        '0x544334':'push esi',
        '0x5443a5':'call 0x58b270',
        '0x5b937a':'cmp eax, 0x105bd',
        '0x5b939a':'cmp ecx, 0x6a7',
        '0x5b93a6':'mov esi, dword ptr [eax + 0x18]',
        '0x5b93b6':'cmp eax, 0x105bf',
        '0x5b93ff':'mov ecx, dword ptr [esi + 0x14]',
        '0x5b9407':'call 0x5008b0',
        '0x5b9413':'movzx edi, ax',
        '0x5b943f':'push 1',
        '0x5b9441':'push edi',
        '0x5b9447':'call 0x561760',
        '0x5b9453':'mov eax, 0x1c',
        '0x5b945c':'mov cx, word ptr [esi + 0x18]',
        '0x5b9460':'mov word ptr [ebp - 0x16], cx',
        '0x5b9464':'mov dx, word ptr [esi + 0x1c]',
        '0x5b9468':'mov word ptr [ebp - 0x14], dx',
        '0x5b946c':'jne 0x5b9553',
        '0x5b947d':'push 6',
        '0x5b947f':'lea edx, [ebp - 0x18]',
        '0x5b9485':'call eax',
        '0x753b60':'mov eax, 0x105bf',
    }
    for va, instruction in expected.items():
        assert ops[va] == instruction, (va,ops.get(va),instruction)
    vtable = read(0xc47be4,8)
    assert struct.unpack('<2I',vtable)[1] == 0x753b60
    result = dict(classification='BOUNDED_NATIVE_NPC_INTENT_FIELDS_AND_CONFIRM_CONSUMER_NOT_OFFICIAL_SERVER_SEQUENCE',
        target_sha256=sha,tool='Capstone '+capstone.__version__,assertions=len(expected)+1,windows=windows,
        i3_vtable=dict(va='0xc47be4',bytes=vtable.hex(),runtime_type_getter='0x753b60',runtime_type='0x105bf'),
        checkpoint_source=dict(category_offset='0xf4',npc_key_offset='0xf6',category_branch=3,query_result_branch=5),
        original_i3_fields={'0x10':'event F43D9','0x14':'signed NPC key (field5)',
                            '0x18':'signed checkpoint category (field6)',
                            '0x1c':'signed NPC key (field7)'},
        confirm_consumer=dict(outer_runtime_type='0x105bd',confirm_value='0x6a7',nested_pointer_offset='0x18',
            nested_runtime_type='0x105bf',quest_lookup_npc_offset='0x14',
            local_scene_call='561760(WORD lookup5008B0(nested+14),1)',
            notification='C2S1C followed by WORD(nested+18), WORD(nested+1C), length6'),
        source_shaped_npc10338_example=struct.pack('<3H',0x1c,3,10338).hex(),
        limits=['Windows are bounded instruction views, not full544070/5B9340 semantic review.',
                'I3 construction and nested confirmation consumer are separately byte-verified; full modal wrapper creation/lifetime and actual delivery remain outside this proof.',
                'Category3 does not mean every NPC/query result reaches this confirmation branch.',
                'Source-shaped example is not an official capture or observed Client packet.',
                '561760 is invoked before1C construction/send; successful playback/Server reply and quest completion are not established.',
                'Serverpose margin3, committed prerequisite admission,0040 acceptance and0047 scene2 scheduling are reconstruction policy outside these windows.',
                'No Client execution, attachment, modification, network capture or transmission.'])
    with a.output.open('x',encoding='utf-8',newline='\n') as f:
        json.dump(result,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps(dict(windows=len(windows),assertions=len(expected)+1,result='PASS_BOUNDED_NATIVE_FIELDS_ONLY')))


if __name__ == '__main__':
    main()
