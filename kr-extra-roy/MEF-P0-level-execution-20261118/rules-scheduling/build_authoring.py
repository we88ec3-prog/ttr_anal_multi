#!/usr/bin/env python3
"""Build authored analysis inputs, never load them in a Server or Client.

The repeat compiler below accepts one finite single-node template and a fixed
visit count. It is a proposed content-build helper, not a runtime loop engine.
"""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]
BASE = '19005c9f8a8180e6f0deb00faf008a11ef98023f'
AUTHORITY = 'SERVER_RECONSTRUCTION_NOT_NATIVE_MEF'
SCHEMA = 'LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF'


def canonical(value):
    return json.dumps(value, ensure_ascii=False, indent=2) + '\n'


def source(path):
    return subprocess.check_output(['git', 'show', BASE + ':' + path], cwd=REPO)


def citation(path):
    return {'kind': 'AUTHORED_ANALYSIS_CANDIDATE_REUSING_EXISTING_CONTRACT',
            'reference': path, 'sha256': hashlib.sha256(source(path)).hexdigest(),
            'authority': AUTHORITY}


def envelope(definitions):
    return {'schema': SCHEMA, 'nativeMef': False, 'authority': AUTHORITY,
            'definitions': definitions}


def make_definition(name, node, docs):
    return {'id': name, 'entryNode': 1, 'authority': AUTHORITY,
            'sources': [citation(p) for p in docs], 'nodes': [node]}


def base_node(group):
    lab = json.loads(source('design/scenario-content/functional-lab.scenario.json'))
    prior = next(d for d in lab['definitions'] if d['id'] == 'content-lab-wave-clear')['nodes'][0]
    # Copy only existing map, positions, profile and ordinary three-rule spine.
    node = {k: copy.deepcopy(prior[k]) for k in
            ('node', 'map', 'spawn', 'portal', 'encounters', 'aiProfile', 'rules')}
    node['encounterGroup'] = group
    node['portal'].pop('condition', None)
    node['clearExperience'] = 0
    for e in node['encounters']:
        e['defeatExperience'] = 0
    return node


def monster(x=377.5, y=291.5):
    # Same model/PRE as the existing map193 lab; coordinates are checked on BND.
    return {'model': 1001, 'pre': 1, 'x': x, 'y': y, 'defeatExperience': 0}


def candidates():
    docs = ['design/scenario-content/functional-lab.scenario.json',
            'design/scenario-content/REINFORCEMENT-FLAGS.md']
    a = base_node('p0-region-entered')
    a['signals'] = [
        {'flag': 'entered-area', 'event': 'RegionEntered',
         'region': {'x': 377.5, 'y': 295.5, 'radius': 2}},
        {'flag': 'node-ready', 'event': 'NodeDelayElapsed', 'delaySeconds': 2},
        {'flag': 'exit-ready', 'event': 'ClearDelayElapsed', 'delaySeconds': 2}]
    a['timedReinforcements'] = [
        {'id': 'region-ambush', 'delaySeconds': 1,
         'requiredFlags': ['entered-area', 'node-ready'], 'encounters': [monster(y=295.5)]}]
    a['portal']['condition'] = {'requiredFlags': ['entered-area', 'exit-ready']}
    b = base_node('p0-boss-defeated')
    b['requiredBoss'] = {'model': 1001, 'pre': 1}
    b['signals'] = [{'flag': 'boss-defeated', 'event': 'BossDefeated'}]
    b['timedReinforcements'] = [
        {'id': 'after-boss', 'delaySeconds': 0, 'requiredFlags': ['boss-defeated'],
         'encounters': [{**monster(y=295.5), 'model': 1009}]}]
    b['portal']['condition'] = {'requiredFlags': ['boss-defeated']}
    c = base_node('p0-empty-initial-sequential')
    c['encounters'] = []
    c['reinforcements'] = [
        {'id': 'first-visible-wave', 'delaySeconds': 2, 'encounters': [monster()]},
        {'id': 'second-visible-wave', 'delaySeconds': 1,
         'requiredFlags': ['first-defeated'], 'encounters': [monster(y=295.5)]}]
    c['signals'] = [{'flag': 'first-defeated', 'event': 'WaveCleared',
                     'waveId': 'first-visible-wave'}]
    c['portal']['condition'] = {'requiredFlags': ['first-defeated']}
    d = base_node('p0-named-wave-boss')
    d['encounters'] = []
    d['timedReinforcements'] = [
        {'id': 'boss-entry', 'delaySeconds': 5, 'encounters': [monster()]}]
    d['requiredBoss'] = {'model': 1001, 'pre': 1, 'waveId': 'boss-entry'}
    d['signals'] = [{'flag': 'boss-defeated', 'event': 'BossDefeated'},
                    {'flag': 'boss-wave-cleared', 'event': 'WaveCleared', 'waveId': 'boss-entry'}]
    d['portal']['condition'] = {'requiredFlags': ['boss-defeated', 'boss-wave-cleared']}
    return envelope([
        make_definition('p0-region-entered-candidate', a,
                        docs + ['design/scenario-content/NODE-DELAY-SIGNALS.md',
                                'design/scenario-content/CLEAR-DELAY-SIGNALS.md']),
        make_definition('p0-boss-defeated-candidate', b,
                        docs + ['design/scenario-content/region-wave-example.scenario.json']),
        make_definition('p0-empty-initial-candidate', c,
                        docs + ['design/scenario-content/WAVE-CLEAR-SIGNALS.md']),
        make_definition('p0-named-wave-boss-candidate', d, docs)])


def compile_repeat(template, visits):
    """Single-node, all-visit-local-flags subset; rejects implicit cross-visit data."""
    if not isinstance(visits, int) or isinstance(visits, bool) or not 1 <= visits <= 256:
        raise ValueError('fixed visit count must fit current 256-node limit')
    if len(template['nodes']) != 1:
        raise ValueError('this bounded helper supports one-node templates only')
    original = template['nodes'][0]
    if original.get('alternativeExits') or original.get('groundDrop') or original.get('groundDrops'):
        raise ValueError('branch/drop transformation requires its own explicit policy')
    if template.get('completionExperience') or template.get('preserveOwnerAcrossNodes'):
        raise ValueError('reward/owner policy must be selected separately for the adapter')
    local_flags = {s['flag'] for s in original.get('signals', [])}
    if len(local_flags) * visits > 64:
        raise ValueError('expanded flags exceed current per-definition limit')
    nodes = []
    mapping = []
    for i in range(1, visits + 1):
        n = copy.deepcopy(original)
        names = {f: 'visit' + str(i) + '.' + f for f in sorted(local_flags)}
        if any(len(v) > 64 for v in names.values()):
            raise ValueError('expanded flag name exceeds current field limit')
        def transform(value):
            if isinstance(value, dict):
                for k, v in value.items():
                    if k in ('flag', 'opensWithFlag', 'disabledByFlag') and v is not None:
                        if v not in names: raise ValueError('nonlocal flag needs declared scope: ' + v)
                        value[k] = names[v]
                    elif k == 'requiredFlags':
                        if any(f not in names for f in v): raise ValueError('nonlocal prerequisite')
                        value[k] = [names[f] for f in v]
                    else: transform(v)
            elif isinstance(value, list):
                for row in value: transform(row)
        transform(n)
        n['node'] = i
        n['encounterGroup'] = original['encounterGroup'] + '-visit-' + str(i)
        rule = next(r for r in n['rules'] if r['event'] == 'InteractZ')
        rule['action'] = 'NextNode' if i < visits else 'Result'
        if i < visits: rule['targetNode'] = i + 1
        else: rule.pop('targetNode', None)
        # Zero reward values are deliberate analysis policy, not a claim about default grants.
        n['clearExperience'] = 0
        for collection in [n['encounters']] + [w['encounters'] for kind in
                          ('reinforcements', 'timedReinforcements') for w in n.get(kind, [])]:
            for actor in collection: actor['defeatExperience'] = 0
        nodes.append(n)
        mapping.append({'visit': i, 'source_node': original['node'], 'compiled_node': i,
                        'encounter_group': n['encounterGroup'], 'flag_map': names,
                        'wave_scope': 'compiled node; wave ids unchanged within each node',
                        'exit_action': rule['action'], 'target_node': rule.get('targetNode')})
    definition = copy.deepcopy(template)
    definition['id'] = 'p0-fixed-three-visits-candidate' if visits == 3 else 'p0-fixed-visits-candidate'
    definition['entryNode'] = 1
    definition['nodes'] = nodes
    return envelope([definition]), mapping


def build():
    basic = candidates()
    repeat, mapping = compile_repeat(basic['definitions'][0], 3)
    carry = copy.deepcopy(basic['definitions'][3])
    carry['id'] = 'p0-cross-node-wave-guarantees-candidate'
    carry['sources'] = list({s['reference']: copy.deepcopy(s)
                             for d in (basic['definitions'][3], basic['definitions'][0])
                             for s in d['sources']}.values())
    first = carry['nodes'][0]
    first['portal'].pop('condition')
    first['rules'][-1] = {'event': 'InteractZ', 'action': 'NextNode', 'targetNode': 2}
    second = copy.deepcopy(basic['definitions'][0]['nodes'][0])
    second['node'] = 2
    second['encounterGroup'] = 'p0-guaranteed-downstream'
    second['timedReinforcements'][0]['requiredFlags'] += ['boss-defeated', 'boss-wave-cleared']
    carry['nodes'].append(second)
    weighted = {
        'schema': 'MEF_AUTHORED_ENTRY_SELECTOR_PROPOSAL_V1',
        'status': 'ANALYSIS_ONLY_NOT_ACCEPTED_BY_CURRENT_SCENARIO_SCHEMA',
        'selection_point': 'before instance construction; once per new run',
        'authority': AUTHORITY, 'policy_version': 'p0-entry-choice-v1',
        'catalog_file': 'missing-coverage.scenario.json',
        'catalog_sha256': hashlib.sha256(canonical(basic).encode()).hexdigest(),
        'entries': [{'definitionId': 'p0-region-entered-candidate', 'weight': 2},
                    {'definitionId': 'p0-named-wave-boss-candidate', 'weight': 1}],
        'draw_contract': 'trusted adapter supplies one uniform integer in [0,totalWeight)',
        'selection_rule': 'first cumulative upper bound strictly greater than draw',
        'in_instance': 'selected definition is fixed; no reroll on node rebuild',
        'persistence': 'existing unfinished-run restart policy; durable checkpoint is separate',
        'reward_policy': 'inherit explicitly selected adapter; no grant during selection'}
    outputs = {'examples/missing-coverage.scenario.json': basic,
            'examples/bounded-repeat.scenario.json': repeat,
            'examples/cross-node-guarantees.scenario.json': envelope([carry]),
            'examples/weighted-entry.plan.json': weighted,
            'repeat-mapping.json': {'schema': 'MEF_BOUNDED_REPEAT_MAPPING_V1',
                                    'template': basic['definitions'][0]['id'], 'visits': 3,
                                    'mapping': mapping}}
    outputs['examples/manifest.json'] = {
        'schema': 'MEF_P0_AUTHORED_ANALYSIS_INPUTS_V1',
        'authority': AUTHORITY,
        'origin': 'New authored analysis inputs; not recovered official data or deployed runtime receipts',
        'existing_schema': 'design/scenario-content/local-scenario-definition.schema.json',
        'map': 193, 'bnd': 'BoundMap/keep04.bnd',
        'static_evidence': '../analysis-result.json',
        'files': [{'path': p.removeprefix('examples/'),
                   'sha256': hashlib.sha256(canonical(v).encode()).hexdigest(),
                   'kind': 'existing scenario schema candidate' if p.endswith('.scenario.json')
                           else 'new entry adapter design input'}
                  for p, v in outputs.items() if p.startswith('examples/')],
        'required_registration': 'Explicit selected content catalog and adapter; no automatic admission of new definition IDs',
        'server_client_lua_executed': False, 'deployed': False}
    return outputs


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--write', action='store_true')
    args = parser.parse_args()
    for path, data in build().items():
        if args.write:
            (HERE / path).parent.mkdir(parents=True, exist_ok=True)
            (HERE / path).write_text(canonical(data), encoding='utf-8')
    print(canonical({'outputs': list(build()), 'written': args.write,
                     'target_or_server_executed': False}), end='')


if __name__ == '__main__':
    main()
