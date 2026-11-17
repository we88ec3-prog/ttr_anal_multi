"""Check paid recovery/CP consumables and bounded costume status labels on pinned KR tables."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, digest, pinned
from build_catalog import PRODUCT_SHA, ITEM_SHA


def inspect(table):
    pinned(table, PINS["table"])
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("cash_consumable_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table)
    pins = {"Table/Product.xml": PRODUCT_SHA, "Table/ItemTable2.xml": ITEM_SHA,
            "Table/ItemUsableTable.xml": "30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c",
            "Table/StatusList.xml": "9be878f847ab75401bf8bd81d943773d3e98ec05bbc36364f4cf8f6c00a70161"}
    roots = {}
    for member, expected in pins.items():
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Source member differs: {member}")
        roots[member] = ElementTree.fromstring(raw.decode("cp949") if member.endswith("ItemUsableTable.xml") else raw)
    products = {int(row.attrib["PRODUCT"]): row for row in roots["Table/Product.xml"]}
    items = {int(row.attrib["item"]): row for row in roots["Table/ItemTable2.xml"]}
    usable = {int(row.attrib["item"]): row for row in roots["Table/ItemUsableTable.xml"]}
    points = []
    for product, expected_item, credit in [(27461, 7639, 2000), (27462, 7640, 4000)]:
        item = items[int(products[product].attrib["ITEM"])]
        if int(item.attrib["item"]) != expected_item or item.attrib["class"] != "21":
            raise ValueError("Unexpected point-book identity")
        actions = usable[expected_item].findall("ACTION")
        if len(actions) != 1 or actions[0].attrib != {"action": "11", "priority": "5"}:
            raise ValueError("Unexpected point-book actions")
        if int(actions[0].find("VALUE").attrib["value"]) != credit or item.find("COOLTIME").attrib["group"] != "3":
            raise ValueError("Unexpected point-book value or group")
        extra = item.findtext("EXTRA")
        if extra != "사용 후 1초 간 재사용이 불가능합니다.":
            raise ValueError("Unexpected point-book cooldown text")
        points.append(dict(product=product, item=expected_item, action=11, priority=5, credit=credit,
                           cooldownGroup=3, cooldownMilliseconds=1000))
    recovery = items[int(products[5238].attrib["ITEM"])]
    if (recovery.attrib["item"], recovery.attrib["class"], recovery.attrib["quan"],
        recovery.findtext("EXPLAIN"), recovery.find("COOLTIME").attrib["group"]) != (
            "5206", "5", "255", "HP, SP, MP 100%", "1"):
        raise ValueError("Unexpected cash recovery book")
    if recovery.findtext("EXTRA") != "사용 후 4초 간 재사용이 불가능합니다.":
        raise ValueError("Unexpected recovery cooldown")
    statuses = {int(row.attrib["ID"]): row.attrib["NAME"] for row in roots["Table/StatusList.xml"]}
    if statuses[12] != "SP 증가" or statuses[13] != "MP 증가":
        raise ValueError("Unexpected resource status labels")
    costume = items[int(products[29769].attrib["ITEM"])]
    options = [dict(status=int(row.attrib["status"]), value=int(row.attrib["value"]))
               for row in costume.findall("OPTION_LIST/OPTION")]
    if options != [dict(status=12, value=120), dict(status=13, value=120)]:
        raise ValueError("Unexpected sample costume options")
    return dict(verification="PINNED_CASH_CONSUMABLE_TABLES", tableSha256=PINS["table"], members=pins,
                points=points, recovery=dict(product=5238, item=5206, itemClass=5, stackLimit=255,
                    recoveryPercent=100, cooldownGroup=1, cooldownMilliseconds=4000),
                costumeSample=dict(product=29769, item=13401, options=options,
                    labels={12: statuses[12], 13: statuses[13]}, resourceCapacityImplemented=False),
                clientRuntimeVerified=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    raw = json.dumps(inspect(args.table), ensure_ascii=True, indent=2) + "\n"
    if args.output:
        args.output.write_text(raw, encoding="utf-8")
    else:
        print(raw, end="")


if __name__ == "__main__":
    main()
