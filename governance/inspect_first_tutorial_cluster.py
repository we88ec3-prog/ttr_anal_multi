"""Read-only pinned first tutorial chart/cluster facts; no runtime or wave policy."""
import argparse, hashlib, json, struct, zlib
from pathlib import Path
import xml.etree.ElementTree as ET
from inspect_tutorial_bounds_resource import members

FIELD_SHA='18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a'
PATHS={'Field/Cluster/CLUST_scenario_town000_01.xml':'f2cbdae86822dfa25936087700ae3c44f3f68703d8d0fc6a5a35a8cda387c159',
       'Field/MapFlow/CHART_scenario_town000_01.xml':'c7ac1fe050335455fb7b4ca9707adc8b0553226c53aaab94d3609eec47b54eb6'}
def decode(data):
    if data[:2]!=b'EX': return data
    mode=data[2]; compressed,expanded,offset=struct.unpack_from('<III',data,4)
    assert mode in (0,1) and offset>=16 and offset+compressed<=len(data) and expanded<=1_000_000
    payload=data[offset:offset+compressed]
    if mode:
        key=[0x30,0xe7]
        for i in range(2,1024): key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
        payload=bytes(v^key[i%1024] for i,v in enumerate(payload))
    result=zlib.decompress(payload); assert len(result)==expanded
    return result
def main():
    p=argparse.ArgumentParser(description=__doc__); p.add_argument('--archive',required=True,type=Path);p.add_argument('--output',required=True,type=Path);a=p.parse_args()
    assert a.output.suffix=='.json' and a.output.resolve()!=a.archive.resolve()
    extracted={name:decode(data) for name,data in members(a.archive.read_bytes(),FIELD_SHA,PATHS).items()}
    for name,data in extracted.items(): assert hashlib.sha256(data).hexdigest()==PATHS[name]
    cluster=ET.fromstring(extracted[next(n for n in PATHS if '/Cluster/' in n)].decode('euc-kr'))
    chart=ET.fromstring(extracted[next(n for n in PATHS if '/MapFlow/' in n)].decode('euc-kr'))
    records=[e.attrib for e in cluster.findall("./CLUSTERSET[@ID='0']/CLUSTER[@ID='1']/OBJECT")]
    maps=[e.attrib for e in chart.findall('.//Map')]
    assert records==[{'ID':'1036','PRE':'1','COUNT':'1'}] and maps==[{'id':'190','percent':'100'}]
    report=dict(schema='s00-first-tutorial-cluster-v1',archive_sha256=FIELD_SHA,members=PATHS,cluster_set=0,cluster=1,records=records,maps=maps,
        limitations=['COUNT is per cluster invocation, not proven total scenario waves','No MEF triggers/placement/official battle balance inferred','No Client execution, process access or raw asset publication'])
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes((json.dumps(report,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps({'result':'PASS','cluster':records,'maps':maps}))
if __name__=='__main__':main()
