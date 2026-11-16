# Blocked skill bindings: bounded follow-up completed — 2026-11-07

Root requested independent evidence for16 blocked matrix0 skill bindings, with
priority to Soma Z/ZC, Pipa Z/ZX, Aelt Z/ZX, Grnt X/XC and Crmd Z. This follow-up
is complete within the following declared scope. No new mapping was promoted.

## New evidence beyond the earlier stem join

1. Re-read all16 blocked Practice files from original and working Table carriers.
   Full schema includes requirements, payment, SkillLevel TargetSkillID, values
   and interrupts. None has a motion/animation/effect/file/alias attribute. The
   confirmed Practice-to-active links do not also constitute motion links.
2. Read the16 corresponding complete SkillActiveTable entries. They contain
   gameplay/cost/attack/heal/buff data, but no explicit motion/animation/effect/
   file/alias attribute. This is a bounded actual-entry check, not an assertion
   that all469 active entries or every native structure lack such a mapping.
3. Inspected9 relevant ASD files and5 role ABFs. ABF animation IDs and ASD Header
   IDs identify motions. Header NAME simply echoes filenames, such as
   Soma_ELECSHOCK01, Pipa_HAMMERING01, Aelt_MANABURN01, Grnt_SUMMON01/EGRITSOUL01.
   None of these selected schemas exposes a matching ActiveSkillID or alias to
   the blocked Practice filename. These filename contrasts are NOT proposed
   skill associations.
4. Inspected3 selected EFF schemas:BasisAttack01,BasisElecshock01,BasisHammering01.
   They contain visual effect composites and no explicit skill/motion/animation
   ID attribute. They do not independently prove a SkillID-to-animation bridge.
5. Inspected auxiliary CharSkill,EffectList,EffectCategoryMapper,
   IndependentSkillEffect and the Soma/Pipa/Grnt Dealer AI tables. CharSkill has
   skill membership, effect tables have visual-effect IDs, and AI rules refer to
   tier/key/phase. None of these selected structures supplies the needed direct
   activeID-to-motion or declared spelling-alias relation.
6. Existing native-source references retained:530890 SkillActive parser,
   546100 primary controller input,4B01C0 S2C motion receiver and4C8A90 playback.
   Prior bounded analysis says0D supplies the motion and receiver plays it.
   This is not proof of an autonomous client-side skill-to-motion chooser, nor
   a whole-client absence verdict. No new decompilation/provider request was made.

## Identity and safety

41 original/working member reads matched byte-for-byte. Full hashes, schema tag
and attribute inventories, nominal header names, and four existing source-file
hashes are in structural-followup.json. No raw XML/ASD/EFF payload was exported.
No Client/Server/original resource was changed, no target execution/attachment,
no MEF search, no Git commit. The constructor/projection files remain separate
from this follow-up; parent controls integration and Server activation.

## Disposition

READY promotions:0. All16 blocked rows remain blocked, including multi-phase
sequences whose complete execution/hit/phase behavior remains unproven. No edit
to runtime-rows.json was made. In particular, do not auto-alias elecshook to
ELECSHOCK, hammer to HAMMERING, summ to SUMMON, egrit to EGRITSOUL, or infer a
basic SkillID from a generic BasisAttack effect merely because it is plausible.

A future exact bridge must come from explicit dispatch/alias data, an independently
identified relevant native path, or separately qualified runtime/reference
animation evidence. An animation-only probe can display a raw motion ID without
claiming which skill it implements, but cannot by itself close the binding.
Per root direction, stop this bounded search here and preserve the16 exclusions.
