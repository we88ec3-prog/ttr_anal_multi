# S00: source-backed scene-start consumer (0x47)

## New bounded evidence

Original KR BIN SHA remains
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`.
The read-only `governance/inspect_scene_start_consumer.py` verified three complete
instruction windows and 11 assertions. Evidence is preserved in
[evidence/S00-20261102-SCENE-START-CONSUMER.json](evidence/S00-20261102-SCENE-START-CONSUMER.json).
No Client execution, modification or network transmission occurred.

QuestMgr registration `5020B0` writes handler `503040` into slot `FAB4DC`
at instruction `50210B`. The existing QuestMgr object base is `FAB2A0`;
dispatcher `4FDA30` loads handler from object+opcode*8+4 (`4FDA3E`).
Therefore `(FAB4DC-FAB2A0-4)/8 = 0x47`; this is not 0x36 or 0x40.
Full initializer window ends after RET at50216B, and full receiver window after
RET0xC at5030BC. Dispatcher window ends after RET at4FDAB0.

Receiver503040 uses MOVSX WORD[payload+4] at503098 and
MOVSX WORD[payload+2] at50309C, pushes argument2 then argument1,
selects scene manager FB73C0 and calls561760 at5030A7.
Saved manager analysis associates its two inputs with the scene resource keys;
this evidence verifies the field reads and call, not every manager helper.
Both fields are sign-extended, unlike the unsigned storage of the C2S3F receipt.

The receiver consumes at least six bytes. This is not proof of upstream exact
frame-length validation or official Server sender implementation. A minimal
source-shaped Quest15/scene2 candidate is `47 00 0f 00 02 00`.
Scene3 and4 examples are likewise supplied as synthetic bytes in the evidence;
none were sent to a game or used as successful runtime evidence.

## Server development use

Private Protocol now has a dormant six-byte scene-start encoder limited to
positive resource keys1..32767. This restriction is an explicit Server candidate
policy; negative native argument semantics remain unknown. It does not accept a
Client-reported key as authority and is not connected to the journey scheduler.
Protocol Release build passed with zero warnings/errors after correcting an
initial C# constant-pattern numeric typing error. No runtime/deferred tests ran.

This removes the unknown receiver-route portion of later Quest15 scheduling.
It does not prove that every3F/15/1/1 must start15/2: that report can originate in
cleanup, and quest availability is different from acceptance. NPC/event intent,
authoritative quest acceptance and the scene2-to3 progression still require
closure. No automatic Quest15 completion, rewards, Town1 spawn or village-entry
claim is introduced. Existing candidate modes and live Host are unchanged.

Next work: establish the NPC interaction event fields and authorized acceptance
path, then connect this receiver only to a Server-owned progression transition.
The normal village controller and legal spawn remain separate prerequisites.
