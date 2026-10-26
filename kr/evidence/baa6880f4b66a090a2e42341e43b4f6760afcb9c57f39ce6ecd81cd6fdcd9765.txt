# T08 — CMonster inherited component construction and initialization boundaries

- Author: **chatgpt-web roy**
- Verified: **2026-10-26 19:01:48 +08:00 (Asia/Taipei)**
- Target: `Tartaros.bin` (SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)
- Method: direct `objdump -d -Mintel` inspection
- Scope: `0x004CA730`, `0x004C7070`, `0x004C9F90`, `0x004D1710`; no runtime test

## Verified initialization hierarchy

1. `CMonster` at `0x004D1710` calls `0x004C7070` at `0x004D173A` after pushing the same object pointer.
2. The parent constructor `0x004C7070` calls `0x004CA730` (base data layout initialization) at `0x004C709D`. It then calls `0x004C9F90` with address `object+0xF0`; the helper zeros 25 contiguous pointer-sized fields at offsets `+0x04...+0x64` relative to its argument and sets a vtable and `+0x68` zero. Consequently the owner component slot table begins at `object+0xF4`.
3. The parent ctor allocates `0x38` bytes at `0x004C723F`, invokes `0x004CB230` with `ECX=1`, sets vtable `0x00C0779C`, initializes offsets `+0x28/+0x2C/+0x30` to 1, and inserts this component using its `component+0x08` type id into `object+0xF4 + id*4` at `0x004C72D9`. The parent also populates `object+0x158` if not already set, and initializes other object components later in the parent ctor (outside narrow scope).
4. The derived `CMonster` ctor initializes `+0x420/+0x428/+0x430` to 0 and `+0x42C` to float zero at `0x004D1759–0x004D176D`.
5. The derived constructor allocates three more components:
   - type **3**, `0x3C` bytes, vtable `0x00C077CC` (`0x004D1747–0x004D17C1`);
   - type **2**, `0x38` bytes, vtable `0x00C077B4` (`0x004D17D7–0x004D182F`);
   - type **5**, `0x3C` bytes, vtable `0x00C077FC` (`0x004D1845–0x004D189A`).
   Each uses `0x004CB230` then writes a slot in the same inherited `+0xF4 + id*4` component table.
6. The `CMonster` ctor sets `object+0x39C=1` at `0x004D18B2`. The parent originally sets the field to `0x7f` at `0x004C717F`; this is an explicit subclass override during construction.

## Important interpretation and limits

- The parent creates at least **one** additional type-1 component. Thus `CMonster` has at least types **1, 2, 3, 5** in its inherited component system; this is a lower bound because other parent constructor parts and later initialization may add entries.
- `0x004C9F90` is a component-slot-table constructor (its 25 zeroed pointer slots and header), **not evidence of model/AvatarBase resource loading**.
- The `object+0x158` pointer is a fallback/first-component pointer set if null; **not proven** to be the graphical resource pointer.
- No direct call to `0x007AEE60`, `0x007197E0` or AvatarBase loaders was observed **within the inspected derived constructor**; lack of a direct call here does not exclude indirect or later binding.
- Names like `CMonster` and `AvatarBase` follow established task labels, not a newly recovered full C++ type system.

## Next targets

A. Enumerate the full parent constructor `0x004C7070` beyond `0x004C72F0` for other inherited type slots.
B. Enumerate xrefs to the CMonster vtable and to writes at `+0x420/+0x428/+0x430`.
C. Connect actual resource pointer assignment paths to `CharacterList` / AvatarBase, rather than inferring from construction-time state only.

No canonical `kr/` or binary changes were made.
