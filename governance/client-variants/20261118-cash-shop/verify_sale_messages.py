"""Check bounded purchase-rejection consumers and message keys without executing Client."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path
from verify import ROOT, PINS, pinned, pe_window, digest


def check(bin_path, v2_path, locales_path):
    original = pinned(bin_path, PINS['bin'])
    variant = pinned(v2_path, PINS['v2'])
    pinned(locales_path, 'b9d0ce6fe7de21dfce53357155d2a54ac9ba3815d45e7fc831972c9c4ba8d68b')
    reader = ROOT.parent / '20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader, PINS['reader'])
    spec = importlib.util.spec_from_file_location('sale_message_archive', reader)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    member = module.Archive(locales_path).read('Locales/Korean/CommonMessages.xml')
    expected = '830cc748fc4739bd11d02ca741a5380895e5f170fdf88b6dc166ee7b9d2e60cc'
    if digest(member) != expected:
        raise ValueError('CommonMessages identity differs')
    rows = [(3, 19, 0x6994F4, 0xD65D04, 0xC18FE8, 'kInsufficient_Cash'),
            (4, 21, 0x699527, 0xD65D1C, 0xC18FB8, 'kInsufficient_CashInvenMax'),
            (5, 265, 0x69955A, 0xD6688C, 0xC17B1C, 'kCashShopPermissionDenide')]
    for source in (original, variant):
        if pe_window(source, 0x6994C5, 0xAB) != pe_window(original, 0x6994C5, 0xAB):
            raise ValueError('Purchase consumer window differs')
        for status, code, push, entry, key_address, key in rows:
            instruction = b'\x6a' + bytes([code]) if code < 128 else b'\x68' + struct.pack('<I', code)
            if pe_window(source, push, len(instruction)) != instruction:
                raise ValueError('Message code push differs')
            if struct.unpack('<III', pe_window(source, entry, 12)) != (code, key_address, 0xC11778):
                raise ValueError('Message triplet differs')
            if pe_window(source, key_address, len(key) + 1) != key.encode() + b'\0':
                raise ValueError('Message key differs')
    return dict(clientExecuted=False, commonMessagesSha256=expected,
                consumerWindowSha256=digest(pe_window(original, 0x6994C5, 0xAB)),
                mappings=[dict(status=s, messageCode=c, key=k) for s, c, _, _, _, k in rows])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for arg in ('bin', 'v2', 'locales'):
        parser.add_argument('--' + arg, type=Path, required=True)
    args = parser.parse_args()
    print(json.dumps(check(args.bin, args.v2, args.locales), ensure_ascii=False, indent=2))
