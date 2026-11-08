# Opt-in skill damage coefficient comparison

T12 README still identifies20/35/60 damage as fixture values and does not recover
an official damage formula. The source projection contains1448 exact learned-
level rows;1333 have exactly one ATTACK row and115 have none. Source ratio/rev
units, stat selection, defense, criticals and native hit/phase timing remain
unknown. A new normal combat formula is not justified by these tags alone.

Server design: isolated SkillLab selection gains `coefficientDamage`, default
false, preserved across that lab's V/Tab profile changes. Normal tutorial/story
and existing ordinary lab behavior stay unchanged. Raw-action preview requires
false. This option is not persisted as player stats, items or progression.

When enabled, each existing prototype damage pulse uses the test hypothesis
`max(0, ceil(100 * ratio / 100 + revision))` from that exact accepted Practice /
learned level / Active level's sole ATTACK row.100 is an explicit comparison
input, not the character's attack stat; percent-plus-addition is a hypothesis,
not recovered units. No defense/critical/type/trait calculation is implied.
Source rows with no ATTACK create no comparison damage, rather than inheriting
the previous X/key's damage. Multiple ATTACK rows are not silently summed.

Keep non-damaging/self-heal/field/defence routing and resource costs unchanged.
Returning-fist outbound prototype damage may use the same comparison value;
return damage remains0 and pull remains independent. Existing area, delay,
projectile topology and pulse counts are not inferred from coefficients.
Target HP caps actual damage normally; lethal cleanup follows the common path.

The page displays an explicit checkbox and numeric comparison preview for each
selected skill. Existing source coefficients are already available in the cached
catalogue; do not expand slim status polling or reinitialize cooldown timers.
Mark the option as a comparison formula, not official balance or full skill
completion. This adds no animation binding or native MEF support.

Validation should exercise exact level-dependent damage and resource payment,
non-damage skills, returning outbound/return distinction, V/Tab retention, normal
mode preservation and raw-preview isolation through authorized positive cases.
Actual Client damage/visual acceptance stays pending; deferred suites remain off.
