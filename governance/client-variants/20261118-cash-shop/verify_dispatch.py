"""Verify the bounded cash storage UI-notification path without running the Client."""

import argparse
import json
from pathlib import Path

from verify import PINS, ROOT, digest, pe_window, pinned


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin", required=True, type=Path)
    parser.add_argument("--v2", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    sources = [pinned(args.bin, PINS["bin"]), pinned(args.v2, PINS["v2"])]
    anchors = json.loads((ROOT / "dispatch-anchors.json").read_text(encoding="utf-8"))
    if anchors["sourceSha256"] != PINS["bin"]:
        raise ValueError("Dispatch anchor source differs")
    verified = []
    for anchor in anchors["anchors"]:
        expected = bytes.fromhex(anchor["bytes"])
        if len(expected) != anchor["length"] or digest(expected) != anchor["sha256"]:
            raise ValueError(f"Invalid anchor: {anchor['id']}")
        if any(pe_window(source, int(anchor["va"], 16), len(expected)) != expected for source in sources):
            raise ValueError(f"Source differs: {anchor['id']}")
        verified.append(anchor["id"])
    result = {"verification": "CASH_STORAGE_NOTIFICATION_DISPATCH_WINDOWS",
              "sourceSha256": PINS["bin"], "clientVariantSha256": PINS["v2"],
              "verifiedAnchors": verified, "runtimeVerified": False}
    serialized = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.write_text(serialized, encoding="utf-8")
    else:
        print(serialized, end="")


if __name__ == "__main__":
    main()
