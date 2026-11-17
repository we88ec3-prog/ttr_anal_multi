"""Project paid hair items, exact style/color indices and model descriptor identities."""

import argparse
import importlib.util
import json
from pathlib import Path
from xml.etree import ElementTree as E

from verify import ROOT, PINS, digest, pinned
from build_catalog import PRODUCT_SHA, ITEM_SHA

CHA_SHA = "ad5e92f9ef63afa1c2f5849823291c8ae3de7f885ece24fef1b6d771b03a9185"
HAIR_SHA = "bd99ebd799c5ebdac6b1e71a666294f5ca258ad282ff2d565ea4218554b78efa"
CATALOG_SHA = "1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd"


def project(table, cha, hair, cash):
    for path, sha in [(table, PINS["table"]), (cha, CHA_SHA), (hair, HAIR_SHA), (cash, CATALOG_SHA)]:
        pinned(path, sha)
    reader_path = ROOT.parent / "20261105-zh-tw-v3/tools/stp_resources.py"
    pinned(reader_path, PINS["reader"])
    spec = importlib.util.spec_from_file_location("hair_archive", reader_path)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    tables, actors, models = reader.Archive(table), reader.Archive(cha), reader.Archive(hair)
    evidence = {"table": {}, "ipk": {}, "descriptors": {}}
    absent_action_rows = []

    def xml(archive, member, group, expected=None):
        raw = archive.read(member)
        sha = digest(raw)
        if expected and sha != expected:
            raise ValueError(f"Member differs: {member}")
        evidence[group][member] = sha
        # XML declarations in these source members use legacy Korean encodings.
        try:
            return E.fromstring(raw)
        except (LookupError, ValueError):
            return E.fromstring(raw.decode("cp949"))

    products = {int(x.attrib["PRODUCT"]): x for x in xml(tables, "Table/Product.xml", "table", PRODUCT_SHA)}
    items = {int(x.attrib["item"]): x for x in xml(tables, "Table/ItemTable2.xml", "table", ITEM_SHA)}
    usable = {int(x.attrib["item"]): x for x in xml(tables, "Table/ItemUsableTable.xml", "table",
        "30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c")}
    single = {int(x.attrib["index"]) for x in xml(tables, "Table/HairInfo.xml", "table",
        "b693f42b6e964f2378856eda2bb027b64b21da591941c60d2a21cb793f2b5bd7").findall("SingleColorHairList/HairStyle")}
    action_rows = xml(tables, "Table/HairItemActionList.xml", "table",
        "58b94271d8249666e0e735c0127bdd538804e9c8ddd2f83fe5813ca07671a955")
    action_map = {}
    for row in action_rows:
        key = (int(row.attrib["ITEM"]), int(row.attrib["CHAR"]))
        if key in action_map:
            raise ValueError("Duplicate hair item/role action")
        action_map[key] = (int(row.attrib["ACTION"]), int(row.attrib["VALUE"]))
    names = {1: "Soma", 2: "Pipa", 3: "Sblm", 4: "Isla", 5: "Aelt", 6: "Grnt", 7: "Crmd", 8: "Ruko", 9: "Epds"}
    # Native role names and the original per-character IPK carrier keep the role domain explicit.
    style_sources = {}
    defaults = []
    for role, name in names.items():
        root = xml(actors, f"Cha/{name}_Hair.ipk", "ipk")
        for row in root.findall("ItemList/Item"):
            style, variant = int(row.attrib["Index"]), int(row.attrib["Level"])
            key = (role, style, variant)
            if key in style_sources:
                raise ValueError("Duplicate style variant")
            style_sources[key] = row.attrib["File"]
        candidates = [(key, path) for key, path in style_sources.items() if key[0] == role and key[2] == 0
                      and f"/{role:02d}_Default{name}_" in path]
        if len(candidates) != 1:
            raise ValueError(f"Ambiguous source default for role {role}")
        defaults.append(dict(role=role, style=candidates[0][0][1]))
    entries = []
    selected = {x["product"] for x in json.loads(cash.read_bytes())["offers"]
                if x["available"] and x["itemClass"] in (38, 39)}
    for product in sorted(selected):
        item_id = int(products[product].attrib["ITEM"])
        item = items[item_id]
        limits = item.findall("USE_LIMIT")
        if len(limits) != 1 or set(limits[0].attrib) != {"char"} or item.attrib["quan"] != "100":
            raise ValueError("Unsupported hair qualification or stack limit")
        role = int(limits[0].attrib["char"])
        if role not in names or item.find("COOLTIME").attrib != {"group": "6"}:
            raise ValueError("Hair role or cooldown differs")
        action = 13 if item.attrib["class"] == "38" else 14
        rows = usable[item_id].findall("ACTION")
        if len(rows) != 1 or rows[0].attrib != {"action": str(action), "priority": "5"}:
            raise ValueError("Hair action differs")
        values = rows[0].findall("VALUE")
        if len(values) != 1:
            raise ValueError("Unsupported hair action value count")
        value = int(values[0].attrib["value"])
        if (item_id, role) not in action_map:
            absent_action_rows.append(dict(product=product, item=item_id, role=role))
        elif action_map[(item_id, role)] != (action, value):
            raise ValueError(f"HairItemActionList differs: product={product} item={item_id} role={role} usable={(action,value)} hair={action_map.get((item_id,role))}")
        entries.append(dict(product=product, item=item_id, role=role, action=action, value=value))
    required = {(x["role"], x["value"]) for x in entries if x["action"] == 14}
    required.update((x["role"], x["style"]) for x in defaults)
    styles = []
    for role, style in sorted(required):
        variants = sorted(key[2] for key in style_sources if key[:2] == (role, style))
        if not variants or 0 not in variants or any(not 0 <= v <= 255 for v in variants):
            raise ValueError("Missing style variants")
        if style in single and variants != [0]:
            raise ValueError("Single-color style unexpectedly has variants")
        for variant in variants:
            path = style_sources[(role, style, variant)]
            prefix = "Character/Cha/"
            if not path.startswith(prefix):
                raise ValueError("Unexpected model path")
            descriptor = xml(models, path[len(prefix):], "descriptors")
            if descriptor.tag != "Item" or descriptor.attrib.get("EquipIdentifier") != "8":
                raise ValueError("Not a source hair component")
        styles.append(dict(role=role, style=style, singleColor=style in single, variants=variants))
    absent_variants = []
    for entry in entries:
        if entry["action"] == 13:
            for style in styles:
                if style["role"] == entry["role"] and not style["singleColor"] and entry["value"] not in style["variants"]:
                    absent_variants.append(dict(product=entry["product"], style=style["style"], color=entry["value"]))
    if len(entries) != 209 or sum(x["action"] == 13 for x in entries) != 90:
        raise ValueError("Active hair product coverage differs")
    content = dict(schema="LOCAL_HAIR_ITEMS_V1_NOT_NATIVE_MEF", tableSha256=PINS["table"],
        chaBaseSha256=CHA_SHA, hairPackSha256=HAIR_SHA, cashCatalogSha256=CATALOG_SHA,
        defaults=defaults, styles=styles, entries=entries)
    return content, dict(verification="SOURCE_HAIR_ACTIONS_IPK_AND_COMPONENT_DESCRIPTORS",
        sourcePins=dict(table=PINS["table"], cha=CHA_SHA, hair=HAIR_SHA, cash=CATALOG_SHA),
        members=evidence, products=len(entries), dyeProducts=90, styleProducts=119, styles=len(styles),
        descriptors=len(evidence["descriptors"]), clientRuntimeVerified=False,
        absentHairItemActionRows=absent_action_rows,
        absentExactDyeVariants=absent_variants,
        defaultSelectionPolicy="SERVER_USES_UNIQUE_SOURCE_DEFAULT_WHEN_NO_HAIR_STATE_SAVED")


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ("table", "cha", "hair", "cash", "output", "evidence"):
        p.add_argument("--" + name, type=Path, required=True)
    p.add_argument("--check", action="store_true")
    a = p.parse_args()
    content, evidence = project(a.table, a.cha, a.hair, a.cash)
    raw = (json.dumps(content, indent=2) + "\n").encode("utf-8")
    if a.check:
        if a.output.read_bytes() != raw:
            raise ValueError("Hair catalog projection differs")
    else:
        a.output.write_bytes(raw)
    evidence["catalogSha256"] = digest(raw)
    a.evidence.write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({key: evidence[key] for key in ("products", "styles", "descriptors", "catalogSha256")}))


if __name__ == "__main__":
    main()
