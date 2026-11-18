"""Read pinned existing working resources; emit Server content, never modify Client files."""
import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree as ET
from verify import ROOT, PINS, pinned, digest
from build_catalog import PRODUCT_SHA, ITEM_SHA

WORKING_TABLE = 'ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
WORKING_CASH = 'd1971c9482f1b74cdc8ed9d0208cc65181ad0f03766b6dce470489155e41f9ed'
BASE = '1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd'

def project(table, base):
    pinned(table, WORKING_TABLE)
    doc = json.loads(pinned(base, BASE))
    reader = ROOT.parent / '20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader, PINS['reader'])
    spec = importlib.util.spec_from_file_location('working_cash_archive', reader)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    archive = module.Archive(table)
    roots = []
    for member, expected in [('CashProduct', WORKING_CASH), ('Product', PRODUCT_SHA), ('ItemTable2', ITEM_SHA)]:
        raw = archive.read('Table/' + member + '.xml')
        if digest(raw) != expected:
            raise ValueError('Source member differs: ' + member)
        roots.append(ET.fromstring(raw))
    cash, products, items = roots
    products = {int(x.get('PRODUCT')): x for x in products}
    items = {int(x.get('item')): x for x in items}
    key = lambda x: (x['product'], x['quantity'], x['period'], x['option'])
    # Retain original offers for existing storage/paid items. Current UI prices win on matching keys.
    offers = {key(x): x for x in doc['offers']}
    slots = {17: 6, 18: 7, 19: 8, 32: 9, 36: 10, 37: 11}
    for row in cash:
        product = int(row.get('PRODUCT'))
        item = items[int(products[product].get('ITEM'))]
        cls = int(item.get('class'))
        slot = slots.get(cls, 0)
        limits = item.findall('USE_LIMIT')
        if row.find('OPTION_LIST') is not None:
            raise ValueError('Cash option projection requires separate review')
        role = int(limits[0].get('char', '0')) if limits else 0
        if slot and (len(limits) > 1 or any(set(x.attrib) - {'char'} for x in limits) or
                     [int(x.get('pos')) for x in item.findall('EQUIP_POS_LIST/EQUIP_POS')] != [slot]):
            slot, role = 0, 0
        options = [(x.get('status'), x.get('value')) for x in item.findall('OPTION_LIST/OPTION')]
        # Extra stats, special effects and non-costume classes stay deferred.
        supported = slot != 0 and options == [('12', '120'), ('13', '120')]
        for index, price in enumerate(row.findall('PRICE_LIST/PRICE'), 1):
            period = int(price.get('PERIOD', '0'))
            offer = dict(product=product, quantity=int(price.get('QTY')), period=period, option=0,
                         cost=int(price.get('PRICE')), priceIndex=index, item=int(item.get('item')),
                         itemClass=cls, stackLimit=int(item.get('quan')), equipmentSlot=slot, requiredRole=role,
                         available=supported and row.get('NOW_SELLING') == '1' and period == 0)
            offers[key(offer)] = offer
    doc.update(schema='LOCAL_CASH_SHOP_CATALOG_V2_WORKING_COPY_NOT_NATIVE_MEF',
               cashProductSha256=WORKING_CASH,
               offers=sorted(offers.values(), key=lambda x: (x['product'], x['priceIndex'], x['quantity'], x['period'], x['option'])))
    return doc

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--table', required=True, type=Path)
    parser.add_argument('--base', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    raw = (json.dumps(project(args.table, args.base), indent=2) + '\n').encode()
    if args.check:
        if args.output.read_bytes() != raw:
            raise ValueError('Working catalog differs')
    else:
        args.output.write_bytes(raw)
    print(json.dumps({'sha256': digest(raw), 'bytes': len(raw), 'clientModified': False}))
