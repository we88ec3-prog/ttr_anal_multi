"""Project display labels for Web management from pinned existing resources; no Client writes."""
import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree as ET
from verify import ROOT, PINS, pinned, digest
from build_catalog import PRODUCT_SHA
from build_working_catalog import WORKING_TABLE, WORKING_CASH

CATALOG = 'f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4'

def project(table, catalog):
    pinned(table, WORKING_TABLE)
    offers = json.loads(pinned(catalog, CATALOG))['offers']
    reader = ROOT.parent / '20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader, PINS['reader'])
    spec = importlib.util.spec_from_file_location('cash_admin_labels_archive', reader)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    archive = module.Archive(table)
    raw = archive.read('Table/Product.xml')
    if digest(raw) != PRODUCT_SHA:
        raise ValueError('Product identity differs')
    products = {int(x.get('PRODUCT')): x.get('NAME', '') for x in ET.fromstring(raw)}
    raw = archive.read('Table/CashProduct.xml')
    if digest(raw) != WORKING_CASH:
        raise ValueError('Working CashProduct identity differs')
    listed = {int(x.get('PRODUCT')): x.get('EXPLAIN', '') for x in ET.fromstring(raw)}
    return dict(schema='LOCAL_CASH_SHOP_ADMIN_LABELS_V1', catalogSha256=CATALOG,
                productSha256=PRODUCT_SHA, cashProductSha256=WORKING_CASH,
                labels=[dict(product=p, name=listed.get(p) or products[p], clientListed=p in listed)
                        for p in sorted({x['product'] for x in offers})])

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--table', type=Path, required=True)
    parser.add_argument('--catalog', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    raw = (json.dumps(project(args.table, args.catalog), ensure_ascii=False, indent=2) + '\n').encode()
    if args.check:
        if args.output.read_bytes() != raw:
            raise ValueError('Admin labels differ')
    else:
        args.output.write_bytes(raw)
    print(json.dumps(dict(sha256=digest(raw), bytes=len(raw))))
