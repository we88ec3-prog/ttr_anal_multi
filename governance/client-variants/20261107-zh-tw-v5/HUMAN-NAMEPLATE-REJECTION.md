# v5 nameplate human rejection — 2026-11-07

User reports overhead NPC names still Korean, with screenshot of square NPCs,
including Tethys. v5 nameplate acceptance FAILED; previous static verification
only proved the produced files, not the runtime consumer path.

Read-only process inventory confirms a process named Tartaros.ip-zh-tw-v5.exe,
PID27400. Win32_Process ExecutablePath is null, so this is a process-name check,
not proof of its full executable path or in-memory image identity. No attach,
injection, restart or game input was performed.

On-disk v5 Table npctable NPC10338 NAME/GUILD are Chinese as planned. v5 EXE's
Table mount instruction at4A2E20 still points to the added section address and
v5 string; no evidence yet that the overhead renderer consumes that archive.
Existing saved original code524850 parses NAME/GUILD using XML and UTF8-to-wide
conversion440130. This is a partial reader path, not a fully audited renderer
chain. Existing saved CNPC/CDoll creation sources alone do not close that gap.
No further EXE/resource patch is applied based on this failed hypothesis.

Left-bottom screenshot text is a normal system chat-command help list:
chat commands; whisper (recipient ID), party, guild, alliance. It is not a
render error or server rejection. Korean UI help remains untranslated. This
observation does not authorize changing other UI resources without the user's
requested explanation/confirmation process.

Next investigation must establish exact runtime data/lookup-to-nameplate path,
including competing archive/cache/initialization sources, before another proposal.
Do not ask the user to repeat the same v5 test or count v5 as passed.
