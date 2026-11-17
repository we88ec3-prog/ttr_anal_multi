"""Recheck selected hair native instructions and the saved bounded disassembly."""

import argparse
import json
import re
from pathlib import Path

from verify import ROOT, PINS, digest, pe_window, pinned

ANCHORS = {
    "header_style_read": (0x509AC7, "0fb74603"),
    "header_color_read": (0x509ACB, "8a5605"),
    "role_color_write": (0x509ACE, "889702010000"),
    "role_style_write": (0x509AD4, "66898700010000"),
    "header_minimum": (0x509ADB, "83f906"),
    "dye_current_style": (0x6007D7, "0fb78000010000"),
    "dye_style_set": (0x6007DF, "e8cc45e7ff"),
    "dye_membership": (0x6007E5, "e8265e2200"),
    "plain_use_no_options": (0x600ADE, "6a00"),
    "plain_use_builder": (0x600AE3, "e8082feaff"),
    "action_13_dispatch": (0x47564D, "83e80d"),
    "style_action_value": (0x475655, "0fb7510c"),
    "color_action_value": (0x47565B, "8a490c"),
    "single_color_zero": (0x47567A, "32c0"),
    "preview_apply": (0x47568B, "e8f06a2600"),
    "component_kind_8": (0x6DD100, "83781008"),
    "model_variant_read": (0x7A728F, "8a5510"),
}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--bin", type=Path, required=True)
    p.add_argument("--v2", type=Path, required=True)
    p.add_argument("--output", type=Path, required=True)
    a = p.parse_args()
    sources = [pinned(a.bin, PINS["bin"]), pinned(a.v2, PINS["v2"])]
    listing = pinned(ROOT / "hair-instructions.txt", "73f9b0605938d0aba238a86ec47f3a4a5d57b3b105dfe0241b1172bb0956d502")
    observed = {}
    total_bytes = 0
    ranges = 0
    for line in listing.decode("utf-8").splitlines():
        if line.startswith("RANGE "):
            ranges += 1
        match = re.fullmatch(r"([0-9a-f]{8}) ([0-9a-f]+) (.+)", line)
        if not match:
            continue
        va, raw = int(match[1], 16), bytes.fromhex(match[2])
        if va in observed or any(pe_window(source, va, len(raw)) != raw for source in sources):
            raise ValueError(f"Disassembly source differs at {va:x}")
        observed[va] = raw
        total_bytes += len(raw)
    verified = []
    for name, (va, value) in ANCHORS.items():
        if observed.get(va) != bytes.fromhex(value):
            raise ValueError(f"Bounded instruction differs: {name}")
        verified.append(name)
    if ranges != 9:
        raise ValueError("Disassembly range count differs")
    a.output.write_text(json.dumps(dict(verification="PINNED_HAIR_NATIVE_WINDOWS_NOT_FULL_FUNCTION_ACCEPTANCE",
        sourceSha256=PINS["bin"], clientVariantSha256=PINS["v2"], listingSha256=digest(listing),
        rangeCount=ranges, instructions=len(observed), instructionBytes=total_bytes,
        anchors=verified, runtimeVerified=False), indent=2) + "\n", encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
