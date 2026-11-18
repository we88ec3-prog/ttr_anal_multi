"""Check Wing source identity and selected original/v2 use and position instructions."""

import argparse
import importlib.util
import json
import re
import struct
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, digest, pinned, pe_window
from build_catalog import PRODUCT_SHA, ITEM_SHA

LISTING_SHA = "13c72add35880fc171f486c3209ec484004fe2e23bfc1da98b27f8cf92aa8113"
ANCHORS = {
    "class_minus_one": (0x600410, "49"),
    "class_compact_dispatch": (0x600424, "0fb681900f6000"),
    "class_jump_dispatch": (0x60042B, "ff2485600f6000"),
    "field_mode_4": (0x600459, "83b84c5f000004"),
    "field_mode_9": (0x600467, "83b84c5f000009"),
    "field_mode_28": (0x600475, "83b84c5f00001c"),
    "use_option_zero": (0x600496, "6a00"),
    "use_builder": (0x60049B, "e85035eaff"),
    "plain_use_command": (0x4A3A0A, "b821000000"),
    "plain_use_length": (0x4A3A34, "ba08000000"),
    "position_handler_pointer": (0x4ADD6F, "ba80fb4a00"),
    "position_16_registration": (0x4ADE71, "8990b4000000"),
    "position_immediate_branch": (0x4AFC6A, "66837d1016"),
    "position_x": (0x4AFC77, "8996e8000000"),
    "position_y": (0x4AFC80, "8986ec000000"),
    "position_apply": (0x4AFD0D, "ffd2"),
}


def inspect(table, original, v2):
    pinned(table, PINS["table"])
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("cash_wing_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(table)
    members = {"Table/Product.xml": PRODUCT_SHA, "Table/ItemTable2.xml": ITEM_SHA,
               "Table/CashProduct.xml": PINS["member"],
               "Table/ItemUsableTable.xml": "30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c"}
    rows = {}
    for member, expected in members.items():
        raw = archive.read(member)
        if digest(raw) != expected:
            raise ValueError(f"Source member differs: {member}")
        tree = ElementTree.fromstring(raw.decode("cp949") if member.endswith("ItemUsableTable.xml") else raw)
        key, value = ("PRODUCT", "5342") if member.endswith(("Product.xml", "CashProduct.xml")) else ("item", "5308")
        found = [entry for entry in tree if entry.get(key) == value]
        if len(found) != 1:
            raise ValueError(f"Expected one Wing row: {member}")
        rows[member] = found[0]
    product, item = rows["Table/Product.xml"], rows["Table/ItemTable2.xml"]
    if (product.get("ITEM"), item.get("class"), item.get("quan"), item.find("COOLTIME").get("group")) != ("5308", "13", "255", "3"):
        raise ValueError("Unexpected Wing item identity")
    if item.findtext("EXPLAIN") != "텔포인트로 순간 이동" or item.findtext("EXTRA") != "텔포인트가 열려 있는 경우만 사용 가능합니다.":
        raise ValueError("Unexpected Wing source description")
    if [entry.attrib for entry in rows["Table/ItemUsableTable.xml"]] != [{"action": "10", "priority": "5"}]:
        raise ValueError("Unexpected Wing action")
    prices = [entry.attrib for entry in rows["Table/CashProduct.xml"].findall("PRICE_LIST/PRICE")]
    if prices != [{"QTY": "100", "PRICE": "16"}, {"QTY": "200", "PRICE": "24"}]:
        raise ValueError("Unexpected Wing prices")
    sources = [pinned(original, PINS["bin"]), pinned(v2, PINS["v2"])]
    listing = pinned(ROOT / "wing-instructions.txt", LISTING_SHA)
    observed = {}
    for line in listing.decode("utf-8").splitlines():
        match = re.fullmatch(r"([0-9a-f]{8}) ([0-9a-f]+) (.+)", line)
        if match:
            va, raw = int(match[1], 16), bytes.fromhex(match[2])
            if va in observed or any(pe_window(source, va, len(raw)) != raw for source in sources):
                raise ValueError(f"Listing bytes differ: {va:x}")
            observed[va] = raw
    for name, (va, expected) in ANCHORS.items():
        if observed.get(va) != bytes.fromhex(expected):
            raise ValueError(f"Instruction anchor differs: {name}")
    for source in sources:
        compact = pe_window(source, 0x600F90 + 12, 1)[0]
        if struct.unpack("<I", pe_window(source, 0x600F60 + 4 * compact, 4))[0] != 0x600454:
            raise ValueError("Class-13 switch target differs")
    return dict(verification="PINNED_WING_TABLES_AND_BOUNDED_NATIVE_WINDOWS_NOT_FULL_PASS",
                tableSha256=PINS["table"], members=members, originalSha256=PINS["bin"], v2Sha256=PINS["v2"],
                listingSha256=LISTING_SHA, listedInstructions=len(observed), instructionBytes=sum(map(len, observed.values())),
                anchors=list(ANCHORS), class13Target="0x600454", product=5342, item=5308,
                prices=prices, stackLimit=255, cooldownGroup=3, sourceAction=10,
                serverPolicy=dict(destination="Current normal hunting or RAID node authored primary exit, only when unlocked",
                                  cooldownMilliseconds=4000, manualZRequired=True),
                officialDestinationSelection="UNKNOWN", officialCooldownMilliseconds="UNKNOWN",
                sourcePointIdentity="UNKNOWN_NOT_ASSUMED_CATEGORY1", nativeMef=False, clientRuntimeVerified=False)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ["table", "bin", "v2", "output"]:
        parser.add_argument("--" + name, type=Path, required=True)
    args = parser.parse_args()
    args.output.write_bytes((json.dumps(inspect(args.table, args.bin, args.v2), ensure_ascii=True, indent=2) + "\n").encode("utf-8"))
