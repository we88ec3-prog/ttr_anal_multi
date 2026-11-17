"""Verify every source-projected cash wearable has the bounded flat SP/MP options."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, pinned, digest
from build_catalog import ITEM_SHA
from verify_consumables import inspect


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--table", required=True, type=Path)
    parser.add_argument("--catalog", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    prior = inspect(args.table)
    catalog_sha = "1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd"
    catalog = json.loads(pinned(args.catalog, catalog_sha))
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("cash_capacity_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    archive = reader.Archive(args.table)
    raw = archive.read("Table/ItemTable2.xml")
    if digest(raw) != ITEM_SHA:
        raise ValueError("ItemTable2 source differs")
    items = {int(row.attrib["item"]): row for row in ElementTree.fromstring(raw)}
    selected = sorted({row["item"] for row in catalog["offers"] if row["equipmentSlot"]})
    verified = []
    for item in selected:
        options = [row.attrib for row in items[item].findall("OPTION_LIST/OPTION")]
        if options != [{"status": "12", "value": "120"}, {"status": "13", "value": "120"}]:
            raise ValueError(f"Unexpected wearable options: {item}")
        verified.append([item, 12, 120, 13, 120])
    if len(verified) != 864:
        raise ValueError("Wearable count differs")
    result = dict(verification="ALL_PINNED_CASH_WEARABLE_RESOURCE_OPTIONS", catalogSha256=catalog_sha,
                  tableSha256=PINS["table"], itemTableSha256=ITEM_SHA,
                  statusListSha256=prior["members"]["Table/StatusList.xml"],
                  verifiedItems=len(verified), mappingSha256=digest(json.dumps(verified, separators=(",", ":")).encode()),
                  option12Sp=120, option13Mp=120, otherOptionsObserved=False,
                  policy="SERVER_FLAT_CAPACITY_ADDITION_NOT_OFFICIAL_FORMULA",
                  clientRuntimeVerified=False)
    output = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.write_text(output, encoding="utf-8")
    else:
        print(output, end="")


if __name__ == "__main__":
    main()
