"""Check additional KR cash-balance and storage instruction windows offline."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree

from verify import ROOT, PINS, digest, inspect_sources, pe_window, pinned


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin", required=True, type=Path)
    parser.add_argument("--v2", required=True, type=Path)
    parser.add_argument("--table", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    baseline = inspect_sources(args.bin, args.v2, args.table)
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    reader_spec = importlib.util.spec_from_file_location("cash_balance_pinned_archive_reader", reader_path)
    reader = importlib.util.module_from_spec(reader_spec)
    reader_spec.loader.exec_module(reader)
    table = ElementTree.fromstring(reader.Archive(args.table).read("Table/CashProduct.xml"))
    prices = [price for product in table for price in product.findall("PRICE_LIST/PRICE")]
    sources = [pinned(args.bin, PINS["bin"]), pinned(args.v2, PINS["v2"])]
    document = json.loads((ROOT / "balance-anchors.json").read_text(encoding="utf-8"))
    if document["sourceSha256"] != PINS["bin"]:
        raise ValueError("Balance anchor source identity differs")
    verified = []
    for anchor in document["anchors"]:
        expected = bytes.fromhex(anchor["bytes"])
        if len(expected) != anchor["length"] or digest(expected) != anchor["sha256"]:
            raise ValueError(f"Anchor record differs: {anchor['id']}")
        if any(pe_window(source, int(anchor["va"], 16), len(expected)) != expected for source in sources):
            raise ValueError(f"Source bytes differ: {anchor['id']}")
        verified.append(anchor["id"])
    result = {
        "verification": "CASH_BALANCE_AND_STORAGE_PINNED_WINDOWS",
        "sourceSha256": PINS["bin"],
        "clientVariantSha256": PINS["v2"],
        "baselineAnchors": baseline["verifiedAnchors"],
        "additionalAnchors": verified,
        "cashProductCount": baseline["cashProductCount"],
        "priceOptionCount": len(prices),
        "quantities": sorted({int(price.attrib["QTY"]) for price in prices}),
        "periods": sorted({int(price.attrib.get("PERIOD", "0")) for price in prices}),
        "optionListCount": sum(len(product.findall("OPTION_LIST")) for product in table),
        "sourceRelations": {
            "globalStatusBase": "0xf8d9e0",
            "cashBalanceOffset": "0x686c",
            "cashBalanceAddress": "0xf9424c",
            "balanceCommand": "S2C 00DD",
            "balancePayload": "command:u16 balance:u32",
            "storageSnapshotCommand": "S2C 00E2",
            "storageDeltaCommand": "S2C 00E3",
            "storageRowBytes": 19,
        },
        "runtimeVerified": False,
        "checkoutAndClaimImplemented": False,
    }
    serialized = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.write_text(serialized, encoding="utf-8")
    else:
        print(serialized, end="")


if __name__ == "__main__":
    main()
