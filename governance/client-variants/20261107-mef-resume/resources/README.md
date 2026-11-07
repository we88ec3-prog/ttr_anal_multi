# MEF resource resume: bounded identity audit

This resumes prior evidence rather than rescanning package payloads. It checks only the three authorized roots and the previously listed42 KR carriers for original/working, plus56 TC carriers.140 carrier instances were hashed:139 identical carriers reuse old MEF index results; only original/Table.stp differs from the old working carrier hash and its STPI index was reread. Its decoded _MapList member remains identical to the retained KR hash.

No MEF-named member was found in those indexes, and no exact .mef loose file was found beneath the three roots. This is bounded not-found, not proof that every Client, embedded payload, alternate name, other version or official Server lacks MEF. Reparse subtrees are skipped. No package payload corpus scan was performed.

All three current table identities retain these exact references:

| Map ID | TRIGGER | MAP | BOUND |
|---|---|---|---|
|182|town001.mef|town001D|town001|
|188|town000.mef|town000D|town000|
|190|scenario_town000.mef|town000D|scenario_town000|
|191|S_pathofpindus01.mef|scenario_pathofpindus01D|scenario_pathofpindus01|
|192|S_pathofpindus02.mef|scenario_pathofpindus02D|scenario_pathofpindus02|

Exact-case and casefold basename checks for these names have no archive hits in the bounded inventory. A TRIGGER filename is a reference, not a MEF sample, format definition or executable server script.

`domain-separation.json` reuses74 retained town001/town002 EMF metadata references, all backed by an unchanged current Map/Object/MapEffect.stp carrier. Those .emf resources are distinct from .mef names. No renaming, light-to-script conversion or monster behavior inference is justified. The narrow carrier inventory has no Light-named carrier; it does not inventory all internal lighting resources and cannot prove that domain absent.

Reproduce: run `audit_resources.py`, then `project_retained_domains.py`. `resource-audit.json` records prior evidence hashes, current carrier hashes, reindex decisions, target matches, current table member proof and loose walk coverage. Only metadata is output; no raw archive member bytes are exported or published.

No executable launch/attachment, resource rename/write, Client/Server change or Git action occurred. Without a sample or a proven receiver/parser bridge this resource audit cannot define MEF wire format or propose a faithful interpreter.
