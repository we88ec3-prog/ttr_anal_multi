# Resource lifecycle and actor removal — independent semantic review

Reviewer: Codex T01 / review_t08_new; date: 2026-10-29 Asia/Taipei.
Target: original KR `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12,472,320 bytes.
Only offline reads were performed. These decisions concern stated normal-return paths with valid object/container invariants. Exceptions, concurrent mutation, arbitrary corrupt containers and unknown dynamic overrides are not certified.

## Evidence interpretation

`target.json` records PE mappings. `source-assembly-audit.json` records every quoted assembly byte span in the 31 source versions (5,401 statements, zero byte mismatches). Byte agreement is only a consistency check: four sources contain semantic/address/type errors despite matching quoted byte spans. `native-cfg/*.json` contains independently decoded instructions and reachable branch edges from actual function entries. `entry-provenance.json` binds entries to the previously saved Ghidra index. `direct-e8-candidates.json` independently enumerates raw E8 candidates; it does not claim complete CFG callers. `imports.json` binds IAT slots to names from the PE import directory.

The exploratory windows `0x7F6F90` and `0x7B80E0` were rejected as function entries. Their containing functions are `0x7F6F50` and `0x7B8090`; only the latter complete CFGs support verdicts. No source verdict is inferred automatically from the mechanical checks.

<a id="s1"></a>

## S1 — nested payload precleanup and container destruction

At `0x7BE0F0`, stack arg `[ebp+8]` is the item. Its pointer range is `[item+4]..[item+8]`. Each range element is dereferenced as a node before the payload null test; a null node is not guarded. A non-null `node+8` payload receives vtable `+8` (`0x7BE114`), is reloaded from `node+8`, and if still non-null receives vtable `+0` with stack argument 1 (`0x7BE123`); the slot is then zeroed at `0x7BE125`. The range end is captured before traversal. On normal completion `[item+0x74]=0` at `0x7BE138`.

At `0x7BD850`, EDI is the item. Every non-null DWORD in `[item+4]..[item+8]` is passed to `0x89120C` and zeroed. The zero-length `0x8912F0` call follows `eax=ecx; eax-=ecx` at `0x7BD886/88`. The backing storage at item+4 is conditionally freed, and fields +4/+8/+C are zeroed. The payloads are not identified as actors by these functions.

`0x89120C` tail-jumps to `0x8920FC`, which tests pointer null, pushes pointer/0/process-heap and calls IAT `0xBD2210 = KERNEL32!HeapFree`. This independently supports the limited deallocation description. It does not prove each virtual callback's full resource ownership or success.

<a id="s2"></a>

## S2 — deferred insertion, drain, and signed mode gate

`0x7DD1A0` receives owner at stack +8 and item at stack +C, returns with `ret 8`. Signed `cmp [owner+44],1; jl` selects immediate destruction versus enqueue. The enqueue branch calls IAT `0xBD224C = EnterCriticalSection` on owner+64, passes EDI=&owner+7C and EAX=&stack item to `0x7BB350`, then calls `0xBD2248 = LeaveCriticalSection` on the same address. The immediate branch tests item null before `0x7BD850` followed by `0x89120C`.

`0x7BB350` is a DWORD-vector append helper: base+0 begin, +4 end, +8 capacity. It distinguishes source pointer inside versus outside the current storage. For an aliased source, it saves the element index before optional `0x797930` growth and reloads from the new begin. For a non-aliased source, it preserves the source pointer. It writes the DWORD at end when end is non-null and advances end by four. Growth correctness, allocator failure and exception unwinding are separate claims, not certified by the append summary.

`0x7DD1F0` uses ESI as owner, acquires owner+64, reads `[owner+7C]..[owner+80]`, and passes each slot's VALUE to `0x7BE0F0` before checking that slot for null. Non-null values then reach `0x7BD850`, `0x89120C`, and slot zeroing. The limit is re-read each iteration. It has no pre-call null guard before `0x7BE0F0`; valid queued items are a precondition. At tail, `mov eax,ecx; sub eax,ecx` proves the `0x8912F0` length is zero, and the stored end becomes begin. The same critical section is released on the normal path. This does not establish exception safety or exclusion of all producers.

The two raw E8 sites targeting drain are `0x7B8045` and `0x7DD132`; indirect/tail/external calls are outside this enumeration.

<a id="s3"></a>

## S3 — mode enable/disable and manager count

`0x7B7FD0` first traverses the collection addressed through `[container]` and invokes each node+24 payload's vtable+4. It then traverses the collection whose sentinel is `[container+8]`, writing constant 1 to payload+44. ECX is set to 1 at `0x7B7FFE` and is not altered by the second loop. Both exits set container+30 to 1. Thus T08-173's assertion that this value depends on incoming caller ECX is false; T08-177 explicitly corrects it.

`0x7B8030` traverses the second collection first: ESI=node+24, drain, then ESI+44=0. It then traverses the first collection invoking vtable+8, and sets container+30=0. The order is drain-before-gate-zero, not a proof of concurrent mode shutdown safety. Callers `0x7AAD40` and `0x7AB020` pass literal address `0xFE173C` through `push`, not the slot's contents.

`0x7DD100` copies ECX to ESI, performs non-atomic decrement on +5C through `add -1`, and only the zero-result branch calls drain, clears +44, then traverses the separate +4C/+50 DWORD array, passing each value in EDX and `[0xFE173C]` in ECX to `0x7DC510`. It returns the count reloaded from +5C. At `0x7B8090`, the caller returns without destroying payload if that result is nonzero; zero permits `0x7DCF40`, heap free, then index-node removal. This is a local release protocol, not proof that +5C is the unique lifetime counter.

<a id="s4"></a>

## S4 — acquire/reuse, wrapper, and counter separation

`0x7DCFB0` increments owner+60 before locking +64. Nonempty +7C/+80 storage supplies its last DWORD to `0x7BE5B0`; end is then reduced by four, the lock released, and the item returned. Empty storage unlocks first, requests 0x7C bytes, conditionally constructs via `0x7BD7E0`, and builds 0x0C nodes corresponding to owner+4C/+50. The mode +44 gate reaches `0x7BDF90` only in this new-allocation branch. The native code has additional failure hazards; pseudocode with an `if (r)` is not adopted as a claim about native null handling.

`0x7BE5B0` zeros item+1C (float zero) and +6C, then invokes each existing node+8 payload's vtable+24. It is a local prepare/reset path, not full reinitialization of every byte.

`0x7BE5F0` receives a pointer SLOT in ESI, obtains resource=*slot, then owner=*resource, decrements owner+60, and chooses deferred/immediate handling using resource+74/+78. It ultimately zeroes the original slot on successful normal paths. This +60 is distinct from owner+5C. The static pair of inc/dec does not prove error-path balance or atomicity.

The actual wrapper function is `0x7F6F50`. It calls `0x7B8180` for the manager, executes `push 0x30` at **0x7F6FBF**, saves EAX manager in EDI at **0x7F6FC1**, and calls allocation at 0x7F6FC3. If the wrapper pointer is null, branch 0x7F7021 returns zero without calling acquire; otherwise it calls acquire at 0x7F6FDC, writes vptr 0xC511CC, and stores the returned resource at wrapper+2C. T08-187's exact instruction-address assertion is wrong even though the overall allocation size is correct.

<a id="s5"></a>

## S5 — name index, callbacks and container identity

`0x7DC510` saves EDX key and ECX index, creates the temporary string, calls `0x7B86F0`, compares the returned node against index+4 sentinel, and only for a non-sentinel obtains node+24 payload. It invokes vtable+C with ECX=payload. Return zero gates a vtable+0 call with stack argument 1, followed by `0x7B8680` index erase. Nonzero callback skips erase. The callback implementations remain unresolved.

`0x7B86F0` and `0x7B8680` use `0x5525E0` to hash a string, AND the result with owner+20, conditionally fold it using owner+24, then address an 8-byte bucket pair from owner+10. Lookup compares strings within the bucket range; erase repairs bucket bounds and calls `0x719B20`. That helper unlinks a doubly linked node, conditionally frees the string storage, frees the node, and decrements the list count. This is hash-bucket/list structure evidence, **not an ordered-tree erase**. T08-183's affirmative tree description requires correction; its release ordering can remain a separately verified bounded claim.

`0x719B90` allocates a 0x28 node with two links +0/+4, string value at +8, and copies the supplied payload from argument+1C to node+24. `0x7B82D0` calls `0x7B86F0` with EAX=&container+4, allocates the node via `0x719B90`, links it around the sentinel at container+8, and invokes `0x7D1080` for bucket integration. Container+8 here is the sentinel field of the embedded index at container+4; it is not evidence of a separate ordered actor tree.

`0x7B7DA0` allocates the first heap index and stores it in 0xFE173C; it also initializes the embedded second index at 0xFE1740 with a 0x28 two-link sentinel and the same bucket initializer `0x7DCC30(8)` used by heap-index constructor `0x7DC3D0`. The global slot and embedded index remain different objects even though they share a helper/layout. This does not reclassify the separate actor registry's red-black-tree structures.

<a id="s6"></a>

## S6 — manager cleanup ordering

`0x7DCF40` uses EDI, frees/zeros non-null entries from +4C/+50, conditionally frees the buffer at +7C and zeros +7C/+80/+84, calls IAT 0xBD2228 (`DeleteCriticalSection`) on +64, then conditionally frees +4C storage and zeros +4C/+50/+54. No loop over the +7C buffer's individual resources occurs in this destructor; prior drain/lifetime assumptions are not invented. Direct calls from `0x7B7F30` and `0x7B8090` provide EDI as the manager payload.

<a id="s7"></a>

## S7 — actor main tree, secondary tree and conditional removal

`0x4DFBC0` searches owner+8 using exact find `0x82EF00` (the lower-bound candidate is checked for equality at its tail), compares owner+C sentinel, clears three controller slots through vtable+1C, then actor+14, reloaded actor+0(1), node+10=0, and `0x7B6890` erase. The first actor+14 dereference is not guarded for null.

`0x4DFC30` instead receives owner in ESI, searches owner+18 using `0x8438C0`, compares owner+1C sentinel, conditionally clears owner+F8 if its first DWORD matches the key, directly frees non-null node+10 payload and erases the node. It has no actor virtual +14/+0 calls.

`0x4DFC90` receives owner in EAX and computes **EDI=&owner+8** at 0x4DFC96. It traverses that SAME main tree, compares actor+88 against the DWORD stack parameter, and only matching entries receive precleanup/deleting calls, zero payload and erase. The next iterator is read from the helper's returned output pointer; nonmatching nodes follow the in-order successor branches. T08-196's second-tree +18/1C attribution and associated double-tree ownership discussion are based on a wrong premise. T08-197's later source correctly identifies the +8 traversal.

`0x4DFD40` compares a zero-extended BYTE actor+4 to the WORD parameter. On match, low AL kind values 0,1,6,7 gate an additional actor+15C / actor+370 processing path; these values do not restrict the final virtual deletion, which follows the shared match path. These are local predicates, not official gameplay categories. No official meaning is assigned to +88 or the byte key.

<a id="s8"></a>

## S8 — full clear and concrete vtable case

`0x4DFE90` receives owner on the stack, iterates owner+C sentinel/main tree, and for non-null actor calls +14 then +0(1), without individual `0x7B6890` calls. It then calls `0x823850` once on owner+8 and invokes the separate global `[0xFBA7A4]` object's +14 callback. This last callback is not the actor's callback.

Constructor `0x4D1710` writes main vptr 0xC0C9DC at 0x4D1749 and secondary vptr 0xC0CA64 at object+F0. The .rdata main-table slots +0 and +14 are 0x4D18D0 and 0x4D1F80. For this exact vptr case, +14 calls `0x4C8360` then returns zero; +0 resets the vptrs, calls `0x4C7B90`, and conditionally heap-frees the same actor when argument bit0 is set. No other actor dynamic class is silently mapped to these targets.

`0x4C8360` first tests actor+15C and invokes the secondary interface at child+8, slot+8, with ECX=child+8. It then conditionally calls `0x7BE5F0` on the ADDRESS of item+24 for actor+364 and a 128-entry pointer array starting actor+164. These pointer array slots are not themselves all zeroed here; only the referenced resource slots may be zeroed by release. Unknown child vptr/callback behavior stays unknown.

<a id="s9"></a>

## S9 — registration key and duplicate boundary

`0x4DFF30` normalizes actor+4 WORD to a DWORD search key; `0x82EF00` returns an exact matching node or sentinel, because its lower-bound search is followed by unsigned key validation. Only sentinel leads to `0x82F200` insertion; duplicate enters the local message call `0x6EDB60`. No replacement allocation or actor-free call is in that duplicate branch. Upstream responsibility for a duplicate actor is not established. This supports T08-200 and does not inherit the old T01 lower-bound-only mistake.

## Limits kept separate

Client unknown: concrete remaining virtual targets, complete object provenance, all writers/aliasing paths, exception behavior, external modules and real packet/event timing.
Server development: official spawning policy, wave timing, authority and gameplay decisions are not inferred from these resource/container facts.
Integration/play testing: no target execution or end-to-end gameplay acceptance occurred.
