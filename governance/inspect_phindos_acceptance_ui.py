"""Read-only original S2C40 acceptance UI dispatch and scene-report cleanup order."""
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
    assert not a.output.exists()
    sha, read = mapped(a.binary); assert sha == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for start,stop,scope in [
        (0x5020b0,0x5020df,'QuestMgr registration excerpt'),
        (0x502270,0x5023e2,'Status0 prefix before AcceptAction dispatch'),
        (0x5b7f80,0x5b7fb5,'Square event dispatcher prefix'),
        (0x5b7fff,0x5b8011,'Resolved F438B target'),
        (0x5b6d20,0x5b6e55,'Complete F438B handler'),
        (0x636594,0x6365b0,'Dialogue mode field initialization excerpt'),
        (0x636611,0x636630,'Dialogue mode dispatch'),
        (0x636687,0x6366ba,'Mode2 dialogue population excerpt'),
        (0x561f9a,0x5620aa,'Ordinary scene report before final cleanup tail'),
    ]:
        raw = read(start,stop-start); ins = list(md.disasm(raw,start))
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
        '0x5020b0':'mov eax, 0xfab2a8',
        '0x5020c0':'mov dword ptr [eax - 4], edx',
        '0x5020cf':'mov dword ptr [0xfab4a4], 0x502270',
        '0x5022a1':'mov eax, dword ptr [ebx + 4]',
        '0x5022ac':'cmp eax, edi',
        '0x5022ae':'jne 0x5026ca',
        '0x5022fe':'mov dword ptr [eax + 0x10], 0xf4281',
        '0x502313':'call 0x58aa50',
        '0x502355':'movzx ecx, word ptr [ebx + 2]',
        '0x502362':'mov dword ptr [eax + 0x10], 0xf438b',
        '0x50236f':'mov dword ptr [eax + 0x14], ecx',
        '0x502377':'call 0x58aa50',
        '0x5b7f93':'mov eax, dword ptr [esi + 0x10]',
        '0x5b7f96':'add eax, 0xfff0bc9c',
        '0x5b7fa6':'movzx eax, byte ptr [eax + 0x5b8460]',
        '0x5b7fae':'jmp dword ptr [eax*4 + 0x5b8394]',
        '0x5b8003':'call 0x5b6d20',
        '0x5b6dae':'mov eax, dword ptr [ebx + 0x14]',
        '0x5b6e0f':'mov edx, dword ptr [ebx + 0x14]',
        '0x5b6e12':'mov eax, dword ptr [0xfab1bc]',
        '0x5b6e17':'mov ecx, dword ptr [esi + 0x28]',
        '0x5b6e1b':'mov edx, dword ptr [edi + 0x224]',
        '0x5b6e21':'push 2',
        '0x5b6e24':'call 0x636520',
        '0x5b6e30':'call 0x74a010',
        '0x5b6e3d':'call 0x596e00',
        '0x636594':'mov edx, dword ptr [ebp + 0xc]',
        '0x63659f':'mov dword ptr [edi + 0x90], edx',
        '0x636611':'mov eax, dword ptr [edi + 0x90]',
        '0x636629':'jmp dword ptr [eax*4 + 0x636774]',
        '0x63669b':'mov eax, dword ptr [ebp + 0x10]',
        '0x63669e':'call 0x500f90',
        '0x6366ab':'je 0x6366ed',
        '0x6366ad':'mov ecx, dword ptr [eax + 0x34]',
        '0x6366b3':'call 0x635f10',
        '0x561fb0':'call 0x4a39a0',
        '0x561fb5':'jmp 0x561ff1',
        '0x562022':'push 0xc106ec',
        '0x56202d':'call 0x4ad0a0',
        '0x56207b':'call 0x589a20',
        '0x562091':'mov dword ptr [edi + 0x38], esi',
        '0x562094':'mov dword ptr [edi + 0x3c], esi',
    }
    for va,op in expected.items(): assert ops[va] == op, (va,ops.get(va),op)
    assert (0xfab4a4-0xfab2a4)//8 == 0x40
    event_index = 0xf438b-0xf4364
    event_slot = read(0x5b8460+event_index,1)[0]
    event_target = struct.unpack('<I',read(0x5b8394+4*event_slot,4))[0]
    assert (event_index,event_slot,event_target) == (39,12,0x5b7fff)
    mode_target = struct.unpack('<I',read(0x636774+2*4,4))[0]
    assert mode_target == 0x636687
    assert read(0xc106ec,22).startswith(b'f_removeAllCoroutines\0')
    result = dict(classification='BOUNDED_NATIVE_UI_SIDE_EFFECT_NOT_SILENT_ACCEPTANCE_ACK',
        target_sha256=sha,tool='Capstone '+capstone.__version__,assertions=len(expected)+4,windows=windows,
        registration=dict(opcode='0x40',receiver='0x502270',message_status='DWORD+4==0',quest_key='WORD+2'),
        f438b_dispatch=dict(event_index=event_index,byte_table_va=hex(0x5b8460+event_index),
            byte_table_value=event_slot,jump_entry_va=hex(0x5b8394+4*event_slot),target=hex(event_target)),
        dialogue_mode2=dict(jump_entry_va=hex(0x636774+2*4),target=hex(mode_target),
            quest_record_field='0x34',population_helper='0x635f10'),
        limits=['Only listed instruction windows, not all functions or helpers semantically reviewed.',
                'Status0 queues dialogue presentation before AcceptAction lookup; presentation remains conditional on resource/helper state.',
                'Human v12 overlap is correlated with this extra UI route, not an instrumented causal runtime trace.',
                'Ordinary3F report producer runs before final coroutine/UI cleanup; receipt is not a universal UI-closed acknowledgment.',
                'Removing extraneous40 from this scene handoff is a minimal Server candidate; no alternative quiet acceptance opcode or fixed delay is inferred.',
                'No Client execution, attachment, mutation, network capture or transmission.'])
    with a.output.open('x',encoding='utf-8',newline='\n') as f:
        json.dump(result,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps(dict(windows=len(windows),assertions=len(expected)+4,result='PASS_BOUNDED_UI_ROUTE_ONLY')))


if __name__ == '__main__':
    main()
