# zh-TW v7 — direct skill / Practice tooltip readers

User-authorized translation only. Created three new files in the original game directory; no launch, attachment, OS configuration, original-resource rewrite, or Git commit.

## Outputs and inherited dependencies

- `Tartaros.ip-zh-tw-v7.exe`, SHA256 `937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec`.
- `TC_UI/SkillExplainText7.xml`, SHA256 `c0b340d0c52257a08fd759d14fb7e8711fb78ca2e520ac384508875edba04f03`.
- `TC_UI/PracticeDescription7.xml`, SHA256 `76168490f133b3b32fb6fdd4231bb0b8da05f84afe1d6c1b57c4bd6504e1331e`.

Direct EXE launch from the existing root; no CMD. Existing approved v5 Table overlay, v4 fonts, v6 Actor/NPC XML, original runtime and assets remain dependencies. All old versions remain intact.

## Exact patch scope

Pinned input v6 SHA256 `3b1605c2d231704f9e0fefc7bc27a45e9b5759d71e94e944736adb4481053148`.
Two equal-length literal changes, 23 actual changed bytes:

|File offset|Original path|New path|
|---|---|---|
|0x80D5EC|Table/SkillExplainTable.xml|TC_UI/SkillExplainText7.xml|
|0x80D3EC|Table/PracticeExplainTable.xml|TC_UI/PracticeDescription7.xml|

EXE length12487680, PE headers, all code sections and every byte outside the two literals are unchanged. Existing age/IP/font/NPC fixes are inherited unchanged. This is a bounded direct-reader repair, not a new gameplay patch or full native compatibility verdict.

## XML origin and text-only repairs

Start with exact decoded members from approved `TC_UI/Table.story-zh-tw-v5.stp` (SHA `aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae`). Source Taiwan archive SHA `d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84`.

Repair residual Skill243 and Practice146/148/152/181/199..207 using unique matching IDs and exact child/Level identity/shape. Only display text and thirteen Practice NAME values change; every ID, level, other attribute, child shape and unselected row stays equal to v5. All14 rows accepted, zero unsafe rows skipped. The resulting two payloads happen to be byte-identical to the respective Taiwan members; this was checked after bounded text repair, not used as a license to replace gameplay tables.

The9 Practice199..207 phase-transition descriptions are included. Isilia V descriptions67/68/69, active phase descriptions2541..2549 and Practices63/64/193/202 were checked for Chinese/Hangul coverage. Both retained fonts cover all751 required display codepoints; no fonts changed. No displayed Hangul remains in these two tables. Korean XML comments are not rendered text and are not a translation target.

## Verification and limits

`build-manifest.json` preserves per-row original/donor hashes, exact edits, source/output identities, scope checks, PE section comparisons, font coverage and92 existing runtime/resource hashes, all unchanged; source Taiwan archive also unchanged. No raw EXE/XML/font payload goes to Git.

One initial pre-write assertion incorrectly searched XML comments as if they were display strings. It stopped before creating any game outputs. The assertion was narrowed to actual parsed display text/NAME; final scoped checks then passed. No partial game build was overwritten.

Actual tooltips/cache precedence and Tab/V display require user testing. Taiwan descriptions are retained localization text; this Client patch does not establish complete Server skill behavior, reconcile every KR/TC balance difference, or change physical Tab/V dispatch. Nine original Taiwan long-V descriptions retain their existing persistent/repeated-selection wording. Bounded KR input evidence means **keep V held**; the root agent will explain that operation to the user. This wording caveat is recorded in `wording-limitations.json`; no further Client version is requested and this build/output manifest remains preserved.
