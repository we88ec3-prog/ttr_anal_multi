# S00: publish square NPC interaction regions

## Actual implementation gap and source qualification

The current C# square bootstrap sent twelve CNPC appearances but no0x27 checkpoint
collection. Actor visibility alone does not establish manual interaction. This is
a concrete missing initialization step; it is not proof of the cause of every
previous user NPC freeze. No new Client observation was performed this round.

Original KR BIN remains9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91.
[Read-only verifier](../inspect_square_npc_interaction.py) reproduced four full
instruction windows, branch alignment and thirteen field/registration assertions;
[evidence](evidence/S00-20261102-SQUARE-NPC-INTERACTION.json) preserves bytes.

-4ADD50 registers4B2AF0 at object+13C, command(13C-4)/8=27.
-4B2AF0 clears the checkpoint manager then iterates18-byte rows after2-byte header.
 Its constructor call at4B2BD5 reads keyWORD, signed categoryBYTE, enableBYTE,
 position pointer, radiusFLOAT and two trailing bytes.
-543700 stores the enable parameter in object+105 at54378D.
-544730 tests object+105 at544739 before distance/input processing. Thus an
 actor record or a zero enable byte does not create an enabled manual checkpoint.

Resource/domain boundaries remain: actor category, checkpoint category and
npctable TYPE10 are different. Existing NPC coordinates and interaction radius2
are provisional Server policy, not official MEF placement or trigger data.
Whole collection publication matters: sending one27 per NPC would replace earlier
regions. No interpretation of27 as quest acceptance or scene ACK is introduced.

## Private candidate implementation and normal verification

Only the existing explicit prerequisite-publication candidate mode now emits
one complete27 collection after NPC appearances and before activation/loading end.
Every region uses the corresponding model and existing XY, category3, enable1,
radius2, manual0 and auxiliary0. All12 regions are sent together. The qualified
15/1 control-restoration branch republishes the complete set after bind/parameters,
because RestoreMap may replace checkpoint objects; this ordering is a candidate,
not a captured official Server sequence. Default/livev10 behavior is unchanged.

Existing positive synthetic journey coverage was expanded to inspect actual TCP
publication:218-byte27 packet, all12 actor-model/region matches, enable/manual/radius
fields, NPC10338 position920/900 and identical full-set republication after the
source-shaped15/1 receipt. Movement/stopping still passes afterward. All26
HappyPath cases passed, zero failed/skipped,14seconds. Deferred tests were not run.
No quest15 completion, acceptance, reward or village transfer is emitted.

## Legacy reference correction

Read-only old workspace reference anal/plaza_npcs.py contains0x45/quest/scene as
an alleged scene start and0x4C as alleged QuestMgr completion. Current original
registration proves503040 scene start is0x47 and5030C0 result consumer is0x64;
0x45 instead routes5027D0. The same reference marks Quest15 complete after15/1
although resourceSceneList lists four scenes and C2S3F value1 may originate in
cleanup. Its tests mirror those assumptions; they are not native acceptance.
Do not port those branches or run the old Server/scripts as validation.

QuestInfo15 was re-read from originalTable09e2... / QuestInfo5d2514... this round:
Demand16, giver/finisher10338, field19, rewards2/2800 and4/468; its only child
sections areDemands andRewardsEtc. There is no explicitAcceptAction or
CompleteAction child in that record. This is resource absence only, not proof
that acceptance/UI/post-battle processing is unnecessary. Native record defaults
and all runtime producers still need qualification.

Next: close the NPC callback/intent and authoritative Quest15 scheduling, then
ordinary Town1 controller/legal spawn. No new Host deployed or game test requested.
Normative pin and approval/FULL-PASS statuses unchanged.
