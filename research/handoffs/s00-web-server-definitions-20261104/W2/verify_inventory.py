#!/usr/bin/env python3
"""Read-only W2 data verification. Never executes package scripts or game files.

Requires Python 3 and jsonschema. The optional --report writes only the named
verification report; all source XML, reports and repository history stay read-only.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from copy import deepcopy
import csv
import hashlib
from importlib.metadata import version
import json
from pathlib import Path
import re
import subprocess
import sys
from xml.parsers import expat
import xml.etree.ElementTree as ET

from jsonschema import Draft202012Validator

AI_FIELDS = {'chase', 'perception', 'return', 'skill_selection', 'windup',
             'hit', 'cooldown', 'hurt', 'death'}
TARGETS = (1001, 1009, 1004)
TABLES = ['local-resources/Table/' + x for x in
          ['_ActorList.xml', 'CharSkill.xml', 'SkillActiveTable.xml',
           'Skill/SkillMatrix.xml', 'IndependentSkillEffect.xml']]
GENERAL = 'git-evidence/kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt'


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def blob(data):
    return hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()


def load_json(path):
    return json.loads(path.read_bytes())


def load_csv(path):
    with path.open(encoding='utf-8', newline='') as f:
        return list(csv.DictReader(f))


def xml_records(raw):
    declaration = re.search(br'encoding=[\"\x27]([^\"\x27]+)', raw[:200])
    encoding = declaration.group(1).decode('ascii') if declaration else 'utf-8'
    text = raw.decode(encoding, errors='strict')
    root = ET.fromstring(text)
    records, stack = [], []
    parser = expat.ParserCreate()

    def start(tag, attrs):
        record = {'tag': tag, 'attrs': attrs, 'line': parser.CurrentLineNumber,
                  'ancestors': list(stack)}
        records.append(record)
        stack.append({'tag': tag, 'attrs': attrs})

    def end(tag):
        require(stack[-1]['tag'] == tag, 'XML stack mismatch')
        stack.pop()

    parser.StartElementHandler, parser.EndElementHandler = start, end
    parser.Parse(text, True)
    return root, records, encoding


def walk_refs(value):
    if isinstance(value, dict):
        if 'package_path' in value and 'sha256' in value and 'evidence_basis' in value:
            yield value
        for child in value.values():
            yield from walk_refs(child)
    elif isinstance(value, list):
        for child in value:
            yield from walk_refs(child)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--input', type=Path, required=True, help='Extracted uploaded package root')
    ap.add_argument('--output', type=Path, default=Path(__file__).resolve().parent,
                    help='W2 deliverable directory to verify')
    ap.add_argument('--git-repo', type=Path, help='Optional existing repo for source commit tree verification')
    ap.add_argument('--report', type=Path, help='Optional output JSON report; never put inside --input')
    args = ap.parse_args()
    package, out = args.input.resolve(), args.output.resolve()
    if args.report:
        require(not args.report.resolve().is_relative_to(package), 'Report may not overwrite input package')
    manifest_raw = (package / 'MANIFEST.json').read_bytes()
    manifest = json.loads(manifest_raw)
    records = manifest['files']
    require(len(records) == 130, 'Unexpected source manifest file count')
    expected = {r['path']: r for r in records}
    require(len(expected) == len(records), 'Duplicate input manifest paths')
    raw = {}
    for path, item in expected.items():
        source = (package / path).resolve()
        require(source.is_relative_to(package), f'Unsafe input path: {path}')
        data = source.read_bytes()
        require(len(data) == item['bytes'] and digest(data) == item['sha256'], f'Input mismatch: {path}')
        raw[path] = data
    actual = {str(p.relative_to(package)) for p in package.rglob('*') if p.is_file()}
    require(actual == set(expected) | {'MANIFEST.json'}, 'Unexpected missing or extra input files')

    source_index = load_json(out / 'source-index.json')
    source_map = {r['package_path']: r for r in source_index['sources']}
    require(set(source_map) == set(expected), 'Source index is not the exact input manifest set')
    require(source_index['input_manifest_sha256'] == digest(manifest_raw), 'Manifest digest mismatch')
    for path, item in source_map.items():
        require(item['sha256'] == digest(raw[path]) and item['bytes'] == len(raw[path]), f'Source index bytes: {path}')
        require(item['original_member_sha_match_declared'] == expected[path].get('original_member_sha_match'),
                f'Original-member classification changed: {path}')
        require(item['carrier_sha256_declared'] == expected[path].get('carrier_sha256'), f'Carrier digest: {path}')
        if path.startswith('git-evidence/'):
            require(item['git_blob_sha1'] == blob(raw[path]), f'Git blob mismatch: {path}')
            require(item['source_commit'] == manifest['source_analysis_commit'], f'Git source commit: {path}')
        else:
            require(item['source_commit'] is None and item['git_blob_sha1'] is None, f'Raw resource falsely attributed to Git: {path}')
    git_checks = 0
    if args.git_repo:
        tree_bytes = subprocess.run(['git', '-C', str(args.git_repo.resolve()), 'ls-tree', '-rz',
                                     manifest['source_analysis_commit']], check=True, capture_output=True).stdout
        tree = {}
        for entry in tree_bytes.split(b'\0'):
            if entry:
                meta, path = entry.split(b'\t', 1)
                tree[path.decode()] = meta.split()[2].decode()
        for path, item in source_map.items():
            if path.startswith('git-evidence/'):
                require(tree.get(item['repository_path']) == blob(raw[path]), f'Commit tree mismatch: {path}')
                git_checks += 1
        require(git_checks == 110, 'Expected110 Git evidence copies')

    doc = load_json(out / 'monster-profiles.json')
    schema = load_json(out / 'monster-profile.schema.json')
    Draft202012Validator.check_schema(schema)
    validator = Draft202012Validator(schema)
    validator.validate(doc)
    require(doc['input_manifest_sha256'] == digest(manifest_raw), 'Profiles input manifest SHA')
    require(doc['source_analysis_commit'] == manifest['source_analysis_commit'], 'Profiles source commit')
    profiles = {p['actor_key']['actor_id']: p for p in doc['profiles']}
    require(len(doc['profiles']) == 3 and set(profiles) == set(TARGETS), 'Missing or duplicated target actor')

    parsed = {p: xml_records(raw[p]) for p in TABLES}
    actors = {}
    for rec in parsed[TABLES[0]][1]:
        if rec['tag'] == 'ACTOR':
            key = (int(rec['ancestors'][-1]['attrs']['ID']), int(rec['attrs']['ID']), int(rec['attrs']['PRE']))
            require(key not in actors, f'Duplicate category/ActorID/PRE: {key}')
            actors[key] = rec
    require(len(actors) == 5361, 'Actor table row count')
    require((0, 1, 1) in actors and (3, 1, 1) in actors, 'Naked ActorID/PRE namespace counterexample disappeared')
    variants = 0
    for aid, profile in profiles.items():
        expected_keys = {k for k in actors if k[:2] == (1, aid)}
        emitted_keys = {(v['key']['category'], v['key']['actor_id'], v['key']['pre']) for v in profile['variants']}
        require(expected_keys == emitted_keys and len(emitted_keys) == len(profile['variants']), f'Variant coverage: {aid}')
        for v in profile['variants']:
            key = (v['key']['category'], v['key']['actor_id'], v['key']['pre'])
            row = actors[key]
            require(v['raw_attributes'] == row['attrs'], f'Changed or defaulted raw actor field: {key}')
            require(v['source']['line'] == row['line'], f'Actor row line: {key}')
            require(v['source']['selector'] == f"/ACTORLIST/OBJCATEGORY[@ID='1']/ACTOR[@ID='{aid}'][@PRE='{key[2]}']", f'Actor selector: {key}')
            require(profile['file_stem'] == row['attrs']['FILE'], f'FILE stem: {key}')
            require(v['absent_attributes'] == ([] if 'SCALE' in row['attrs'] else ['SCALE']), f'Absent SCALE: {key}')
            variants += 1
        require(set(profile['ai_fields']) == AI_FIELDS, f'AI field coverage: {aid}')
        for field in profile['ai_fields'].values():
            require(field['source_status'] == '無來源' and field['value'] is None and field['unit'] is None,
                    f'Unsupported AI value on actor {aid}')
        require(not profile['runtime_ready'] and all(profile[k] is None for k in
                ['body_carrier', 'body_member', 'body_extension', 'body_member_sha256']), f'Unproven body path/runtime: {aid}')
    require(variants == 12, 'Expected12 target variants')
    require(actors[1, 1001, 7]['attrs']['NAMECOLOR'] == '#FFOO2C', 'Raw letter-O NAMECOLOR silently repaired')

    char_ids = {int(x.get('ID')) for x in parsed[TABLES[1]][0]}
    skill_nos = {int(x.get('no')) for x in parsed[TABLES[2]][0]}
    effects = {int(x.get('Index')): x.get('File') for x in parsed[TABLES[4]][0]}
    require(char_ids == set(range(1, 10)), 'CharSkill domain changed')
    require(not char_ids.intersection(TARGETS), 'A target CharSkill row now exists; re-analyze')
    require(not skill_nos.intersection({76, 307, 371, *TARGETS}), 'New SkillActive numeric hit; re-analyze domain')
    require(not set(effects).intersection({76, 307, 371, *TARGETS}), 'New independent effect numeric hit; re-analyze domain')
    require(len(skill_nos) == 469 and len(effects) == 92 and sum(bool(x) for x in effects.values()) == 55,
            'Skill/effect inventory counts')
    matrix_imports = [x.get('File') for x in parsed[TABLES[3]][0]]
    require({x['member'] for x in doc['matrix_imports']} == set(matrix_imports), 'Matrix import literals differ')
    for member in matrix_imports:
        require('local-resources/' + member not in expected, f'Imported raw matrix unexpectedly supplied: {member}')

    report_lines = raw[GENERAL].decode('utf-8-sig').splitlines()
    require('1001：tier 0 的 key 1／2／3 → 76／307／371' in report_lines[41], 'Reported skill source text changed')
    require([(c['matrix_tier'], c['matrix_key'], c['skill_word']) for c in profiles[1001]['reported_matrix_cells']]
            == [(0, 1, 76), (0, 2, 307), (0, 3, 371)], 'Historical matrix cells differ')
    require(all(not profiles[aid]['reported_matrix_cells'] for aid in [1009, 1004]), 'Invented target skill cells')
    require([(a['slot'], a['name']) for a in profiles[1001]['reported_animation_refs']] == [(4, 'HokyPoky_MOVE01')], '1001 animation hints')
    require([(a['slot'], a['name']) for a in profiles[1004]['reported_animation_refs']]
            == [(4, 'Nepenths_WAIT01'), (6, 'Nepenths_WAIT01')], '1004 animation hints')
    require(not profiles[1009]['reported_animation_refs'], 'Invented1009 animation hints')

    inv = load_json(out / 'table-inventory.json')
    for item in inv['table_inventory']:
        root = parsed[item['source_path']][0]
        counts, attributes = Counter(), defaultdict(set)
        for node in root.iter():
            counts[node.tag] += 1
            attributes[node.tag].update(node.attrib)
        require(dict(counts) == item['element_counts'], f'Table inventory counts: {item["source_path"]}')
        require({k: sorted(v) for k, v in attributes.items()} == item['attributes_by_tag'], 'Table attribute inventory')
    cluster_rows = {}
    for path in expected:
        if path.startswith('local-resources/Field/Cluster/'):
            _, rows, _ = xml_records(raw[path])
            for row in rows:
                if row['tag'] == 'OBJECT' and int(row['attrs']['ID']) in TARGETS:
                    cluster_rows[path, row['line']] = row['attrs']
    require(len(cluster_rows) == 55 and len(inv['cluster_target_mentions']) == 55, 'Cluster occurrence count')
    emitted_cluster_rows = {(r['source_path'], r['line']): r['raw_attributes'] for r in inv['cluster_target_mentions']}
    require(cluster_rows == emitted_cluster_rows, 'Cluster source occurrence coverage/raw fields')
    for aid, profile in profiles.items():
        seen = {int(attrs['PRE']) for attrs in cluster_rows.values() if int(attrs['ID']) == aid}
        require(sorted(seen) == profile['cluster_pre_literals'], f'Cluster PRE coverage: {aid}')

    links = load_csv(out / 'monster-skill-links.csv')
    link_index = {r['link_id']: r for r in links}
    require(len(links) == len(link_index) == 38, 'Link count/uniqueness')
    required = load_csv(out / 'required-members.csv')
    req_index = {r['request_id']: r for r in required}
    require(len(required) == len(req_index) == 7, 'Required-member row count/uniqueness')
    for row in links:
        src = source_map[row['source_path']]
        require(row['source_sha256'] == src['sha256'], f'Link source digest: {row["link_id"]}')
        require(row['source_commit'] == (src['source_commit'] or ''), f'Link source commit: {row["link_id"]}')
        require(row['source_blob_sha1'] == (src['git_blob_sha1'] or ''), f'Link blob: {row["link_id"]}')
        require(row['carrier_sha256_declared'] == (src['carrier_sha256_declared'] or ''), 'Link carrier declaration')
        require(set(filter(None, row['required_member_ids'].split(';'))) <= set(req_index), 'Dangling required member ID')
        for key in ['from_key', 'to_key']:
            json.loads(row[key])
    for profile in profiles.values():
        aid = profile['actor_key']['actor_id']
        for lid in profile['link_ids']:
            require(lid in link_index and link_index[lid]['actor_id'] == str(aid), 'Wrong-actor/dangling profile link')
        require(set(profile['required_member_ids']) <= set(req_index), 'Dangling profile member request')
        for field in profile['ai_fields'].values():
            require(set(field['related_report_link_ids']) <= set(profile['link_ids']), 'Wrong field report hint')
    require(req_index['W2-M01']['member'] == 'Table/Skill/Matrix/MonsterMatrices.xml', 'Exact monster member')
    require(req_index['W2-M06']['bundle_phase'] == 'OPTIONAL_COMPARISON', 'Character matrix incorrectly required')
    for rid, aid in [('W2-M02', 1001), ('W2-M03', 1009), ('W2-M04', 1004)]:
        r = req_index[rid]
        require(r['stem'] == profiles[aid]['file_stem'] and not r['member'] and not r['carrier']
                and not r['carrier_sha256'] and not r['member_sha256'], f'Invented raw body path/carrier: {rid}')
    require(not req_index['W2-M05']['member'] and not req_index['W2-M07']['member'], 'Invented Monster/skill provider filename')
    require(req_index['W2-M07']['bundle_phase'] == 'AFTER_MATRIX_AND_BODY', 'Conditional provider promoted to immediate file')
    for r in required:
        require(r['server_policy_design_blocked'] == 'false', 'Official Server unknown turned into design blocker')
        for src in json.loads(r['source_refs']):
            require(src['sha256'] == source_map[src['package_path']]['sha256'], 'Required member source SHA')
    ref_count = 0
    for src in walk_refs(doc):
        item = source_map[src['package_path']]
        require(src['sha256'] == item['sha256'] and src['source_commit'] == item['source_commit']
                and src['git_blob_sha1'] == item['git_blob_sha1'], 'Profile source ref provenance mismatch')
        if src['line'] is not None:
            require(src['line'] > 0, 'Source line must be positive')
        ref_count += 1
    policy_ids = {p['id'] for p in doc['server_policy_candidates']}
    require(len(policy_ids) == 9 and {p['field'] for p in doc['server_policy_candidates']} == AI_FIELDS,
            'Candidate policy coverage')
    require(all(f['server_requirement'] in policy_ids for p in profiles.values() for f in p['ai_fields'].values()),
            'Dangling Server requirement')

    negative_checks = []
    mutants = []
    mutant = deepcopy(doc)
    mutant['profiles'][0]['ai_fields']['cooldown']['value'] = 0
    mutants.append(('reject_unknown_cooldown_as_zero', mutant))
    mutant = deepcopy(doc)
    del mutant['profiles'][1]['ai_fields']['death']
    mutants.append(('reject_missing_ai_field', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['body_extension'] = '.abf'
    mutants.append(('reject_unproven_body_extension', mutant))
    mutant = deepcopy(doc)
    mutant['runtime_ready'] = True
    mutants.append(('reject_runtime_promotion', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['reported_matrix_cells'][0]['matrix_variant'] = 1
    mutants.append(('reject_invented_PRE_matrix_variant', mutant))
    for label, mutant in mutants:
        require(not validator.is_valid(mutant), f'Schema failed mutation check: {label}')
        negative_checks.append(label)

    artifacts = {p.name: digest(p.read_bytes()) for p in sorted(out.iterdir())
                 if p.is_file() and p.name != 'validation-report.json'}
    result = dict(format='W2_DATA_VALIDATION_V1', result='PASS',
        scope='input integrity, JSON Schema, source-backed rows, typed link states and unknown preservation only',
        input_manifest_sha256=digest(manifest_raw), manifest_files_verified=len(raw),
        git_commit_tree_blobs_verified_this_run=git_checks,
        git_check_scope='not_requested' if not args.git_repo else manifest['source_analysis_commit'],
        original_carrier_reread=False, bin_native_reverification=False,
        old_evidence_scripts_executed=False, game_or_server_executed=False,
        profile_count=3, actor_variant_count=variants, ai_field_count=27,
        unresolved_ai_numeric_values=27, link_count=len(links),
        link_status_counts=dict(Counter(r['status'] for r in links)),
        required_member_rows=len(required), required_rows_are_not_a_physical_file_count=True,
        cluster_target_occurrences=len(cluster_rows), profile_source_refs_checked=ref_count,
        schema_validator='jsonschema '+version('jsonschema')+' / Draft 2020-12',
        negative_schema_cases=negative_checks,
        formal_acceptance='No T01 FULL-PASS/RR acceptance/S00 SPEC or ADR promotion',
        runtime_validation='NOT_PERFORMED', artifact_sha256=artifacts)
    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(json.dumps(result, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in result.items() if k != 'artifact_sha256'}, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, subprocess.CalledProcessError) as exc:
        print(f'W2 validation failed: {exc}', file=sys.stderr)
        raise SystemExit(1)
