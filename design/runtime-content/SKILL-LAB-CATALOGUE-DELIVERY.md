# Skill catalogue delivery — v68 prepared

Observed live v63 `/local-test/progress/status` response size was5,473,337 UTF8
bytes. The page requested the complete static catalogue every2seconds. This is
unnecessary repeated transfer/allocation, not proof that it caused a reported
gameplay stall or an established performance benchmark.

## Compatible API and page behavior

- Keep default `/local-test/progress/status` with its full `skillLabChoices` for
  existing callers. Add optional `includeSkillCatalogue=false`; that response
  retains the other state/checkpoint/journal fields but sets `skillLabChoices:null`.
- Include `skillLabCatalogueUrl:"/local-test/skills/catalog"` in both shapes.
- Add loopback-only GET `/local-test/skills/catalog`, returning the same189
  profile catalogue as JSON. Serialize the embedded immutable data once per
  Host process, lazily and outside the progress-control lock. The response uses
  `Cache-Control:no-cache`; this is a per-Host cache, not a persistent browser
  or on-disk cache of account state.
- The page polls the slim status every2seconds and uses a single shared promise
  to fetch catalogue data once. Repeated polls retain role/matrix/tier, individual
  levels, target mode and the unchanged picker DOM. Source data must not be
  replaced by `[]` merely because a slim response has no catalogue payload.
- A failed catalogue fetch resets the pending promise so a subsequent regular
  refresh can try again. The test-entry button starts disabled until a supported
  selection is available. No new user permission/approval flow is introduced.

Legacy full-catalogue construction is also moved outside the connection-state
snapshot lock. The static catalogue has no account data, current cooldowns or live
combat state; profile selection still uses the existing exact source joins. A new
Host build/restart rebuilds the cache. Refresh the page after deployment to obtain
the new page script; an already-open old page retains its old polling code.

This changes catalogue delivery only. Skill admissions, resource/cooldown rules,
normal village admission, test isolation, Client resources and native MEF are
unchanged. Do not infer original Client compatibility or universal latency/frame
improvement from static payload reductions.

## Verification

181 HappyPath passed,0failed/0skipped,61seconds. The added positive case verifies
slim/default state equivalence except catalogue contents, semantic equality of
separate/default catalogues,189 profiles, exact Practice50 level11 SP55/MP50,
memoized JSON reuse and a small disconnected-state response. It is not a load,
concurrency, failure or security suite; those remain deferred.

JavaScript syntax and a page-flow simulation passed. The simulation observed one
catalogue GET across three slim polls, preserved the selected level/picker and
submitted both the level override and Melee target mode. Host build and deployed
HTTP results are recorded separately. Normal village/skill Client acceptance
remains pending. Prepared skill counts stay179/881 with64 unavailable.
