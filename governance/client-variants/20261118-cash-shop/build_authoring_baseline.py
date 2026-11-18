"""Project immutable row identities and price mappings for Server-owned catalog proposals; no Client writes."""
import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree as ET
from verify import ROOT, PINS, pinned, digest
from build_working_catalog import WORKING_TABLE, WORKING_CASH

CATALOG = 'f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4'

def project(original, working, catalog):
    pinned(original, PINS['table'])
    pinned(working, WORKING_TABLE)
    document = json.loads(pinned(catalog, CATALOG))
    offers = {(x['product'], x['quantity'], x['period'], x['option']): x for x in document['offers']}
    reader = ROOT.parent / '20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader, PINS['reader'])
    spec = importlib.util.spec_from_file_location('cash_authoring_archive', reader)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    roots = []
    for path, expected in [(original, PINS['member']), (working, WORKING_CASH)]:
        raw = module.Archive(path).read('Table/CashProduct.xml')
        if digest(raw) != expected:
            raise ValueError('CashProduct identity differs')
        roots.append({int(x.get('PRODUCT')): x for x in ET.fromstring(raw)})
    source, current = roots
    templates = []
    for product in sorted({x['product'] for x in document['offers']}):
        row = current.get(product)
        listed = row is not None
        if row is None:
            row = source[product]
        prices = []
        native_prices = row.findall('PRICE_LIST/PRICE')
        keys = [(int(x.get('QTY')), int(x.get('PERIOD', '0')), 0) for x in native_prices]
        for index, price in enumerate(native_prices, 1):
            quantity, period, option = keys[index-1]
            offer = offers.get((product, quantity, period, option))
            cost = int(price.get('PRICE'))
            direct = (keys.count(keys[index-1]) == 1 and offer is not None and
                      offer['cost'] == cost and offer['priceIndex'] == index)
            prices.append(dict(priceIndex=index, quantity=quantity, period=period, option=option,
                               cost=cost, directServerMapping=direct,
                               serverSupported=bool(offer and offer['available'])))
        templates.append(dict(product=product, currentlyListed=listed,
                              rowSource='WORKING' if listed else 'ORIGINAL',
                              rowRepresentationSha256=digest(ET.tostring(row, encoding='utf-8')),
                              prices=prices))
    return dict(schema='LOCAL_CASH_AUTHORING_BASELINE_V1_NOT_NATIVE_MEF', catalogSha256=CATALOG,
                originalTableSha256=PINS['table'], workingTableSha256=WORKING_TABLE,
                originalCashProductSha256=PINS['member'], workingCashProductSha256=WORKING_CASH,
                rowRepresentation='ElementTree UTF-8 serialization; not an original byte span', templates=templates)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('original', 'working', 'catalog', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    raw = (json.dumps(project(args.original, args.working, args.catalog), ensure_ascii=False, indent=2)+'\n').encode()
    if args.check:
        if args.output.read_bytes() != raw:
            raise ValueError('Authoring baseline differs')
    else:
        args.output.write_bytes(raw)
    document = json.loads(raw)
    print(json.dumps(dict(sha256=digest(raw), bytes=len(raw), products=len(document['templates']),
                          unmappedPriceRows=sum(not x['directServerMapping'] for t in document['templates'] for x in t['prices']),
                          clientModified=False)))
