# Learned level, script level, tier and matrix are separate (2026-11-07)

Status: PARTIAL. Existing source-only audit, not T01/native FULL-PASS and not an official Server specification. No game execution/attachment, provider request, MEF search, Client/Server modification or Git commit. Source identities are pinned in source-identities.json.

## Closed bounded native data flow

41D5F0 iterates 8-byte learned-Practice records. Record DWORD0 is PracticeID; low WORD of DWORD1 indexes that Practice level-vector at object+14/+18. The selected level-data modifier vector +14/+18 is passed to81B7F0.

81B7F0 routes SkillLevel(type12100000,flag2) and SkillScriptLevel(type12200000,flag4) into different modifier vectors.825FA0 reads vector+14/+18 and sums signed modifier+8 into the active cache short+4; target ActiveID is modifier short+4. New cache records are8 bytes with DWORD+4=10000: level+4 starts0 and scriptLevel+6 starts1. The separate vector+24/+28 applies unsigned MAX(modifier+8) to cache short+6. These fields must not be conflated.

4E46D0/4E48A0 collect both role+FC learned Practice and selectedPreset+110 into the modifier accumulator before825FA0. Duplicating identical SkillLevel grants in both collections adds levels twice. Preset selection uses role+1F4/+1F5, chosen by +1F6; this is a separate concept from actor+3E8 charge-tier row.

530890 loads ACTIVEINFO hp/sp/mp/cooltime into signed shorts at row+0/+2/+4/+6, stride16.530530/5305C0/530650/5306E0 take one-based level and access vectorBase-16+level*16.549980 obtains the learned active cache through825F70 before getters; its decompilation omits register ABI inputs, so the exact cache+4-to-getter-register def-use is retained PARTIAL rather than claimed closed.

## Resource evidence and the missing presentation bridge

Isilia Practice50(isla_wslash) levels1..11 declare SkillLevel target30 Value=level; Practice52 target31 and53 target32 similarly have multiple SkillLevel rows. They do not establish automatic ScriptLevel thresholds. Talent1403(target30),1401(target31),1407(target32),1417(target35) separately contain SkillScriptLevel Level=2 in their first catalogued level. Full list is in contract.json.

Isilia motion108/Wslash01 explicitly references BasisWslash01 effect;120/Wslash02 references AverageWslash01;141/Wslash03 references ExperWslash01. Other Sslash/Hslash/Rampage/Surprise variants are projected from original ABF->ASD->EFF exact member paths and hashes. This proves distinct presentation resources exist, not which learned level or Talent runtime selects each one. No rule such as levels1-3=Basis,4-6=Average is supported here.

The active cache+6 consumer selecting a specific script/action/motion remains open. Consequently it is safe to vary actual Practice learned level and recompute cost/stat rows for a test lab, but not safe to manufacture motion progression from general level bands. A Talent test should publish its actual modifier and mark presentation verification pending until the cache+6 dispatch is closed.

## Distinct parameters

- Learned Practice level: level-specific modifiers and active cache+4.
- SkillScriptLevel: separate Talent modifier, active cache+6 default1/MAX.
- Charge tier: actor+3E8 written by ParamUpdate property4; matrix row0..3.
- Matrix/preset selector: per-hero+1F4/+1F5 selected by+1F6.
- ParamUpdate property17hex writes actor+3D4, not per-hero+1F6. Property8 has no explicit known CCharacter4CE7F0 branch and must not be guessed as selector setter.
