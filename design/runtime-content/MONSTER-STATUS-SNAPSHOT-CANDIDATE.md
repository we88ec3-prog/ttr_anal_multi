# Monster status snapshot candidate

Known monster constructor4D1710 passes its same object pointer to common actor
constructor4C7070 before installing the monster vtable. Independently checked
success-path prefix initializes +3F4 sentinel/+3F8 and +400/+404/+408, agreeing with
the previously reviewed0077 per-included-actor replacement receiver at4D2E40.
The receiver looks up actorUID and has no established player-only class filter.
This is bounded consumer compatibility evidence, not official publication rules.

New boundary `monster-buff-inheritance-boundary-v1.json`, SHA256
`df4226e5cf11ede217a4f8c716da9e66f1ff3ddd611a0adcab579eb14b44b345`,
includes original-byte prefix windows, bulk source hashes, companion receiver/
writer pins and exact original/work equality for three _BuffList EFF members:
12 holding,28 frostbite,39 weak stun. No new raw resources are redistributed.
This does not close referenced geometry, actual rendering, map lookup folder or
visual cleanup scheduling, and does not claim whole-function/Task FULL-PASS.

Server lab policy: separate monster emitter accepts only nonzero type1 IDs
(low byte1), those three reviewed Buff IDs and levels1..5, maximum3 unique entries.
Owner defence emitter remains unchanged. Emit the COMPLETE current set for each
included monster when ID/level set changes, including count0 when the last effect
expires, damage breaks weak stun or monster dies. Include surviving statuses when
another expires; do not emit incremental subsets. Other actors are not cleared.
New actors start with an empty constructor map, so no initial empty snapshot is
needed. Reapplying an unchanged ID/level refreshes Server time without restarting
the visual snapshot. Parameters/root/stun mechanics remain the existing lab rules.

Wire candidate: command0077,actorCount1,WORD entity,BYTE count,then sorted four-byte
records WORD BuffID,BYTE level,BYTE0. Last byte is opaque; zero is a lab choice,
not seconds or duration. Server owns timers and proc/level policy. Candidate is
restricted to isolated skill lab; no quest/normal tutorial or raw-preview grants.
No automatic Client AI, collision/damage authority, new opcode or native MEF.

Verify ordinary positive application, overlap and partial expiry, last expiry,
weak-stun damage break, death cleanup and nine-role preview isolation with the
authorized HappyPath category. Actual Client rendering/cleanup remains PENDING.
