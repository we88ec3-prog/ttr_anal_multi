"""Summarize a live metadata-only log by reading its handle, not directory size."""
import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--log-file', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.log_file.resolve() != a.output.resolve()
    raw = a.log_file.read_bytes()
    events, commands = Counter(), Counter()
    last_input = None
    milestones = []
    complete_lines = raw.splitlines()
    if raw and not raw.endswith(b'\n'):
        complete_lines = complete_lines[:-1]
    for line in complete_lines:
        j = json.loads(line)
        assert j.get('payload_logged') is False
        event = j['event_type']
        events[event] += 1
        command = j.get('application_command')
        if command is not None:
            commands[f'0x{command:04X}'] += 1
            if command == 0x0a:
                last_input = {'at_utc': j['ts_utc'], 'bytes': j['bytes_count']}
        if event in ('PRIMARYTUTORIALFIRSTBATTLEWINPERSISTED', 'PRIMARYTUTORIALSCENE10REPORTED',
                     'PRIMARYTUTORIALSCENE12REPORTED', 'PRIMARYTUTORIALSCENE13REPORTED', 'PRIMARYTUTORIALSCENE14REPORTED'):
            milestones.append({'at_utc': j['ts_utc'], 'event': event})
    result = {'captured_at_utc': datetime.now(timezone.utc).isoformat(),
              'source_prefix_bytes_read': len(raw), 'source_prefix_sha256': hashlib.sha256(raw).hexdigest(),
              'complete_metadata_rows': len(complete_lines), 'event_counts': dict(events),
              'application_counts': dict(commands), 'last_input': last_input, 'milestones': milestones,
              'limitations': ['Snapshot of a growing metadata-only file, not packet bodies or flags.',
                             'Directory listing size may stay stale while writer handle remains open.',
                             'Scene report is receipt, not scene success or quest completion.']}
    a.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2)+'\n').encode('utf-8'))
    print(json.dumps({'rows': len(complete_lines), 'input_batches': commands['0x000A'], 'milestones': len(milestones)}))

if __name__ == '__main__':
    main()
