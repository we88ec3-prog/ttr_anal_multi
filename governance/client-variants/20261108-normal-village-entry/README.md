# Normal village entry: local eligibility and named party-create producer

2026-11-08. Read-only source work for original KR SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91. No Client execution/attachment/provider retry, resource change, Server restart or shared edits.

## Exact observed source chain

CCreatePartyDialog vtable C37A3C, constructor68C480, event slot15C=68C750. Confirm control click event578 enters68C790. It sends C2S0053 (50B) via53B900 if no existing party, then005E/0060 for checkbox branch. Travel launch context2 emits UI eventF4390, delivered by5B7F80 to5B6250. Thus a party-create request may have already reached the Server before the local village eligibility popup.

5B6250 reads selectedtown from page+24C->20C. Its4E2E70 preflight reads CGlobalStatus town eligibility DWORD vector+68FC..6900 and CTownInfoTable TYPE1; there is no role/expedition level comparison in this helper. A false result produces CommonMessages6/kNotEnoughLevel ('진입 가능 레벨이 아닙니다.'). This message does not identify a real level threshold.

S2C007E appends DWORD masks to the eligibility vector; S2C0080 ORs one town bit, with native word index town>>5 and bit index(town-1)&31. For Town1 the state-idempotent single publication is800001. Do not use007E as a reset/replacement or unlock unearned future towns.

A passing normal preflight sends C2S003D + selectedtownBYTE (3B, slot0) through4A3620. Existing one-member party skips multi-member confirmation and retains this normal path.

## Party publication boundary

Native S2C008E/008F consumers are recorded separately.008E has party-keyWORD at+2F (raw ABI recovers AX), name21WCHAR at+2, BYTE+2C->record20 and WORD+2D->record24. BYTE+2C is a capacity candidate, not proven town.008F has party key+2, clear flagDWORD+4 and nine-byte member rows+8. A local-user row with flag4 establishes current-party pointer via53B750 and emitsF4404; flag2 sets member leader property.

No assumption that reply=request+1 is permitted: S2C0053..58 dispatch to TradeMgr.0088/0089 clear party data; they are not generic success replies. The exact minimal complete positive room-publication sequence remains a candidate requiring Server review and Client testing. No additional lobby scene is inferred merely from terminology.

## Files

- preflight-publication.json: source identities, data members, exact ABI, eligibility/message/request windows.
- create-party-producer.json: named RTTI UI, confirm path,50B C2S0053 layout and order.
- party-publication-candidates.json: typed008E/008F consumers and explicitly incomplete reply semantics.

Original XML/member payloads are not copied into this package. Metadata is local and not a formal RR claim or T01 FULL-PASS.

Snapshot caveat: the earlier party-publication-candidates.json preflight_note/unknown create-producer wording predates create-party-producer.json. The latter closes the named-create producer; positive reply field semantics/order remain open. This package is source evidence, not T01 FULL-PASS or tested Server compatibility.

## Consumer follow-up

party-ui-consumers.json closes capacity via the native modify-dialog combo ABI, member role/level and the non-Duel constructor-neutral tag boundary. roster-local-identity.json additionally verifies the existing0002 roster producer writes F93930 at4B803F/4B8042; no extra opaque002A bootstrap is required. 005E/0060 to008A/008B remains an explicit Server policy candidate. Source identities/windows were checked against pinned originals; this is not a complete function/native acceptance verdict.
