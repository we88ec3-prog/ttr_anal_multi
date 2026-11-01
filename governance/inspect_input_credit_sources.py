"""Read-only bounded KR input allowance registration, add/spend/gate evidence."""
import argparse
import hashlib
import json
import sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists()
    digest, read = mapped(a.binary)
    assert digest == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for va, size in [(0x4931f6, 11), (0x495a44, 7), (0x4b8001, 10),
                     (0x5457a4, 0x5b), (0x545b38, 0x3b)]:
        instructions = list(md.disasm(read(va, size), va))
        count = sum(i.size for i in instructions)
        windows.append({'start': hex(va), 'end_exclusive': hex(va+count),
                        'sha256': hashlib.sha256(read(va, count)).hexdigest(),
                        'bytes': read(va, count).hex(),
                        'instructions': [{'va': hex(i.address), 'op': i.mnemonic+' '+i.op_str}
                                         for i in instructions]})
    ops = {i['va']: i['op'] for w in windows for i in w['instructions']}
    assert ops['0x4931f6'] == 'mov edx, 0x4959f0'
    assert ops['0x4931fb'] == 'mov dword ptr [eax + 0xfa8], edx'
    assert ops['0x495a44'] == 'add dword ptr [0xfba7b0], 5'
    assert ops['0x4b8001'] == 'mov dword ptr [0xfba7b0], 0x1e'
    assert ops['0x5457f7'] == 'cmp edx, esi' and ops['0x5457f9'] == 'jle 0x545b7d'
    assert ops['0x545b4f'] == 'dec dword ptr [0xfba7b0]'
    assert (0xfa8 - 0x200 - 8) // 16 == 0xda
    result = {'target_sha256': digest, 'tool': 'Capstone '+capstone.__version__,
              'classification': 'bounded allowance interface, not official Server replenishment policy/FULL-PASS',
              'frontend_command': '0xDA', 'frontend_slot': 'C+0xFA8', 'counter': '0xFBA7B0',
              'initial': 30, 'added_per_da': 5, 'spent_per_nonempty_input_batch': 1,
              'windows': windows,
              'limits': ['Counters are input send flow control, not currency/stamina/skill cooldown.',
                         'Receive/send registration layout reuses prior bounded frontend/input structural evidence.',
                         'Every-five-batches replenishment is Server policy, not recovered official cadence.',
                         'No Client process access, packet send, raw asset publication or completion claim.']}
    a.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2)+'\n').encode('utf-8'))
    print(json.dumps({'windows': len(windows), 'command': '0xDA', 'add': 5, 'spend': 1}))

if __name__ == '__main__':
    main()
