# MEF native resume: close the old initializer gap first

2026-11-07. Status: bounded partial analysis; no native MEF reader or network content chain established. Target KR BIN SHA2569741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91.

Scope: reused saved bulk and saved raw instruction audits only. No new REA provider request, Client execution/attachment, original-resource mutation, Client/Server change, Git operation, task-owner edit or broad MEF filename rescan. EMF is not treated as MEF. Source SHA256 identities and exact original raw windows are in source-identities.json/findings.json.

## What changed since the old report

The old2026-10-07 report and2026-11-01 feasibility note deliberately left4DF510's uninitialized4F3D80 helper open. We have now inspected its complete saved pseudocode and the bounded original raw window4F3D80..4F4390. It constructs global lookup containers rooted atFB7470, includingFB74C0/FB74C4/FB74C8. Its normal successful end calls4F4960, which in turn calls10 fixed resource loaders.

4DF510 first testsFB75B0 at4DF547 and, if needed, initializes this same container family before4DF58D calls4F7DF0 onFB74C0. Immediately after the lookup,4DF592 tests the initialization guard again. Whether its second guard skips or invokes4F3D80, the code does not dereference, save or pass the returned trigger string.4DF5B9 overwritesEAX with a local address.4F3D80's incomingEAX is not used as a trigger filename; the function sets its own fixed global state. This narrows the old helper uncertainty: there is no newly revealed trigger-file download/parser entry on this explicit caller-return path.

4F4960 loads ActorList, MapList, MapTitleList, SoundList, BuffList, DamageSounds, an index table, Species and PortalList resources.4F5320 also consults82BB00, whose parsed fields includeType/Speed/EffectFile/GroundTargetingEffect/ImpactEffect/Lifetime/TraceTime/Radius/SplashRadius/Altitude. These resource loader/helper descendants are not exhaustively audited here. Their presence is not a MEF event or AI-script parser proof.

4F7DF0's bounded body remains a map-ID-to-string container subscript: it searches by integer key, inserts an empty string if absent and returns the string field address. The saved full instruction listing ends withLEA of the element's+10 string field. The knownFB74C0 cleanup reference in4F44B0 clears that tree through4F7FE0 and frees the container; it is not a receive-content path.

A targeted lookup of direct4DF510 callers in saved4B/4C/4D/6D sources found4B24F0,4BA8C0,4C15C0 and4C32E0.4B24F0 reads a DWORD map ID frompacket+2, obtains the manager through40F060 and calls4DF510. It does not pass a variable-length content buffer to4DF510 in the inspected body. This is not an exhaustive indirect-call or network-receiver audit.

## What not to repeat

Do not repeat the old42STP filename inventory, the literalFB74C0 pointer scan, or theGB3-to-EMF graphics fallback as if they were new MEF format leads. The three2026-11-01 raw byte windows were rechecked against the original BIN and all matched; their meaning remains bounded and unchanged. The source-only recheck is not T01 FULL-PASS.

Do not implement a fabricated .mef reader or Client blob response. No identified sample, magic, version, compression, record boundaries, opcode, length/chunking, checksum or parser-to-event chain has been established. A scene-loading screen does not establish a MEF download.

## Useful next work

1. Continue from already-saved monster create/movement/action/hit/death message consumers and authoritative Server scenario state. A Server-owned scenario/AI manifest can be implemented with honest provenance; it must not be labeled an officialMEF parser or nativeMEF execution.
2. Acquire or identify a genuineMEF sample and its original producer/consumer before specifying its binary reader. Keep old missing-file evidence as a bounded hypothesis.
3. Resume Client receive-content analysis only from a concrete handler candidate whose length/buffer/decompression/parser/event dependencies can be traced. The4DF510 trigger-name lookup supplies no such candidate.

Remaining unknowns: all aliases, other modules and virtual helper effects; officialServer MEF production/storage; actualMEF format and transmission; whether this Client build ever executes MEF content. This report proves a narrower negative about the explicit old lookup/initializer path, not global absence ofMEF support.
