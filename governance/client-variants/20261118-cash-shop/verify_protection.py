"""Pin cash protection identity, grade, prices and level-up safety requirements."""

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
    spec = importlib.util.spec_from_file_location("cash_protection_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table)
    members = {"Table/Product.xml": PRODUCT_SHA, "Table/ItemTable2.xml": ITEM_SHA,
               "Table/CashProduct.xml": PINS["member"],
               "Table/ItemLevelupInfoSet.xml": "ff2e4ac049a104875f97dd094a84d01417aa6ccb0fdc9ffa084d539d5fced384"}
    roots = {}
    for member, expected in members.items():
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Source member differs: {member}")
        # This exact level-up member has UTF-8 bytes despite its euc-kr declaration.
        roots[member] = ElementTree.fromstring(raw.decode("utf-8-sig") if member.endswith("ItemLevelupInfoSet.xml") else raw)
    products = {int(row.get("PRODUCT")): row for row in roots["Table/Product.xml"]}
    items = {int(row.get("item")): row for row in roots["Table/ItemTable2.xml"]}
    cash = {int(row.get("PRODUCT")): row for row in roots["Table/CashProduct.xml"]}
    info = roots["Table/ItemLevelupInfoSet.xml"]
    safety = {int(row.get("id")): {int(mode.get("type")): [child.attrib for child in mode] for mode in row}
              for row in info.find("SafetyModeRequireList")}
    output = []
    for product, item_id, grade, prices in [
            (5523, 5489, 1, [(1, 11), (11, 112)]), (5524, 5490, 2, [(1, 16), (11, 160)]),
            (5525, 5491, 3, [(1, 21), (11, 208)]), (5526, 5492, 4, [(1, 26), (11, 256)]),
            (5527, 5493, 5, [(1, 30), (11, 304)]), (27484, 7659, None, [(1, 141)])]:
        item = items[item_id]
        actual_grade = item.find("GRADE")
        actual_grade = int(actual_grade.get("grade")) if actual_grade is not None else None
        actual_prices = [(int(row.get("QTY")), int(row.get("PRICE"))) for row in cash[product].findall("PRICE_LIST/PRICE")]
        if (int(products[product].get("ITEM")), item.get("class"), item.get("quan"), actual_grade, actual_prices) != (
                item_id, "33", "100", grade, prices):
            raise ValueError(f"Unexpected source protection row: {product}")
        mode = 3 if grade is None else 2
        set_ids = [key for key, requirements in safety.items() if requirements.get(mode) == [{"id": str(item_id), "qty": "1"}]]
        if set_ids != (list(range(1, 7)) if grade is None else [grade]):
            raise ValueError("Unexpected safety-mode requirement mapping")
        output.append(dict(product=product, item=item_id, itemClass=33, stackLimit=100, grade=grade,
                           safetyMode=mode, safetySetIds=set_ids,
                           aliases=sorted(int(row.get("PRODUCT")) for row in products.values() if row.get("ITEM") == str(item_id)),
                           prices=[dict(quantity=qty, garnet=cost) for qty, cost in prices],
                           description=item.findtext("EXPLAIN"), extra=item.findtext("EXTRA")))
    ranks = [dict(setId=int(info_set.get("id")), **row.attrib)
             for info_set in info.find("LevelupInfoSetList") if info_set.get("id") in ("1", "2")
             for row in info_set if row.get("rank") in ("2", "3")]
    if len(ranks) != 4 or any(row["SafetyID"] != "1" for row in ranks):
        raise ValueError("Unexpected early-equipment safety set")
    return dict(verification="PINNED_CASH_PROTECTION_TABLES", tableSha256=PINS["table"], members=members,
                protections=output, earlyEquipmentRanks=ranks,
                encodingNote="Pinned ItemLevelupInfoSet bytes are UTF-8; XML declaration says euc-kr",
                serverPolicy="Early E-grade only; mode-2 0/1/2 loss uses Server equal weights and safe floor",
                higherGradeEquipmentImplemented=False, clientRuntimeVerified=False)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.write_bytes((json.dumps(inspect(args.table), ensure_ascii=True, indent=2) + "\n").encode("utf-8"))
