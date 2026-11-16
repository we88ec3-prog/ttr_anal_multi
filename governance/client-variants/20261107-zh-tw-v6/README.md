# zh-TW v6 — direct NPC nameplate reader paths (2026-11-07)

The user now authorizes translation companion additions/changes without repeated
confirmation, requiring explanation after completion and preservation of originals.
This supersedes the prior approval rule for translation only. It does not permit
unrelated gameplay/system changes. User also requires continuing independent work
while manual tests are pending; policy is persisted in workspace/repository AGENTS.

## Delivery

Three new local files in E:/Tartaros/workspace:

- Tartaros.ip-zh-tw-v6.exe
- TC_UI/ActorName6.xml
- TC_UI/NpcName6.xml

The two XMLs are byte-identical extractions from the approved v5 Table actor/NPC
members. They introduce no additional text or gameplay values. EXE uses equal-
length literal replacements at0x80BA40 and0x80D1E4 to force the direct readers to
these paths, preserving code/PE layout, v5 archive path, v4 font path and age patch.
Existing Table.story-zh-tw-v5.stp and UI/Fnt4.stp/v4jh*.ttf remain dependencies.
Old versions and original files remain unchanged; normal root launch, no CMD.
Raw EXE/XML/font/archive payloads remain local, not in Git.

EXE SHA2563b1605c2d231704f9e0fefc7bc27a45e9b5759d71e94e944736adb4481053148.
Actor XML SHA2568ae9812a1a5bb171ed0304d8ee02193433e0401975e6c7af6374866f2ba02df0.
NPC XML SHA256aba6331722139803902175cb6d5d83e0705b1a6916f1504f9007bb0c6e579e65.

## Evidence and checks

Read path investigation and bounded instruction/source identities:
../20261107-nameplate-read-path/README.md. v5 table text was correct on disk but
human nameplate result failed. v6 changes the actual direct XML path literals,
not merely the temporary archive prefix. Precise runtime cache-order hypothesis
remains unobserved and is not promoted to FULL-PASS.

Independent static check: expected two literal replacements only (24 actual byte
differences vs v5); size/PE headers unchanged; bothXMLs exact decoded-member copies;
NPC10338 Chinese name/title confirmed;84 existing immutable files hash unchanged.
No game execution/attachment. Previous untranslated/unproven rows and105 legacy
NPC codepoints outside current font subset remain unchanged, not claimed covered.

Human status:PENDING. Test card sent for NPC overhead name/title, scene/dialogue,
and optionally report the already-running v29 cooldown test. v5 rejection remains
historical failure; neither static checks nor test-card delivery imply v6 passed.

## Independent work after sending the card

Located the left-side chat help in Table/Messages/SystemMessages.xml keys
kChatHint_1..5, not in the narrow UI font/string archive items searched first.
The Taiwan source has matching keys and Chinese descriptions, but its slash
commands differ from KR (e.g. Taiwan /w,/p,/g,/u vs KR language/keyboard aliases).
Do not blindly copy the Taiwan help and advertise commands the KR parser may not
accept. No chat resource/command behavior was changed by v6. Further bounded
consumer/command-alias review is needed before a safe descriptive translation.
The five-key discovery is source-only; original raw message content stays local.
