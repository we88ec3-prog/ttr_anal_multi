"""Reproduce bounded cash-equipment lookups in the retained modified-client snapshot."""

import argparse
import json
from pathlib import Path

from verify import ROOT, digest, pinned


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--snapshot", required=True, type=Path)
    parser.add_argument("--catalog", required=True, type=Path)
    args = parser.parse_args()
    raw = pinned(args.snapshot, "8950cfb3741644876180421f23cf7e41f2407b2079e33a59fc28e1d15d7d3ab0")
    snapshot = json.loads(raw)
    catalog = json.loads(args.catalog.read_bytes())
    item_ids = {row["item"] for row in catalog["offers"] if row["equipmentSlot"]}
    found = []
    for item in sorted(item_ids):
        entries = [row for row in snapshot["appearances"]
                   if row.get("keyLow") == item and row.get("keyHigh") == 0]
        found.append(dict(item=item, modelKeyPresent=len(entries) == 1,
                          componentType=entries[0]["words"][8] if len(entries) == 1 else None))
    result = dict(schema="CASH_EQUIPMENT_LEGACY_SNAPSHOT_LOOKUP", snapshotSha256=digest(raw),
                  originalRuntime=False, clientRuntimeVerified=False, items=found)
    if json.loads((ROOT / "cash-equipment-models.json").read_bytes()) != result:
        raise ValueError("Cash equipment model projection differs")
    print(json.dumps(dict(items=len(found), found=sum(row["modelKeyPresent"] for row in found),
                          clientRuntimeVerified=False)))


if __name__ == "__main__":
    main()
