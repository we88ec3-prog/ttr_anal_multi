"""Project pinned cash prices and item limits into a Server-owned catalog, not game resources."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, digest, pinned

PRODUCT_SHA = "8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c"
ITEM_SHA = "7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2"


def project(table_path):
    pinned(table_path, PINS["table"])
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("cash_catalog_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table_path)
    members = [("Table/CashProduct.xml", PINS["member"]),
               ("Table/Product.xml", PRODUCT_SHA), ("Table/ItemTable2.xml", ITEM_SHA)]
    roots = []
    for member, expected in members:
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Source member differs: {member}")
        roots.append(ElementTree.fromstring(raw))
    cash, products, items = roots
    products = {int(row.attrib["PRODUCT"]): row for row in products}
    items = {int(row.attrib["item"]): row for row in items}
    offers = []
    for row in cash:
        product = int(row.attrib["PRODUCT"])
        item = items[int(products[product].attrib["ITEM"])]
        if row.find("OPTION_LIST") is not None:
            raise ValueError("Option-list projection needs a new version")
        for index, price in enumerate(row.findall("PRICE_LIST/PRICE"), 1):
            period = int(price.attrib.get("PERIOD", "0"))
            # Initial local supply policy. Historical promotions and duration items
            # remain in the projection but are not admitted by this release.
            available = (row.attrib.get("NOW_SELLING") == "1" and
                         row.attrib.get("SELLING_STATE") == "1" and
                         row.attrib.get("SELLING_TYPE") == "0" and
                         row.attrib.get("SELL_END_DAY", "").startswith("9999-") and
                         period == 0 and item.attrib["class"] != "30")
            slot_by_class = {17: 6, 18: 7, 19: 8, 32: 9, 36: 10, 37: 11}
            slot = slot_by_class.get(int(item.attrib["class"]), 0)
            limits = item.findall("USE_LIMIT")
            role = 0
            if slot:
                positions = [int(pos.attrib["pos"]) for pos in item.findall("EQUIP_POS_LIST/EQUIP_POS")]
                if positions != [slot] or len(limits) > 1 or any(set(u.attrib) - {"char"} for u in limits):
                    raise ValueError(f"Equipment qualification needs a new contract: {product}")
                role = int(limits[0].attrib.get("char", "0")) if limits else 0
            offers.append(dict(product=product, quantity=int(price.attrib["QTY"]),
                               period=period, option=0, cost=int(price.attrib["PRICE"]),
                               priceIndex=index, item=int(item.attrib["item"]),
                               itemClass=int(item.attrib["class"]),
                               stackLimit=int(item.attrib["quan"]), available=available,
                               equipmentSlot=slot, requiredRole=role))
    offers.sort(key=lambda offer: (offer["product"], offer["priceIndex"]))
    return dict(schema="LOCAL_CASH_SHOP_CATALOG_V1_NOT_NATIVE_MEF",
                cashProductSha256=PINS["member"], productSha256=PRODUCT_SHA,
                itemTableSha256=ITEM_SHA, offers=offers)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    raw = (json.dumps(project(args.table), indent=2) + "\n").encode("utf-8")
    if args.check:
        if args.output.read_bytes() != raw:
            raise ValueError("Catalog projection differs")
    else:
        args.output.write_bytes(raw)
    print(json.dumps(dict(sha256=digest(raw), bytes=len(raw), runtimeVerified=False)))


if __name__ == "__main__":
    main()
