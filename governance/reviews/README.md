# S00 RR review ledger (Iteration 05)

The sole authoritative RR state remains `research/requests/index.json`. This index is **only** a one-record-per-current-decision audit mirror, not a second dispatch register.

- For `QUEUED`, `CLAIMED`, `IN_PROGRESS`, `SUBMITTED`, `IN_REVIEW` and `BLOCKED`, do not invent review records.
- When S00 actually publishes `ACCEPTED` or `NEEDS_REVISION`, record the current decision in `index.json`, including `id`, `rr_id`, `actor: S00`, `decision`, `client_version`, `target_sha256`, `outcome_refs`, `review_path` and `review_blob_sha`.
- The `review_path` must be an existing Markdown under `governance/reviews/`. Its Git blob SHA, the original submitted research blob SHA and the RR dispatch review must agree. Use the [review template](../templates/S00-RR-REVIEW.md).
- Decision evidence is not equivalent to a T01 FULL-PASS, a resolved GAP, a REVIEWED/STABLE SPEC, an approved ADR, source-backed vector or real original Client compatibility.
- Run `python -B governance/check_s00_reviews.py --check` and the governance tests. This check cannot authenticate reviewer identity; maintainer review and Git permissions remain authoritative. It neither changes state nor sends notifications.

For an additional review of the same RR, retain historical Markdown records and update the current ledger entry with the new decision and blob, coordinating a single main-branch update.
