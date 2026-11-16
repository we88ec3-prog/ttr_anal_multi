# Skill levels and matrix declarations

These are read-only projections of original Table.stp members, compared byte-for-byte with working members. No Client, Server, source archive or Git history was changed by this evidence task.

## Exact learned-level costs

`build_skill_level_projection.py` reproduces `active-practice-level-costs.json` (schema `tartaros-active-practice-level-costs-v1`), `practice-level-performance.json`, `talent-script-levels.json`, `source-members.json` and `summary.json`.

1448 exact rows cover 270 ActiveSkill Practices for nine roles. Resolve Practice LevelData@Level, then that level's SkillLevel modifier TargetSkillID/Value, then matching SkillActiveTable LEVEL@val/ACTIVEINFO. The learned level must not be treated as ActiveInfo array index. They happen to agree numerically in these rows. No missing-level clamping is allowed. Max level means greatest exact supported LevelData, not a guessed character-level formula.

Consumption hp/sp/mp is the negative of signed source ACTIVEINFO. rawCooltime preserves the source integer. Numeric performance children are evidence, not a reconstructed Server damage formula.

The minimal numeric test selection is role + matrix + tier + per-Practice learnedLevel. A simpler shared learnedLevel may only use the intersection of the selected Practices' supported levels. Existing matrix0 full-profile intersections: tier0 Soma/Pipa/Grnt levels1..5; other six roles1..6; tiers1/2 all roles1..5. Basic Z does not limit these to level1.

## Distinct Talent script axis

608 Talent SkillScriptLevel modifier rows are separate in `talent-script-levels.json`. For example Isilia Active Practice50 grants active30 levels1..11. Talent1403 independently grants active30 scriptLevel2/3 at Talent levels1/2. These are not interchangeable with matrix or key tier. Existing bounded native parser 0x813d60 recognizes SkillScriptLevel separately and constructs CSkillModifier_SkillScriptType. Native consumer/animation variant dispatch is a separate task.

No automatic Basis/Average/Exper/Master/Super animation mapping is assigned from ordinary learned level or Talent script number. The previous v30 Basis previews remain resource candidates, not complete native dispatch proofs.

## Matrix-to-Talent declarations

`build_matrix_talent_links.py` reproduces `matrix-talent-links.json` and `matrix-source-members.json`. These hold 63 matrix declarations, 54 builtin Talent definitions and 55 original/working member identities. Every role has 15 distinct six-key slots in matrix0 and 27 distinct six-key active IDs across matrices0..6. All KeyInfo columns are retained; only columns1..6 count toward that statistic.

Each Matrix explicitly declares prerequisites and BuiltinPracticeList. For Isilia: matrix1 grants1007 level1; matrix2 grants1008 level1; matrix3 grants1007 level2 and1031 level1; matrix4 grants1007 level2 and1032 level1; matrix5 grants1008 level2 and1033 level1; matrix6 grants1008 level2 and1034 level1. These builtin Talents carry interrupt/stat effects. This declaration is directional evidence only: it does not prove that learning a Talent via0126 changes selected matrix. No direct matrix-switch attribute was found while reading all576 Talent XML definitions. Matrix setter/packet field remains unresolved here. Do not substitute Talent learning for a matrix selector.

The existing bulk sources 0x48c6e0,0x8180c0 and0x819280 were bounded reads. 0x48c6e0 names Table/Skill/SkillMatrix.xml, calls the loader and another initialization routine; those alone do not establish a network matrix setter. No new target launch, attachment or binary provider request was performed.

Unresolved: native matrix setter, exact script-level animation dispatch, authoritative multi-phase timing/damage behavior, and the previously reported16 blocked v30 motion bindings. Numeric costs do not resolve these gaps.
