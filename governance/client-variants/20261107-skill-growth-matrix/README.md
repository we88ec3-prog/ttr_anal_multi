# Skill growth: three independent axes

`growth-matrix.json` (schema tartaros-skill-growth-three-axes-v1) covers270 role/active pairs from270 Practices,243 of which occur in the six-key matrix slots. It joins all608 explicit Talent SkillScriptLevel rows, exact ordinary numeric-level changes, existing exact-stem motion/effect candidates and bounded original/Taiwan description metadata.158 role/active pairs have at least one existing resource candidate. No numeric-level-to-animation correspondence was inferred.

`ISILIA-27.md` is the readable27-skill comparison; `isilia-27.json` is its detailed metadata. `isilia-explicit-text-rules.json` structures13 narrowly matched Taiwan description rows for target/projectile counts, cooldown reduction or duration increase. Those remain descriptions, not native runtime parameters.

## Three source checks

`isilia-three-source-checks.json` records seven levels across original Talent1407,1427,1435. It contains complete modifier attributes and complete structured interrupt children, dual-region description excerpts and hashes, plus original/working member hashes.

-1435 / active2505: KR explicitly says target count increases TO2/3/4, agreeing with TC. Talent levels1/2/3 grant SkillScriptLevel2/3/4; Interrupts empty. No typed target-count value is present in these Talent definitions.
-1427 / active474: both regions contain4/5, but KR wording says projectile count increases4/5, whereas TC says firing count increases TO4/5. Delta versus total is unresolved. Talent levels1/2 grant SkillScriptLevel2/3; Interrupts empty. Do not make KR total count4/5 solely from the TC description.
-1407 / active32: KR and TC descriptions both say cooldown decreases1/2 seconds, alongside increased attack range. Talent levels1/2 grant SkillScriptLevel2/3. Separately, each has Interrupt Type=Consume Cooltime=-10/-20, with Condition Type=SkillLevel SkillID=32. Thus cooldown change has an explicit typed interrupt; it is not solely an inferred consequence of ScriptLevel. Native Consume timing/application is still a separate consumer proof.

Basis/Average/Exper/Master/Super presence is listed from existing resource evidence, with no assertion that level2 means Average or level3 means Exper. Some script levels have no exact animation join and remain unresolved. Ordinary skill levels expose changed ATTACK/HEAL/ACTIVEINFO fields only; they do not prove extra hits or projectiles.

## Conditional Consume projection

`project_talent_consume_interrupts.py` produces `talent-consume-interrupts.json` (schema tartaros-talent-consume-interrupts-v1). The explicitly requested scope is the576 known Talent members, not a new archive or native-code search.432 Consume level rows come from81 original/working members whose bytes and pinned original hashes match.420 rows have one explicit target SkillLevel.SkillID and no additional Condition;12 have additional runtime conditions and remain blocked for simple application. Every row retains the full learning Requirements, all Conditions, raw signed interrupt attributes and complete ordinary modifiers. Source-shape eligibility is not native runtime admission.

Observed attributes are Cooltime411 rows, MPPercent162 and SPPercent133. No absolute HP/SP/MP delta attribute exists here. Accordingly hpDelta/spDelta/mpDelta are null rather than guessed values; spPercentDelta/mpPercentDelta remain separate signed raw fields. Missing attributes must not overwrite costs. Missing target conditions must never make a modifier global. Learning requirements, runtime conditions, stacking, percentage base, rounding and event timing must be respected or separately proven before execution.

Reproduce in order: `build_skill_growth_matrix.py`, `build_isilia_report.py`, `build_isilia_three_checks.py`, `project_talent_consume_interrupts.py`. Existing cost/motion projections are reused with their file hashes. Original and TC explain-table hashes also match the pinned all-skills catalog. No Server/Client/original/Git modification, target execution/attachment or MEF search occurred.
