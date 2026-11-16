# v29 cooldown delta deployment — 2026-11-07

User explicitly requested fixing the resource-recovery cooldown sweep restart,
and asked whether a newer translation test build exists. Translation answer:
no new build beyond rejected v5; no Client modification accompanies v29.

Server main1a301924d09e1ecf7eaa95a0e97f10989825c999 deployed after59 authorized
Category=HappyPath tests passed (0failed/skipped,59s), Release publish succeeded.
Initial test compile had a missing helper reference, corrected before that run.
No deferred suite rerun. No normative spec/ADR admission changed.

Only resource values are sent for resource recovery/rejected casts. New admitted
skill and expired skills use reset-free012A rows limited to those changed keys;
unchanged active timer total/remaining are not republished. Full initialization
still uses the existing context reset/list. Server deadlines, costs, regen rates,
combos and movement recovery unchanged. Two new normal tests check recovery
within20-second cooldown and independent20/30-second timers with selective expiry.
Human icon rendering remains PENDING_USER.

Before replacing exact v28 Host PID34824/path, verified ownership and loopback
listeners, then created a consistent new isolated account backup. Activated v29
at2026-11-07T06:42:18.2294123+00:00, PID30132, with auth/journey/story healthy.
Host DLL SHA1903F2EA6349939CA8C29A049A6C7FD592254DA4D9325EAA9AB364C9FD3268E7;
Network DLL SHAB0FE568EB6DB82298662BD24023D34BBB58AC50452CD0DE66814FB0F9BAD47B9.
Story content unchanged59a0e6221e76171ef9618b787dbf25c6ba0db61180866458317025916ef35678.

Local receipt:runtime-observations/2026-11-05-controls-npc/host-v29-process-receipt.json.
No unrelated process terminated, no game input/attachment. Current v5 may be reused
for cooldown test despite overhead-name translation still rejected.

Suggested normal manual test:empty IsiliaSkills lab, Z+X once then after its action
ends X+C once; watch both20/30-second cooldowns across10-second resource ticks and
the shorter timer's expiry. No full sweep restart on resource refresh, second
cast or neighbor expiry. Observe resource change separately from cooldown readiness.
This simple check does not promise to recreate a resource-shortage boundary in the
1000-cap lab; repeat the user's existing shortage sequence separately if needed.
