"""Read pinned KR archives and emit the first three challenge routes."""

import argparse
import hashlib
import json
from pathlib import Path
import runpy
import struct
import xml.etree.ElementTree as ET


PINS = {
    'Table.stp': 'ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c',
    'Field.stp': '18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a',
    'Map/BoundMap.stp': '07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8',
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def numeric_attributes(node):
    return {name: int(value) for name, value in node.attrib.items()}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('client', type=Path, help='Directory of the pinned KR archives')
    parser.add_argument('output', type=Path, help='Destination JSON manifest')
    parser.add_argument('--bounds', type=Path, help='Optional directory for original BND copies')
    args = parser.parse_args()

    reader = Path(__file__).resolve().parents[2] / 'governance/client-variants/20261105-zh-tw-v3/tools/stp_resources.py'
    archive = runpy.run_path(str(reader))['Archive']
    for name, expected in PINS.items():
        if digest((args.client / name).read_bytes()) != expected:
            raise ValueError(f'KR archive identity mismatch: {name}')
    table, field, bounds = (archive(args.client / name) for name in PINS)
    members = {}

    def read_xml(source, name, encoding='utf-8-sig'):
        data = source.read(name)
        members[name] = digest(data)
        return ET.fromstring(data.decode(encoding))

    listings = read_xml(table, 'Table/ChallengeListTable.xml')
    raids = read_xml(table, 'Table/RaidInfoTable.xml')
    cases = read_xml(table, 'Table/_CaseList.xml')
    maps = {entry.get('ID'): entry for entry in read_xml(table, 'Table/_MapList.xml')}
    bound_files = {Path(name).stem.lower(): name for name in bounds.files if name.lower().endswith('.bnd')}
    content = []

    for raid_id in ('1', '2', '3'):
        listing = listings.find(f"./CHALLENGE_LIST/CHALLENGE[@ID='{raid_id}']/INTO")
        raid = raids.find(f"./RAID[@ID='{raid_id}']")
        stage = raid.find('STAGELIST').get('FIRSTSTAGE')
        stage_row = raid.find(f"./STAGELIST/STAGE[@STAGEID='{stage}']")
        case, = (entry for entry in cases if entry.get('STAGE') == stage)
        chart_name = 'Field/MapFlow/' + case.get('MAPFLOW')
        cluster_name = 'Field/Cluster/' + case.get('CLUSTER')
        chart = read_xml(field, chart_name, 'cp949')
        clusters = read_xml(field, cluster_name, 'cp949')
        nodes = {node.get('id'): node for node in chart.find('NodeList')}
        route = []
        links = chart.find('NodeLink')
        while len(links):
            link, = list(links)
            node = nodes[link.get('id')]
            map_ref, = node.findall('Map')
            if map_ref.get('percent') != '100':
                raise ValueError(f'Expected a fixed map at raid {raid_id}, node {link.get("id")}')
            map_row = maps[map_ref.get('id')]
            bound_name = bound_files[map_row.get('BOUND').lower()]
            data = bounds.read(bound_name)
            route.append({
                'node': int(link.get('id')), 'nodeType': int(node.get('type')),
                'map': int(map_ref.get('id')), 'mapResource': map_row.get('MAP'),
                'triggerReference': map_row.get('TRIGGER'), 'boundsFile': Path(bound_name).name,
                'boundsSha256': digest(data), 'boundsVersion': struct.unpack_from('<I', data, 0x20)[0],
            })
            if args.bounds:
                args.bounds.mkdir(parents=True, exist_ok=True)
                destination = args.bounds / Path(bound_name).name
                if destination.exists():
                    if destination.read_bytes() != data:
                        raise ValueError(f'Existing collision copy differs: {destination}')
                else:
                    destination.write_bytes(data)
            links = link

        content.append({
            'raid': int(raid_id), 'nameKr': raid.get('NAME'), 'listType': int(listing.get('type')),
            'visible': listing.get('visible') == 'true', 'stage': int(stage), 'case': int(case.get('ID')),
            'requirements': numeric_attributes(raid.find('REQUIREMENTS')),
            'stageValues': numeric_attributes(stage_row),
            'reward': [numeric_attributes(item) for item in stage_row.findall('./REWARD_LIST/REWARD')],
            'mapFlow': chart_name, 'cluster': cluster_name,
            'clusterGroupCount': len(clusters.findall('./CLUSTERSET/CLUSTER')),
            'route': route,
        })

    result = {'sourceArchivesSha256': PINS, 'sourceMembersSha256': members, 'raids': content}
    args.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))


if __name__ == '__main__':
    main()
