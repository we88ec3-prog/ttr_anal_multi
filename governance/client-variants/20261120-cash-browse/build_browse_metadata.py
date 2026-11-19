"""Project admin-only names, role limits and parts; never write Client/gameplay resources."""
import argparse
import hashlib
import importlib.util
import json
import re
from pathlib import Path
from xml.etree import ElementTree as ET

ROOT=Path(__file__).resolve().parent
CATALOG_SHA='f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4'
LABEL_SHA='a1bcc931d1715a43d946ff208044e320e7abc3373829dec172c6fc454aded8eb'
TABLE_SHA='ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
PRODUCT_SHA='8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c'
ITEM_SHA='7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2'
HANGUL=re.compile('[가-힣]+')
def digest(b):return hashlib.sha256(b).hexdigest()
def pinned(path,sha):
    b=Path(path).read_bytes()
    if digest(b)!=sha:raise ValueError('Source identity differs: '+str(path))
    return b

def project(table,catalog,labels):
    pinned(table,TABLE_SHA)
    offers=json.loads(pinned(catalog,CATALOG_SHA))['offers']
    names=json.loads(pinned(labels,LABEL_SHA))['labels']
    reader=ROOT.parent/'20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader,'b47f343d9ab4fdc667939023c0c2fa577975ef3b07c848249a25bbcd1aea0a9d')
    spec=importlib.util.spec_from_file_location('browse_source_archive',reader)
    module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    archive=module.Archive(table)
    product_raw=archive.read('Table/Product.xml');item_raw=archive.read('Table/ItemTable2.xml')
    if digest(product_raw)!=PRODUCT_SHA or digest(item_raw)!=ITEM_SHA:raise ValueError('Source member identity differs')
    products={int(x.get('PRODUCT')):x for x in ET.fromstring(product_raw)}
    items={int(x.get('item')):x for x in ET.fromstring(item_raw)}
    glossary_raw=(ROOT/'simple-zh-glossary.txt').read_bytes()
    glossary={}
    for line in glossary_raw.decode().splitlines():
        if line.startswith('#'):continue
        for pair in line.split('|'):
            if not pair.strip():continue
            key,value=pair.split('=',1);glossary[key]=value
    unknown=set()
    def word(match):
        value=match[0]
        if value in glossary:return glossary[value]
        for ending,translated in [('의','的'),('와','與'),('과','與'),('처럼','風格'),('씨','')]:
            if value.endswith(ending) and value[:-len(ending)] in glossary:return glossary[value[:-len(ending)]]+translated
        unknown.add(value);return value
    result=[]
    for label in names:
        p=label['product'];item=items[int(products[p].get('ITEM'))];cls=int(item.get('class'))
        roles=sorted({int(x.get('char','0')) for x in item.findall('USE_LIMIT')}) or [0]
        if any(x not in range(10) for x in roles):raise ValueError('Unmapped role')
        positions=sorted({int(x.get('pos')) for x in item.findall('EQUIP_POS_LIST/EQUIP_POS')})
        kind='equipment' if positions else 'service' if cls==30 else 'item'
        parts=[str(x) for x in positions] or (['hair'] if cls in (38,39) else ['none'])
        original=label['name'];translated=HANGUL.sub(word,original)
        translated=re.sub(r'(?<=[\u3400-\u9fff])\s+(?=[\u3400-\u9fff])','',translated)
        result.append(dict(product=p,item=int(products[p].get('ITEM')),originalName=original,displayName=translated,
            translation='SIMPLE_ZH_GLOSSARY_NOT_OFFICIAL' if original!=translated else 'EXISTING_LABEL',
            itemClass=cls,roles=roles,parts=parts,kind=kind))
    if unknown:raise ValueError('Untranslated words: '+json.dumps(sorted(unknown),ensure_ascii=False))
    if {x['product'] for x in result}!={x['product'] for x in offers}:raise ValueError('Browse/catalog product set differs')
    return dict(schema='LOCAL_CASH_ADMIN_BROWSE_V1_NOT_NATIVE_MEF',catalogSha256=CATALOG_SHA,
        labelSha256=LABEL_SHA,tableSha256=TABLE_SHA,productSha256=PRODUCT_SHA,itemTableSha256=ITEM_SHA,
        glossarySha256=digest(glossary_raw),classification='ADMIN_ONLY_NOT_GAMEPLAY_OR_CLIENT_TRANSLATION',products=result)

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for key in ('table','catalog','labels','output'):parser.add_argument('--'+key,required=True,type=Path)
    args=parser.parse_args();doc=project(args.table,args.catalog,args.labels)
    raw=(json.dumps(doc,ensure_ascii=False,indent=2)+'\n').encode()
    args.output.write_bytes(raw)
    print(json.dumps(dict(products=len(doc['products']),translated=sum(x['translation']!='EXISTING_LABEL' for x in doc['products']),sha256=digest(raw))))
