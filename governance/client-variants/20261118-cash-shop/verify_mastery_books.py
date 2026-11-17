"""Verify the two paid skill-mastery books against immutable KR tables."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, digest, pinned
from build_catalog import PRODUCT_SHA, ITEM_SHA


def inspect(table, catalog):
    pinned(table, PINS["table"])
    catalog_sha = "1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd"
    pinned(catalog, catalog_sha)
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("mastery_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table)
    pins = {"Table/Product.xml": PRODUCT_SHA, "Table/ItemTable2.xml": ITEM_SHA,
            "Table/ItemUsableTable.xml": "30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c"}
    roots = {}
    for member, expected in pins.items():
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Member differs: {member}")
        roots[member] = ElementTree.fromstring(raw.decode("cp949") if member.endswith("ItemUsableTable.xml") else raw)
    products = {int(row.attrib["PRODUCT"]): row for row in roots["Table/Product.xml"]}
    items = {int(row.attrib["item"]): row for row in roots["Table/ItemTable2.xml"]}
    usable = {int(row.attrib["item"]): row for row in roots["Table/ItemUsableTable.xml"]}
    offers = json.loads(catalog.read_text(encoding="utf-8"))["offers"]
    result = []
    for product, item_id, credit, price in [(18209, 16537, 2000, 32), (18210, 16538, 5000, 64)]:
        if int(products[product].attrib["ITEM"]) != item_id:
            raise ValueError("Product mapping differs")
        item = items[item_id]
        if (item.attrib["class"], item.attrib["quan"], item.find("COOLTIME").attrib) != ("21", "255", {"group": "6"}):
            raise ValueError("Class, stack or cooldown differs")
        if item.findtext("EXPLAIN") != f"스킬 숙련도 +{credit}":
            raise ValueError("Skill-mastery label differs")
        actions = usable[item_id].findall("ACTION")
        if len(actions) != 1 or actions[0].attrib != {"action": "5", "priority": "5"}:
            raise ValueError("Action differs")
        if [value.attrib for value in actions[0].findall("VALUE")] != [{"value": str(credit)}]:
            raise ValueError("Credit differs")
        selected = [offer for offer in offers if offer["product"] == product]
        if len(selected) != 1 or not selected[0]["available"] or any(selected[0][key] != value for key, value in
                {"quantity": 1, "period": 0, "option": 0, "item": item_id, "cost": price}.items()):
            raise ValueError("Pinned paid offer differs")
        result.append(dict(product=product, item=item_id, credit=credit, price=price, action=5,
                           priority=5, cooldownGroup=6, stackLimit=255))
    return dict(verification="PINNED_PAID_MASTERY_BOOKS", tableSha256=PINS["table"], members=pins,
                catalogSha256=catalog_sha, books=result, runtimeVerified=False,
                cooldownMillisecondsPolicy="SERVER_EXISTING_GROUP_6_1000MS_NOT_SOURCE_DURATION")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", type=Path, required=True)
    parser.add_argument("--catalog", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.write_text(json.dumps(inspect(args.table, args.catalog), ensure_ascii=True, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
