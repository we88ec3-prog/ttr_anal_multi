"""Read pinned KR inputs and check the bounded claims in README.md, offline."""
import argparse
import hashlib
from pathlib import Path
import struct
import sys
from xml.etree import ElementTree as ET

sys.dont_write_bytecode = True
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "20261105-zh-tw-v3" / "tools"))
from stp_resources import Archive

PINS = {
    "bin": "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
    "table": "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442",
    "event": "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b",
}
# VA / original instructions selected from the rooted functions in the notes.
TEXT = {
    0x5030A7: "e8 b4 e6 05 00",                  # scene start
    0x4ADE7D: "c7 80 c4 00 00 00 30 27 4b 00",  # target + steps
    0x4C85AD: "e8 de 22 00 00",
    0x4CAA4D: "ff 8e c8 00 00 00",
    0x4ADE8D: "c7 80 d4 00 00 00 d0 28 4b 00",  # 001a actor removal
    0x4B2AC2: "e8 f9 d0 02 00",
    0x4A94B6: "e8 85 b4 09 00",                  # local and network checkpoint callers
    0x4B333B: "e8 00 16 09 00",
    0x543B77: "88 8b 05 01 00 00",
    0x4A103C: "e8 df 10 03 00",                  # world CNPC constructor
    0x4AE82B: "e8 f0 38 02 00",
    0x5437F0: "e8 1b 81 fb ff",                  # market marker
    0x543865: "e8 66 e5 00 00",
    0x544491: "e8 7a 74 fb ff",                  # shop no -> shop row
    0x5444AA: "e8 61 2b fe ff",                  # shop row -> NPC
    0x5444EC: "e8 8f fa 20 00",
    0x683D9B: "e8 c0 7b e7 ff",                  # town / NPC lookup
    0x4FBD2B: "83 c1 0a 89 48 20",               # shop type 2 -> NPC type 12
    0x637D61: "c7 45 e4 1d 00 00 00",              # menu function 29
    0x637D68: "c6 45 f3 0c",
    0x638810: "c7 81 4c 01 00 00 f0 9e 63 00",    # function 29 delegate
    0x639F17: "c7 40 10 f6 42 0f 00",              # open enhancement window
    0x5B77F2: "8b 83 64 02 00 00",
    0x5B8CF7: "8b 89 64 02 00 00",                 # enhancement result window
    0x686FB4: "68 e0 2b bf 00",
    0x4A373E: "b9 27 00 00 00",                  # purchase request
    0x4A37C9: "b9 20 00 00 00",                  # sell request
    0x4ADFFD: "c7 80 84 01 00 00 60 37 4b 00",  # trade feedback
    0x4A3C03: "b8 a1 00 00 00",                  # ordinary enhancement cue
    0x4E1ECF: "c7 80 cc 06 00 00 20 34 4e 00",
    0x4DD0C6: "0f be 49 02",
    0x4C4F89: "c7 00 01 00 00 00",               # tutorial completion flag
    0x58547D: "68 59 03 00 00 68 a8 78 d6 00",  # 857-entry text catalogue
}


def check(condition, name):
    if not condition:
        raise ValueError(name)


def verify_bin(binary):
    # These raw offsets are only valid under the required full-file hash.
    for va, encoded in TEXT.items():
        expected = bytes.fromhex(encoded)
        offset = va - 0x400C00
        check(binary[offset:offset + len(expected)] == expected, hex(va))
    # Locate the clear-condition keys in the localisation descriptors, not by
    # assuming their English names describe an executable clear-event producer.
    keys = []
    for index in range(857):
        key, ptr, default = struct.unpack_from("<III", binary, 0x9650A8 + 12 * index)
        check(key == index and default == 0xC11778, f"descriptor {index}")
        start = ptr - 0x401A00
        name = binary[start:binary.index(0, start)]
        if name.startswith(b"kClearCondition_"):
            keys.append(key)
    check(keys == list(range(515, 537)), "22 localised condition keys")


def verify_resources(table, event):
    def rows(member):
        return ET.fromstring(table.read("Table/" + member))

    shops = rows("ShopInfo.xml").findall("./SHOP[@TOWN='1']")
    inventory = [(int(s.get("NO")), int(s.get("TYPE")), int(s.get("NPC")), len(s.findall("PRODUCT"))) for s in shops]
    check(inventory == [(1, 1, 10028, 5), (2, 2, 10030, 27), (3, 3, 10029, 3),
                        (4, 4, 10031, 6), (70, 7, 10013, 1)], "Town1 shops")
    town = rows("_TownList.xml").find("./TOWN[@ID='1']")
    roster = {int(item.get("ID")) for item in town.findall("./NPCLIST/NPC")}
    check(roster == {10001, 10002, 10003, 10008, 10013, 10014, 10047, 10048, 10015}, "Town1 roster")
    check({entry[2] for entry in inventory} & roster == {10013}, "merchant / NPC intersection")
    actor_models = {int(x.get("ID")) for x in rows("_ActorList.xml").findall("./OBJCATEGORY[@ID='6']/ACTOR")}
    check({s[2] for s in inventory} & actor_models == {10013}, "class-6 model intersection")
    npc_rows = rows("npctable.xml")
    check(all(npc_rows.find(f"./NPC[@ID='{s[2]}']/TALKLIST/TALKSET") is not None for s in inventory), "talk sets")
    check(all("X" not in s.attrib and "Y" not in s.attrib for s in shops), "market list has no direct XY")
    check(npc_rows.find("./NPC[@ID='10030']").get("TYPE") == "12", "blacksmith NPC type")
    check(npc_rows.find("./NPC[@ID='10015']").get("TYPE") == "6" and
          rows("ItemExpertNPCTable.xml").find("./NPC[@ID='10015']") is not None, "separate item expert")
    product = rows("Product.xml").find("./PRODUCT[@PRODUCT='183']")
    check((product.get("ITEM"), product.get("LEELOO"), product.get("SELL_LEELOO")) == ("183", "2000", "200"), "product 183")
    check(shops[0].find("./PRODUCT[@NO='183']") is not None, "product 183 on shelf 1")
    chance = rows("ItemEnchant.xml").find("./EQUIP_LEVELUP/INFO[@EQUIP='1'][@LEVEL='1']")
    cost = rows("ItemEnchantCharge.xml").find("./EQUIP_LEVELUP/EQUIP_LEVELUP[@CLASS='1'][@RANK='1'][@LEVEL='1']")
    check((chance.get("SUCCESS"), chance.get("FAIL"), chance.get("BROKEN"), cost.get("CHARGE")) ==
          ("80", "20", "0", "375"), "separate raw chance and cost tables")
    qc = ET.fromstring(event.read("Event/SceneList.xml").decode("cp949"))
    scene = qc.find("./SCENE[@questIdx='119'][@sceneIdx='3']")
    check(scene.get("funcName") == "Phindous_YuriandRazed_Boss", "scene keys")
    seq = event.read("Event/Sequences/Phindous_YuriandRazed_Boss.seq")
    check(hashlib.sha256(seq).hexdigest() == "05abe5f9773c3b0b40d5a849f7d984b4f06f57d2e5a5fe8c931e83ec2d7b857a", "scene bytes")
    check(seq.count(b"WalkObject(") == 5 and seq.count(b"AniObject(") == 6, "scene local operations")


def main():
    cli = argparse.ArgumentParser(description=__doc__)
    for name in PINS:
        cli.add_argument("--" + name, type=Path, required=True)
    args = cli.parse_args()
    for name, digest in PINS.items():
        check(hashlib.sha256(getattr(args, name).read_bytes()).hexdigest() == digest, name + " SHA-256")
    verify_bin(args.bin.read_bytes())
    verify_resources(Archive(args.table), Archive(args.event))
    print(f"PASS: 3 pinned originals, {len(TEXT)} anchored instruction spans, 22 localisation keys, "
          "Town1 NPC/merchant/price/enhancement tables and Q119/3. Offline only.")


if __name__ == "__main__":
    main()
