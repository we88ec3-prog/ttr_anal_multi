"""Verify pinned offline cash-shop source windows and inspect the original table."""

import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
from xml.etree import ElementTree


ROOT = Path(__file__).resolve().parent
PINS = {
    "bin": "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
    "v2": "6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c",
    "table": "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442",
    "member": "77b3f5d521f3c01948210f8c0895c6eb4e5b7d9a4bc6914e11d6608fd4bcd5e3",
    "reader": "b47f343d9ab4fdc667939023c0c2fa577975ef3b07c848249a25bbcd1aea0a9d",
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def pinned(path, expected):
    data = path.read_bytes()
    if digest(data) != expected:
        raise ValueError(f"Source identity differs: {path}")
    return data


def pe_window(data, address, length):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("Missing PE signature")
    optional = pe + 24
    if struct.unpack_from("<H", data, optional)[0] != 0x10B:
        raise ValueError("Expected PE32")
    image_base = struct.unpack_from("<I", data, optional + 28)[0]
    section_count = struct.unpack_from("<H", data, pe + 6)[0]
    sections = optional + struct.unpack_from("<H", data, pe + 20)[0]
    rva = address - image_base
    matches = []
    for index in range(section_count):
        _, section_rva, raw_size, raw_offset = struct.unpack_from(
            "<IIII", data, sections + index * 40 + 8)
        if section_rva <= rva and rva + length <= section_rva + raw_size:
            start = raw_offset + rva - section_rva
            window = data[start:start + length]
            if len(window) != length:
                raise ValueError("Truncated source window")
            matches.append(window)
    if len(matches) != 1:
        raise ValueError(f"Ambiguous or absent source mapping: {address:x}")
    return matches[0]


def inspect_sources(bin_path, v2_path, table_path):
    original = pinned(bin_path, PINS["bin"])
    variant = pinned(v2_path, PINS["v2"])
    pinned(table_path, PINS["table"])
    anchors = json.loads((ROOT / "anchors.json").read_text(encoding="utf-8"))
    if anchors["sourceSha256"] != PINS["bin"]:
        raise ValueError("Anchor source identity differs")
    verified = []
    for anchor in anchors["anchors"]:
        address = int(anchor["va"], 16)
        expected = bytes.fromhex(anchor["bytes"])
        if len(expected) != anchor["length"] or digest(expected) != anchor["sha256"]:
            raise ValueError(f"Anchor record differs: {anchor['id']}")
        for source in (original, variant):
            if pe_window(source, address, len(expected)) != expected:
                raise ValueError(f"Source instruction window differs: {anchor['id']}")
        verified.append(anchor["id"])

    reader = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader, PINS["reader"])
    spec = importlib.util.spec_from_file_location("cash_shop_pinned_archive_reader", reader)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    member = module.Archive(table_path).read("Table/CashProduct.xml")
    if digest(member) != PINS["member"]:
        raise ValueError("CashProduct member identity differs")
    table = ElementTree.fromstring(member)
    if table.tag != "CASH_PRODUCT_LIST":
        raise ValueError("Unexpected cash product root")
    products = [int(row.attrib["PRODUCT"]) for row in table]
    if len(products) != len(set(products)):
        raise ValueError("Repeated cash product identity")
    selected = []
    for row in table:
        if int(row.attrib["PRODUCT"]) in (27461, 27462, 27484):
            selected.append({
                "product": int(row.attrib["PRODUCT"]),
                "nowSelling": row.attrib["NOW_SELLING"],
                "sellingType": row.attrib["SELLING_TYPE"],
                "priceOptions": [
                    {"quantity": int(price.attrib["QTY"]), "price": int(price.attrib["PRICE"])}
                    for price in row.findall("PRICE_LIST/PRICE")
                ],
            })
    return {
        "verification": "PINNED_SOURCE_WINDOWS_AND_TABLE_ONLY",
        "sourceSha256": PINS["bin"],
        "clientVariantSha256": PINS["v2"],
        "verifiedAnchors": verified,
        "cashProductCount": len(products),
        "cashProductSha256": digest(member),
        "selectedOriginalRows": selected,
        "runtimeVerified": False,
        "serverCheckoutImplemented": False,
        "unknowns": [
            "cash_shop_entry_and_initialization",
            "server_payment_currency_and_balance_publication",
            "cash_inventory_record_identity_and_update",
            "claim_result_followed_by_regular_bag_publication",
            "specified_v2_normal_purchase_and_claim",
        ],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin", required=True, type=Path)
    parser.add_argument("--v2", required=True, type=Path)
    parser.add_argument("--table", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = inspect_sources(args.bin, args.v2, args.table)
    serialized = json.dumps(result, ensure_ascii=True, indent=2) + "\n"
    if args.output:
        args.output.write_text(serialized, encoding="utf-8")
    else:
        print(serialized, end="")


if __name__ == "__main__":
    main()
