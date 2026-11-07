# S00 main-only audit and v28 restart — 2026-11-07

## User request and branch history

The user requested starting the local test Server and questioned failed checks on
`codex/s00-combat-priority-20261101`, reiterating main-only development.
The local reflog records creation on 2026-11-01 19:39:16 +08:00 from
`26c6cfcc35b81cabcfc72fb95d50080f06a3954a`. The branch was used by the preceding
S00 work. Its latest remote head is
`4f1a7f38544842609c081a6d2f835d8988fb02e6` (v21 deployment receipt,
2026-11-04 23:01:16 +08:00), so use of the old branch continued after the
main-only policy. This was a workflow error; it must not be described as a newly
created branch today or as fully compliant historical work.

After fetching both refs, origin/main was
`eea8e38eb7c330b2aa3ad514e19a9d7a6b7996cb`; the remote combat branch has zero
unique commits and main has 18 unique commits. Both public analysis and private
Server working directories are on main. No new branch, force push, historical
rewrite, branch deletion or game binary change is part of this repair.

## CI failure and correction

Historical PR #102 run 41511930677 failed seven requirement fixture tests because
new runtime evidence references were missing from the copied fixture. The
subsequent fixture correction is already in main (`18bbf99e4`, integrated via
`60f73fa3e`). This does not account for all subsequent failures.

Latest combat-branch PR run 41853765841 and main push run 41898310093 each failed
`test_no_approved_runtime_discovery_is_invented`: the test expected only
CODE_ANALYSIS and GAME_RUNTIME_OBSERVATION, while the actual lobby requirements
also contain PLAYER_ADMIN_REQUEST. The production registry checks passed.

The test now explicitly expects all three authorized channels, including the
actual PLAYER_ADMIN_REQUEST evidence. It still requires BLOCKED status,
REQ-0001=CANDIDATE and a modified-copy executable identity distinct from the
original target. No requirement approval or native compatibility gate is relaxed.
The historical failed CI records remain historical failures.

## Local test Server

Restarted the existing v28 build from private Server main source
`e3cd883e66c29fa71d0ebe9c211897384f75b87c`. Verified DLL SHA256 values:

- Host: C7584864E437CBAF7FB0548A1768A60689C4E1FFF728134282C864B6494CAD64
- Network: 9D41E7318BFE62554C17AA1D2C95AB9BECF8C2E0794704028F8B5461C72D7E58

Created a fresh consistent isolated test database backup, retaining the existing
backup and source database. Receipt UTC 2026-11-07T05:50:57.8882793+00:00,
PID 34824. Subsequent elevated read-only verification confirmed the exact v28
Host executable and loopback listeners 8414/8415/8416/5082, with auth bound,
journey and story continuation enabled. A non-elevated process query could not
see this Host; the elevated verification resolved that visibility issue. A second
startup attempt stopped at the existing-listener guard and did not launch or
terminate another Host.

Local receipt: runtime-observations/2026-11-05-controls-npc/
host-v28-restart-20261107-process-receipt.json (local-only, not shipped here).
No Server source change or new Client acceptance is claimed. The next human test
first checks whether the previously repaired zh-tw-v3 resource registry permits
reaching the login screen; skill testing remains pending that result.

## Verification

The registry suite passed 306 tests with the initial corrected assertion. After
replacing its derived expectation with an explicit three-channel expectation,
the affected slice suite passed all 12 tests. The Server requirements checker
and git diff whitespace check also passed. These are document/registry checks,
not deferred Server behavior tests or actual Client acceptance.
