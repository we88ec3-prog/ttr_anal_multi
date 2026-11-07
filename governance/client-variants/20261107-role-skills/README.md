# Role-skill isolated lab resource candidates — 2026-11-07

Scope assigned by root: all9 roles' matrix0 six-key default and actual later-tier
entries, existing resource evidence only. No game execution/attachment, Server/
Client/original-file changes, MEF search, provider retry or Git commit performed.
Only files under this evidence directory were written.

## Deliverables

- runtime-rows.json: flat local Server-consumable135 rows for matrix0, tiers0/1/2.
- default-six-lab-candidates.json:54 default six-key rows with resource details.
- role-skill-lab-candidates.json: original Practice/active/motion/effect joins,
  nominal durations, costs and source identities.
- source-members.json:432 re-read member identities, original/working equal and
  additionally equal to the previously pinned catalog/motion-join identities.
- blocked-rows.json:16 rows not eligible for automatic motion selection.
- build_role_skill_candidates.py and project_runtime_rows.py: read-only resource
  construction/projection; output metadata here only. The first constructor run
  incorrectly treated catalog.members (a dict) as a list; corrected before output.

No raw XML/member payloads are exported. Catalog and motion-join inputs retain
all prior limitations and their SHA256 identities are stored in the full output.
Original and working carrier hashes may differ;432 selected member hashes match,
not a claim of whole-carrier equality.

## Rule and authority

Use the actual matrix0/tier/column activeID, then the unique ActiveSkill Practice
LEVEL1 TargetSkillID binding. No default active ID/motion is reused merely because
another tier has the same key. Costs are negative signed source HP/SP/MP values
projected to consumption, with raw cooltime retained; raw/10seconds remains the
existing Server candidate convention, not formal recovered time-unit authority.

Motion joins require the previously exact normalized Practice filename-stem to
ASD/effect name match. Refine those candidate motions with explicit effect
-Basis tags only when the motion's effect variant tags are unambiguously Basis.
This adds discrimination for Grnt HEAL106 versus122/123 and Epds ShieldAttack107
versus108/109; it does not equate LEVEL1 or matrix tier with a proven native
variant-selector algorithm. Every output row says native dispatcher UNRESOLVED.
These are lab resource candidates, not official recovered skill execution.

Single-basis candidate: one motion and its nominal ASD split duration.
Basic Z resource sequence: existing exact-stem basis candidates additionally have
consecutive SKILL01_01..N filenames; ordered resource sequence supplied as an
animation lab candidate only. Sequence, timing, damage/hits/locks are not native
combat admission proof. Non-Z multi-basis phases remain blocked with all candidate
motions retained. No nearest-name edits or arbitrary first match.

## Coverage

Default six keys:39 single candidates,5 basic-Z sequence candidates,1 unresolved
multi-basis skill (Soma XC),9 no-exact-resource joins. Full matrix0 actual tiers:
114 single candidates +5 basic Z sequences =119 preview candidates;16 blocked.
Each role has6 tier0,6 tier1 and3 tier2 entries:135 total. No invented missing
later-tier columns, no matrix1..6, no special columns7/8/9/10 or V-charge packet
semantics in this assignment.

Critical corrections against old fixed108/109 prototypes:

- Soma X:Practice2 / active2 -> candidate107 CRUSH.108 is C/DEFENCE,
  109 is ZX/BOOM, not ZC elecshook. Soma ZC spelling mismatch remains unresolved.
- Shubal X:Practice34 / active21 -> candidate107 TACKLE. Practice35 / active24
  is ZX/LIONSW109. C23/37 ->108 VIC; ZC22/36 ->111 REGBREAK.
- Basic sequence candidate counts:Shubal6,Isilia7,Grnt4,Ruko6,Epds6.
  Never apply Isilia101..107 universally to every role.

Known unresolved default keys: Soma Z/ZC and XC phases; Pipa Z/ZX; Aelt Z/ZX;
Grnt X/XC; Crmd Z. Examples such as soma_elecshook vs ELECSHOCK,
pipa_hammer vs HAMMERING, gren_summ vs SUMMON are NOT auto-aliased.

## Consumption

runtime rows have role,tier,mask,practice,active,hp,sp,mp,rawCooldown,motions[],
durationSeq,status,blocked,isBasicChain. blocked rows must not silently use a
fixed fallback motion. Their candidate arrays are diagnostic only. Other rows
may be presented as explicitly candidate animation/cost tests in an isolated
empty arena. No quest grants, normal ownership, full-role balance or all-skills
completion is established. Isilia v28/v29 normal route behavior is not changed
by this resource-only work.
