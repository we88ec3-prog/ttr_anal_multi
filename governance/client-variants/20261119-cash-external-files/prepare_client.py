"""Create a separately named v2 mall variant and bootstrap XML; never overwrite existing different bytes.

User authorization: 2026-11-19, independent mall file, retain originals/old versions.
No game execution, attachment, download, STP rewrite or new wire protocol.
"""
import argparse
import hashlib
import importlib.util
import json
import struct
from pathlib import Path
from xml.etree import ElementTree as ET

PINS = {
    'exe': '6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c',
    'bin': '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91',
    'original': '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442',
    'working': 'ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c',
    'reader': 'b47f343d9ab4fdc667939023c0c2fa577975ef3b07c848249a25bbcd1aea0a9d',
    'original_xml': '77b3f5d521f3c01948210f8c0895c6eb4e5b7d9a4bc6914e11d6608fd4bcd5e3',
    'working_xml': 'd1971c9482f1b74cdc8ed9d0208cc65181ad0f03766b6dce470489155e41f9ed',
}
OLD = b'Table/CashProduct.xml\0'
NEW = b'TC_Mall/CashTable.xml\0'
FILE_OFFSET = 0x80c698
RANGES = [(0x511e40, 0xb0), (0x72f110, 0x510), (0x714770, 0x120),
          (0x713910, 0x2a0), (0x714c50, 0x1f0), (0x714030, 0x240), (0x713cc0, 0x1c0)]


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def pinned(path, name):
    raw = Path(path).read_bytes()
    if sha(raw) != PINS[name]:
        raise ValueError('Source identity differs: ' + name)
    return raw


def pe_sections(raw):
    pe = struct.unpack_from('<I', raw, 0x3c)[0]
    if raw[:2] != b'MZ' or raw[pe:pe+4] != b'PE\0\0':
        raise ValueError('Expected PE')
    count = struct.unpack_from('<H', raw, pe+6)[0]
    optional = pe + 24
    if struct.unpack_from('<H', raw, optional)[0] != 0x10b:
        raise ValueError('Expected PE32')
    base = struct.unpack_from('<I', raw, optional+28)[0]
    table = optional + struct.unpack_from('<H', raw, pe+20)[0]
    sections = []
    for index in range(count):
        offset = table + index*40
        virtual_size, rva, size, disk = struct.unpack_from('<IIII', raw, offset+8)
        sections.append((rva, size, disk))
    return base, sections


def file_offset(raw, va, length):
    base, sections = pe_sections(raw)
    for rva, size, disk in sections:
        delta = va-base-rva
        if 0 <= delta and delta+length <= size:
            return disk+delta
    raise ValueError('Unmapped source window')


def write_new_or_identical(path, raw):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        if path.read_bytes() != raw:
            raise ValueError('Refusing to replace existing different file: ' + str(path))
        return
    with path.open('xb') as stream:
        stream.write(raw)


def prepare(args):
    exe = pinned(args.exe, 'exe')
    original_bin = pinned(args.bin, 'bin')
    originals = {str(Path(args.exe).resolve()): sha(exe), str(Path(args.bin).resolve()): sha(original_bin)}
    reader_path = Path(__file__).resolve().parents[1] / '20261105-zh-tw-v3/tools/stp_resources.py'
    pinned(reader_path, 'reader')
    spec = importlib.util.spec_from_file_location('mall_pinned_archive', reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    members = {}
    for name, path in [('original', args.original), ('working', args.working)]:
        archive = pinned(path, name)
        originals[str(Path(path).resolve())] = sha(archive)
        member = reader.Archive(path).read('Table/CashProduct.xml')
        if sha(member) != PINS[name+'_xml'] or ET.fromstring(member).tag != 'CASH_PRODUCT_LIST':
            raise ValueError('Source member identity/root differs')
        members[name] = member
    if len(OLD) != len(NEW) or exe.count(OLD) != 1 or exe[FILE_OFFSET:FILE_OFFSET+len(OLD)] != OLD:
        raise ValueError('Expected unique exact filename literal')
    if file_offset(exe, 0xc0e098, len(OLD)) != FILE_OFFSET:
        raise ValueError('Filename VA mapping differs')
    # Caller passes ECX filename, not a stack filename. The old decompiler omitted ECX.
    call = bytes.fromhex('b998e0c0008db42400010000899c248c010000e868d22100')
    for raw in (exe, original_bin):
        offset = file_offset(raw, 0x511e90, len(call))
        if raw[offset:offset+len(call)] != call:
            raise ValueError('Cash loader filename/call instructions differ')
    windows = []
    for address, length in RANGES:
        first = file_offset(exe, address, length)
        second = file_offset(original_bin, address, length)
        raw = exe[first:first+length]
        if raw != original_bin[second:second+length]:
            raise ValueError('Original/v2 loader windows differ')
        windows.append(dict(address=hex(address), bytes=length, fileOffset=hex(first), sha256=sha(raw)))
    modified = exe[:FILE_OFFSET]+NEW+exe[FILE_OFFSET+len(OLD):]
    changes = [index for index, (a, b) in enumerate(zip(exe, modified)) if a != b]
    if len(modified) != len(exe) or not all(FILE_OFFSET <= x < FILE_OFFSET+len(OLD)-1 for x in changes):
        raise ValueError('Unexpected binary changes')
    output = Path(args.client_root).resolve()
    target = output/'Tartaros.ip-zh-tw-only-v2-mall-v1.exe'
    xml_target = output/'TC_Mall/CashTable.xml'
    evidence = Path(args.evidence).resolve()
    # Check every destination before any write; reruns must not replace a published XML.
    artifacts = [(target, modified), (xml_target, members['working'])]
    artifacts += [(evidence/'templates'/f'{name}-CashProduct.xml', raw) for name, raw in members.items()]
    for path, raw in artifacts:
        if path.exists() and path.read_bytes() != raw:
            raise ValueError('Destination already contains a different version: '+str(path))
    for path, raw in artifacts:
        write_new_or_identical(path, raw)
    if any(sha(Path(path).read_bytes()) != digest for path, digest in originals.items()):
        raise ValueError('An original changed')
    receipt = dict(schema='LOCAL_CASH_EXTERNAL_CLIENT_VARIANT_V1_NOT_NATIVE_MEF',
        authorization='2026-11-19 explicit user request; retain originals/old versions',
        sourceFiles=originals, oldFilename=OLD[:-1].decode(), newFilename=NEW[:-1].decode(),
        filenameVA='0xc0e098', filenameFileOffset=hex(FILE_OFFSET),
        outputExe=str(target), outputExeSha256=sha(modified), executableBytes=len(modified),
        changedBytes=len(changes), changedOffsets=[hex(x) for x in changes], codeWindows=windows,
        bootstrapXml=str(xml_target), bootstrapXmlSha256=sha(members['working']),
        bootstrapRows=len(ET.fromstring(members['working'])), tableRepacked=False,
        originalFilesUnchanged=True, gameExecuted=False, attached=False,
        runtimeAcceptance='PENDING_DESIGNATED_CLIENT_HUMAN_TEST',
        reloadPolicy='Restart Client from game directory after matching paired release; no hot reload')
    encoded=(json.dumps(receipt, ensure_ascii=False, indent=2)+'\n').encode('utf-8')
    write_new_or_identical(evidence/'client-variant-receipt.json', encoded)
    print(json.dumps(receipt, ensure_ascii=False))


if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('exe', 'bin', 'original', 'working', 'client-root', 'evidence'):
        parser.add_argument('--'+name, required=True, type=Path)
    prepare(parser.parse_args())
