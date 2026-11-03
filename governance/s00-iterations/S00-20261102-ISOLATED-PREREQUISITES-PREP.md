# S00: isolated prerequisites candidate preparation

## Purpose and implementation boundary

Prepare a fresh normal tutorial fixture for the prerequisite-publication and
Quest15 intro-control candidates without changing the database used by the
existing game or Admin process. This is a Server-owned development workflow,
not an official Client protocol or game rule. No Client/resource change.

The private LocalDev tool now has an explicit new-database-only initializer.
It reserves a new absolute destination using CreateNew, creates Account schema2
and the expedition/tutorial/journey/quest component1 markers, and exits before
the historical comprehensive self-test. It does not seed accounts, session,
character/role, progress, prerequisite completion, transfers or rewards. This
is distinct from migrating an existing player database or starting a Host.

## Actual checks

- LocalDev Release build: zero warnings/errors.
- One new isolated database initialized successfully.
- Independent read-only SQL: global schema2; four component markers, one row
  each; every non-marker data table empty.
- Host Release publish succeeded into a separate v11 artifact directory.
- No deferred negative/replay/recovery tests, Client operation, live database
  migration, account provisioning or Host replacement were performed.

The previous 26 positive synthetic cases cover the existing source candidates;
this tooling check is not new human/native compatibility evidence. No claim is
made about current external process liveness without a fresh process check.

## Remaining milestone

A fresh account normally reaching the square has human evidence. Quest15 NPC
selection and intro-to-following-scene scheduling, ordinary Town1 controller,
legal player spawn and complete arrival still require implementation/validation.
The prepared v11 artifact is not live. Do not repeat a full user tutorial test
merely because a new database or executable artifact exists; first prepare a
useful test segment and revalidate the exact runtime being replaced.

Sources: S00-20261102-TUTORIAL-PREREQUISITES-PUBLICATION.md,
S00-20261102-QUEST15-INTRO-CONTROL.md, and private implementation documentation.
Original analysis, normative pin and approval states are unchanged.
