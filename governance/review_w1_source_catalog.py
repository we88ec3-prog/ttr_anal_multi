"""Read-only W1/package comparison; emits review metadata and a Server IR.

The IR is a source catalogue, not executable MEF, placement, wave or AI rules.
No Client/Server execution, raw resource publication or registry promotion.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import xml.etree.ElementTree as ET

from jsonschema import Draft202012Validator


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def load_xml(raw):
    try:
        return ET.fromstring(raw.decode('utf-8-sig'))
    except UnicodeDecodeError:
        return ET.fromstring(raw.decode('euc-kr'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', required=True, type=Path)
    parser.add_argument('--w1', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--source-commit', required=True)
    args = parser.parse_args()
    root, source, out = args.input.resolve(), args.w1.resolve(), args.output.resolve()
    assert not out.is_relative_to(root) and not out.is_relative_to(source)
    assert len(args.source_commit) == 40
    manifest = json.loads((root / 'MANIFEST.json').read_text(encoding='utf-8'))
    for item in manifest['files']:
        path = (root / item['path']).resolve()
        assert path.is_relative_to(root)
        raw = path.read_bytes()
        assert len(raw) == item['bytes'] and digest(raw) == item['sha256'], item['path']
    raw = (source / 'scenario-definitions.json').read_bytes()
    document = json.loads(raw)
    schema = json.loads((source / 'scenario-definition.schema.json').read_text(encoding='utf-8'))
    Draft202012Validator.check_schema(schema)
    Draft202012Validator(schema).validate(document)
    assert document['status'] == 'DRAFT_BLOCKED' and document['native_mef'] is False
    cases_xml = load_xml((root / 'local-resources/Table/_CaseList.xml').read_bytes())
    maps_xml = load_xml((root / 'local-resources/Table/_MapList.xml').read_bytes())
    maps = {int(row.attrib['ID']): row for row in maps_xml}
    assert {d['case']['value'] for d in document['definitions']} == {101, 103, 107, 108, 109}
    counts = dict(cases=0, nodes=0, groups=0, object_rows=0)
    definitions = []
    for definition in document['definitions']:
        case = definition['case']['value']
        row = next(e for e in cases_xml if int(e.attrib['ID']) == case)
        assert row.attrib == definition['case_attributes_raw']
        field = int(row.attrib['STAGE'])
        assert field == definition['stage_field']['value']
        for ref in definition['member_provenance'].values():
            assert digest((root / 'local-resources' / ref['member']).read_bytes()) == ref['member_sha256']
        graph = load_xml((root / 'local-resources' / definition['mapflow_member']).read_bytes())
        cluster = load_xml((root / 'local-resources' / definition['cluster_member']).read_bytes())
        graph_nodes = graph.findall('./NodeList/Node')
        assert [int(n.attrib['id']) for n in graph_nodes] == definition['map_graph']['node_list_declared_order']
        traversal, edges = [], []

        def walk(node, parent=None):
            identity = int(node.attrib['id'])
            traversal.append(identity)
            if parent is not None:
                edges.append((parent, identity))
            for child in node.findall('Node'):
                walk(child, identity)

        for entry in graph.findall('./NodeLink/Node'):
            walk(entry)
        assert traversal == definition['map_graph']['node_link_traversal_order']
        actual_edges = [(int(e['from']['value'].split('node')[-1]), int(e['to']['value'].split('node')[-1]))
                        for e in definition['map_graph']['edges']]
        assert edges == actual_edges
        node_ir = []
        for original, item in zip(graph_nodes, definition['nodes'], strict=True):
            assert original.attrib == item['attributes_raw']
            assert item['editor_layout_is_world_position'] is False
            choices = [(int(m.attrib['id']), int(m.attrib['percent'])) for m in original.findall('Map')]
            assert choices == [(m['map']['value'], m['percent_raw']) for m in item['map_choices']]
            for choice in item['map_choices']:
                model = maps[choice['map']['value']]
                assert choice['map_resource']['map_model_raw'] == model.attrib.get('MAP')
                assert choice['map_resource']['bound_key_raw'] == model.attrib.get('BOUND')
                assert choice['map_resource']['trigger_filename_raw'] == model.attrib.get('TRIGGER')
            node_ir.append(dict(sourceNode=item['node_id_raw'], choices=[dict(map=m, percent=p) for m, p in choices]))
            counts['nodes'] += 1
        groups = []
        for original_set, group_set in zip(cluster.findall('CLUSTERSET'), definition['cluster_sets'], strict=True):
            assert original_set.attrib == group_set['raw_attributes']
            for original, group in zip(original_set.findall('CLUSTER'), group_set['groups'], strict=True):
                assert int(original.attrib['ID']) == group['group_id_raw']
                assert all(group[key] is None for key in ['position_world', 'activation_condition', 'wave_order'])
                members = []
                for original_member, member in zip(original.findall('OBJECT'), group['member_objects'], strict=True):
                    assert original_member.attrib == member['raw_attributes']
                    values = tuple(int(original_member.attrib[key]) for key in ['ID', 'PRE', 'COUNT'])
                    assert values == (member['actor_resource']['value'], member['pre_raw'], member['count_raw'])
                    members.append(dict(model=values[0], pre=values[1], count=values[2]))
                    counts['object_rows'] += 1
                groups.append(dict(set=group_set['set_id_raw'], group=group['group_id_raw'], members=members))
                counts['groups'] += 1
        definitions.append(dict(case=case, field=field, nodeOrder=traversal, nodes=node_ir, groups=groups))
        counts['cases'] += 1
    assert counts == dict(cases=5, nodes=18, groups=143, object_rows=186)
    with (source / 'source-map.csv').open(encoding='utf-8-sig', newline='') as stream:
        provenance = list(csv.DictReader(stream))
    assert len(provenance) == 627
    for row in provenance:
        if row['package_path']:
            path = (root / row['package_path']).resolve()
            assert path.is_relative_to(root) and digest(path.read_bytes()) == row['member_sha256'], row
    report = dict(schema='S00_W1_SOURCE_REVIEW_V1', result='PASS', source_commit=args.source_commit,
                  w1_sha256=digest(raw), manifest_sha256=digest((root / 'MANIFEST.json').read_bytes()),
                  counts=counts, source_map_rows=627, native_mef=False,
                  limitations=['Source/member/schema/graph/object comparison only; no native binary revalidation, official scheduling or gameplay verdict.'])
    catalog = dict(schema='LOCAL_SCENARIO_SOURCE_CATALOG_V1_NOT_MEF', sourceCommit=args.source_commit,
                   sourceW1Sha256=digest(raw), runtimePolicy='EXPLICIT_GROUP_SELECTION_REQUIRED',
                   nativeMef=False, cases=definitions)
    out.mkdir(parents=True, exist_ok=True)
    for name, value in [('w1-source-review.json', report), ('scenario-source-catalog-v1.json', catalog)]:
        path = out / name
        assert not path.exists(), path
        path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))
    print(json.dumps(report, ensure_ascii=False))


if __name__ == '__main__':
    main()
