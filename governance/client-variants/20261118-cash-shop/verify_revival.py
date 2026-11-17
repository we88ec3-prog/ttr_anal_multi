"""Verify paid complete revival source rows; no Client or Lua execution."""

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
    spec = importlib.util.spec_from_file_location("cash_revival_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table)
    members = {"Table/Product.xml": PRODUCT_SHA, "Table/ItemTable2.xml": ITEM_SHA,
               "Table/CashProduct.xml": PINS["member"],
               "Table/ItemUsableTable.xml": "30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c"}
    roots = {}
    for member, expected in members.items():
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Source member differs: {member}")
        roots[member] = ElementTree.fromstring(raw.decode("cp949") if member.endswith("ItemUsableTable.xml") else raw)

    def row(member, key):
        found = [entry for entry in roots["Table/" + member] if entry.get(key) == "184"]
        if len(found) != 1:
            raise ValueError(f"Expected one complete revival row: {member}")
        return found[0]

    product = row("Product.xml", "PRODUCT")
    item = row("ItemTable2.xml", "item")
    usable = row("ItemUsableTable.xml", "item")
    cash = row("CashProduct.xml", "PRODUCT")
    if (product.get("ITEM"), item.get("class"), item.get("quan"), item.find("COOLTIME").get("group")) != ("184", "26", "100", "3"):
        raise ValueError("Unexpected complete revival identity or cooldown group")
    if item.findtext("EXPLAIN") != "캐릭터 사망 시 사용" or item.findtext("EXTRA") != (
            "모든 게이지가 100% 회복합니다. 사망에 따른 패널티가 복구됩니다. 사용 후 4초 간 재사용이 불가능합니다."):
        raise ValueError("Unexpected complete revival source description")
    actions = [{"attributes": entry.attrib, "children": [{"tag": child.tag, **child.attrib} for child in entry]}
               for entry in usable]
    expected = [
        {"attributes": {"action": "1", "priority": "5"}, "children": [{"tag": "SKILLCAST", "skill": "437", "level": "1"}]},
        {"attributes": {"action": "2", "priority": "8"}, "children": [{"tag": "REBIRTH", "rate": "100"}]},
        {"attributes": {"action": "3", "priority": "3"}, "children": [{"tag": "VALUE", "value": "-800"}]},
        {"attributes": {"action": "23", "priority": "2"}, "children": []}]
    if actions != expected:
        raise ValueError("Unexpected complete revival action source")
    prices = [entry.attrib for entry in cash.findall("PRICE_LIST/PRICE")]
    if prices != [{"QTY": "10", "PRICE": "16"}, {"QTY": "50", "PRICE": "72"}, {"QTY": "100", "PRICE": "128"}]:
        raise ValueError("Unexpected complete revival prices")
    return dict(verification="PINNED_PAID_COMPLETE_REVIVAL_TABLES", tableSha256=PINS["table"], members=members,
                product=184, item=184, itemClass=26, stackLimit=100, prices=prices,
                deathRequired=True, recoveryPercent=100, cooldownGroup=3, cooldownMilliseconds=4000,
                sourceActions=actions,
                limitations=["Action 3 -800 and action 23 semantics are not established by this table check",
                             "SkillCast 437 visual execution and death-penalty/rank restoration are not verified",
                             "Server candidate restores HP/SP/MP to equipped caps and preserves the encounter"],
                clientRuntimeVerified=False)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.write_bytes((json.dumps(inspect(args.table), ensure_ascii=True, indent=2) + "\n").encode("utf-8"))
