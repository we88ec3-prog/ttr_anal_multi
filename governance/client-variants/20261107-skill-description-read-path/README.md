# Skill description direct read paths: v7 proposal

Original BIN and v6 have the same two explicit reader literals and identical bounded consumer instruction bytes:

| Literal / length | File offset | String VA | Consumer start / reference instruction | Equal-length proposed path |
|---|---|---|---|---|
|Table/SkillExplainTable.xml /27|0x80D5EC|0xC0EFEC|0x52FC50 /0x52FC88|TC_UI/SkillExplainText7.xml|
|Table/PracticeExplainTable.xml /30|0x80D3EC|0xC0EDEC|0x529D50 /0x529D88|TC_UI/PracticeDescription7.xml|

Both load the literal into ECX, call0x72EE30 and then0x72F110. Static read-path evidence is exact; runtime file/cache precedence remains a hypothesis until retest. Separate direct XML paths follow the successful v6 NPC approach without changing PE layout or gameplay logic.

The approved v5 Table archive already contains Chinese skill descriptions and Talent text. Proposed unmodified extraction identities:

-Table/skillexplaintable.xml: SKILLEXPLAINTABLE,203868bytes, SHA2560ab7aa30d5fa59b691732c27f1dfe20a5eb5e02c1bed2eb685a4dd6f37e5a70a.
-Table/PracticeExplainTable.xml: PRACTICEEXPLAIN,284550bytes, SHA25634c6f174d1b37c99573d079a3f312ea805f0735c052cef3c66023c99bfc5db33.

These hashes are the old approved payloads, not a claim that a future text-repaired v7 XML has the same hash. Original TC payload identities and original KR identities are recorded separately in proposal.json.

Coverage caveat: v5 has one Hangul Skill row243 and13 Practice rows146,148,152,181,199..207. The latter nine describe each role's advanced-skill switch and matter to the Tab-related request. All14 have same-ID Chinese TC entries; child counts agree, but a builder must verify complete IDs/attributes/shape and apply only names/text, preserving KR structure. The reason the old merger retained these rows was not established here. Do not declare every Talent description translated by simply copying v5 unchanged.

Matrix columns7/8/10 identify36 distinct special active IDs across nine roles; all have Chinese descriptions in v5. Isilia67/68/69 explain V charge stages and2544 says advanced skill switch. This audit does not newly prove physical key dispatch from the column numbers. OnScreenKeyTable is byte-identical across KR/TC/v5 and is not the skill-description translation source.

Reproduce with audit_read_paths.py. It emits metadata, bounded disassembly text and residual TC matches only. No XML companion, EXE, Server or Git change is performed. Original resources are read-only; no game launch/attach or new provider request occurs. Human retest must cover ordinary skill tooltip, Talent description, Tab/advanced switch and V explanations, alongside previously passed rendering/nameplate behavior.
