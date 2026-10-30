# S00 cross-layer analysis — RR-0003 + RR-0006/0007 AUTH receiver proof chain

Date: 2026-10-30 Asia/Taipei. Scope: **KR Client bounded static flow**, not a recorded original Server transaction. This is a new cross-report reasoning aid, not another source claim or Native verification.

## 1. Exact original sources already merged to main

| Origin | Bounded contribution | Identity / integrity |
| --- | --- | --- |
| T03 RR-0003 primary | E8/000F mode, 0x13 handler fields and 0x7A group cursor | SRC-0473, `CLM-AUTH-0003..0005`, blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17` |
| T03 E69 supplement | E8 tail six bytes: no direct init writer; FBA808 initial virtual-zero vs outgoing E8 CP_ACP | SRC-0482, `CLM-AUTH-0006`, blob `98546ce73206e2b8f6fede78d83923af7a76cf5b` |
| T02 E59 RR-0006 | 0x2633 decode, checksum failures, parser/pool delivery gates | SRC-0471, `CLM-NET-0026..0028`, blob `c7c1474b6b3cf928b8031e17fad7761c488d9b18` |
| T02 E60 RR-0007 | lane2 first-/second-layer app dispatcher, active LOGIN 0x13/0x7A | SRC-0472, `CLM-NET-0029..0031`, blob `2ca02f3870d79d3217abf39b8651c43226eb77d6` |
| T02 E56 RR-0005 | key1 local send/Connect; key0+key2 selection/recv and UI guards | SRC-0451, `CLM-NET-0018..0020`, bounded S00 RR-0005 ACCEPTED |

All referenced CLM are source-scoped PARTIAL; no full original Client execution took place here.

## 2. Native conditional chain, not an asserted observed network sequence

### Inbound **S2C** (requires all relevant gates)

~~~text
WSARecv/IOCP completion (T02)
  └─ 0x807B40 parses a frame
       ├─ malformed length (0 or > 0x1000): parser0 / distinct IOCP path
       ├─ incomplete: retain/compact (not delivered yet)
       ├─ 0x0BBB wrong checksum: no successful application copy → zero-length node recycle
       ├─ 0x2633 inflate error: no successful application copy → zero-length node recycle
       └─ valid decoded >0 application payload
            → Conn+A080 lane / 0x489920 → 0x8040A0 queue
            → 0x804740 → 0x4930E0
               └─ only relevant **lane==2** route parses LE16 app opcode
                    ├─ 0x0002 first-level handler (roster 0x4B7F00)
                    └─ first-level default + live scene pointer/table
                         └─ active LOGIN table 0x4C3220
                              ├─ app 0x0013 → 0x4C37A0
                              └─ app 0x007A → 0x4C3C10
~~~

**What this proves:** bounded conditions under which a particular Client handler *could* receive an application command from already decoded data. It does **not** prove the original Server sent 0x0013 after E8, the slot carrying that frame, or the actual original Server frame marker/response order. App `0x13`/`0x7A` and transport `0x2633`/`0x0BBB` are separate namespaces.

### Handler-local postconditions are also conditional

- `0x0013`: can process optional notice `+0x20` **before status**. `status=5` special error; other nonzero/empty UTF16 name error; `status=0` plus nonempty name at `+2` local success → group count at `+0x1C`, group cursor `+0x92` via `0x4C3080`. `+0x90==0` is additionally needed for local F4241 through `0x4C3170`.
- `0x007A`: independently reads group count `+2`, cursor `+6`, calls shared `0x4C3080`; group count0 still reaches local F4243 notification. Distinct layout; cannot substitute for `0x0013` packet.
- Shared groups consume header 3B + child rows 10B. Child+4..7 → IPv4 text; child+8 controls append, child+9 is used, filtered-out rows still advance. Its local loop lacks an observed per-child remaining-length check. A **Server engineering** checked encoder/decoder may require more validation than the Client visibly performs.
- Conditional status0 and F4241 merely make a later **local UI** action possible; UI/record/endpoint mapping gates at `0x66C090` can lead to key0/key2 `0x4957C0` Connect. T02 E56 confirms bounded local paths; it does not show `0x0013` always causes immediate socket switch.

### Outbound **C2S** is an independent producer

Client mode `0x52` creates E8 112-byte application payload; mode `0x54` and other cases 000F 214-byte local payload. Both use manager vtable+0x10, connection key1. No existing source proves that **this concrete C2S** is the causally paired request for the observed LOGIN-scene `0x13` handler or which decoded S2C frame follows it first. Six E8 bytes `+104..109` remain opaque/locally unwritten, not zero-by-policy.

## 3. Conformance tests versus native evidence

The new `TEST-AUTH-0002` is registered as **OFFLINE_SYNTHETIC**. Its hand-written fixture independently checks only:

| Property in fixture model | Static source basis | Claims not made |
| --- | --- | --- |
| group/child consumes `3 + 10*n` bytes | `CLM-AUTH-0005` | authentic Server payload bytes |
| `0x0013` group cursor extent `0x92 + sum(groups)` | `CLM-AUTH-0004/0005` | original Client branch safety or full valid S2C minimum length |
| `0x007A` cursor extent `6 + sum(groups)` | `CLM-AUTH-0004/0005` | `0x7A` follows `0x13` in a real session |
| child+8 filter never prevents cursor advancing; +9 propagated | `CLM-AUTH-0005`, report native path | official child field semantics |
| parser raises on truncated synthetic record | **new conservative test policy**, not native behavior | original Client rejects malformed payload with a controlled exception |

All example addresses are documentation/test-only IPs, not discovered original Server endpoints.

## 4. Still-open causal edges and exact evidence required

| Missing edge | Source of uncertainty | Needed for a usable Server contract |
| --- | --- | --- |
| `E8/000F` → actual first Server S2C | Only local builder and conditional handlers registered | Authorized authenticated trace or other exact server-origin evidence with version, socket and opcode |
| transport marker/Conn+A02C → emitted `0x13` / `0x7A` | Receiver accepts multiple marker pathways; send fallback depends on local mode | Actual valid packet capture or complete original-origin send provenance |
| decoded app `0x13` → LOGIN scene / status0 valid payload | Handler exists only when scene table is active; no proof a real Server sends it in every state | Proven scene lifetime, full length bounds, valid payload field semantics and status conditions |
| `F4241` → key0/key2 Connect → first new S2C | UI gating and user selection are separate | Explicit bounded runtime / original source chain for same user/session across connection keys |
| selection C2S `0x42` → accepted S2C / scene state | T03 RR-0002 BLOCKED, RR-0008 source paths distinguish scene resources from wire | Exact direction-specific S2C success/error handler and branch, not 0x43-by-increment guess |

## 5. Decision and handoff

No RR was created, claimed, submitted, reviewed or promoted in this iteration. `RR-0003/0006/0007` remain `IN_REVIEW`, `RR-0005` remains scoped `ACCEPTED`, `RR-0002` remains `BLOCKED`. All seven GAP and SPEC maturity states unchanged. The source-scoped [AUTH contract](../../spec/session-account/SPEC-AUTH-0001.md) and [receive spec](../../spec/protocol/SPEC-NET-0003.md) remain separate components of a not-yet-closed B-AUTH/B-NET vertical slice.

Next human review should check RR3's acceptance clauses, E69 source correction and T01 independent native cross-check; if a bounded RR decision is approved, use canonical dispatch and review ledger atomically. No static conditional path or synthetic test is permission to operate an original Client, connect to an official Server or claim playable backend compatibility.
