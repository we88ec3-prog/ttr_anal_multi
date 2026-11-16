最新：使用者取消翻譯配套逐次確認，已直接製作[v6](../20261107-zh-tw-v6/README.md)並送出測試卡；下列approval pending保留為當時提案歷史。

# NPC overhead-name read path and v6 proposal — 2026-11-07

This continues investigation while the user tests v29. User explicitly requires
ongoing independent work while manual feedback is pending. v4 rendering/dialogue
name pass and v5 overhead-name rejection remain preserved, not reclassified.

## Bounded source and bytes

The existing original bulk source is used with its recorded limitations, not a
new whole-function/native FULL-PASS. Selected instruction ranges were checked
against the known v5 working-copy bytes (source SHA in proposal.json), using
locally installed Capstone in a read-only bounded inspection. No game process
attachment/execution, original-file mutation, MEF hunt, or retry of the previously
rejected REA provider request occurred. The instruction snippets are limited to
four relevant functions; source-identities.json pins the used existing C files.

CNPC draw4D2A80 obtains the actor key at+88, calls4F7A70 with managerFB7470,
selects its UTF16 string at returned+1C (inline or heap by capacity+30), then
passes it to4C9B60 for display. The second overhead line searches managerFE1BD0
and copies the NPC metadata object's wide string at+24 before the same display
helper. Position getter4C8F90 returns actor+A0, not a name; an earlier exploratory
vtable inspection therefore did not establish a name getter.

4F3D80 initializes the actor manager and4F4960 dispatches its loaders.4F49A0
opens the literal Table/_ActorList.xml through714770, reads NAME, converts UTF8
to wide using440130 and stores actor metadata.4F5320 also inserts event-object
metadata using distinct high-key space; merely observing a later writer must
not be misreported as proven overwrite of NPC names.

524850 constructs a TiXmlDocument with the literal Table/NPCTable.xml, parses
NAME/GUILD and converts the stored values through440130.72EE30 copies its
in_ECX filename into the document; its decompiler signature omits that register
argument, so the bounded instruction check matters.

The existing story EXE patch changes only the archive disk-prefix argument in
4A2DA0. That function creates a temporary package manager, setsFBA814 during
its scope, registers logicalTable under the alternate prefix, and clearsFBA814
before destruction/return. It does NOT alter either direct XML path literal.
The whole runtime ordering/first-cache-writer sequence has not been observed;
we do not assert a specific cache-init timestamp from this static evidence.

714770/713910 first attempt package lookup whenFBA814 is active;714C50 matches
logical package prefixes. Missing package lookup can reach714030;713CC0 opens
the explicit path with fopen. The proposed distinct TC_UI XML paths are absent
from the original packaged namespace and use the existing original directory.
This is an evidenced candidate for making these readers consume the intended
translated bytes, not proof that the next runtime result will pass.

## Concrete reviewable proposal (approval pending)

Add three new local files only:

- Tartaros.ip-zh-tw-v6.exe
- TC_UI/ActorName6.xml, extracted exactly from approved v5 Table/_ActorList.xml
- TC_UI/NpcName6.xml, extracted exactly from approved v5 Table/npctable.xml

In a new v5-derived EXE copy, replace the unique NUL-terminated path literals
Table/_ActorList.xml -> TC_UI/ActorName6.xml (20 bytes each), and
Table/NPCTable.xml -> TC_UI/NpcName6.xml (18 bytes each). The string offsets are
0x80BA40 and0x80D1E4. Equal-length edits preserve layout and code. Reuse existing
v5 Table and v4 font paths, without a new archive/font or overwrite. The two
XMLs are exact copies of already-reviewed text-only translated members, not a
new TC gameplay-table substitution. Raw XMLs stay local, not in Git.

Required static checks: exact source/output hashes, unique old literals, full
EXE diff limited to these two path ranges; verify instruction callsites reference
them; v5 resources/EXE unchanged; both XMLs identical to v5 decoded members;
no new font edits. Human check both overhead lines, dialogue and scene rendering.
Unmatched/duplicate source rows and their prior glyph limitations stay disclosed.

User requires confirmation for companion-resource changes; a pending async
question requests approval for precisely these files. No v6 game file exists
at proposal time. Independent analysis and other authorized tasks continue while
that specific approval is pending. This is not an unnecessary second approval
for producing v5; it is a newly identified delivery shape with two loose XMLs.
