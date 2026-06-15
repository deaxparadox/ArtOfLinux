# Content Writing Guide — Bible Topic Files

This document defines the mandatory structure, conventions, and rules for every topic
file written in the `bible/` directory. Every file — regardless of phase — follows this
template. Do not skip sections. Do not reorder sections. Do not merge sections.

**This guide exists so the structure is never lost or forgotten during content writing.**

---

## Table of Contents

- [Folder Structure](#folder-structure)
- [Tone & Voice](#tone--voice)
- [Code Block Conventions](#code-block-conventions)
- [Heading Level Rules](#heading-level-rules)
- [Cross-linking Rules](#cross-linking-rules)
- [Distro and Version Compatibility](#distro-and-version-compatibility)
- [The Mandatory File Template](#the-mandatory-file-template)
- [Section-by-Section Rules](#section-by-section-rules)
- [Section Reference Table](#section-reference-table)
- [Theory vs. How It Works — The Critical Distinction](#theory-vs-how-it-works--the-critical-distinction)
- [Trade-offs vs. When to Use/Avoid — The Distinction](#trade-offs-vs-when-to-useavoid--the-distinction)
- [Phase-Specific Weight Shifts](#phase-specific-weight-shifts)
- [Teaching Principles](#teaching-principles)

---

## Folder Structure

```
bible/
├── README.md                                    ← table of contents (never edit structure here)
├── phase-1-getting-comfortable/
│   ├── 1.1-what-is-linux.md
│   ├── 1.2-the-terminal.md
│   ├── 1.3-navigating-the-filesystem.md
│   ├── 1.4-reading-writing-files.md
│   └── 1.5-getting-help.md
├── phase-2-filesystem/
│   ├── 2.1-fhs.md
│   ├── 2.2-everything-is-a-file.md
│   ├── 2.3-file-types.md
│   ├── 2.4-inodes.md
│   └── 2.5-mounting.md
├── phase-3-permissions/
├── phase-4-text-processing/
├── phase-5-shell-scripting/
├── phase-6-processes/
├── phase-7-users-auth/
├── phase-8-packages/
├── phase-9-networking/
├── phase-10-storage/
├── phase-11-init-services/
├── phase-12-performance/
├── phase-13-security/
└── phase-14-advanced/
```

**One topic = one file.** Every file is self-contained and fully teachable on its own.
A learner should be able to open any single file and understand it without needing
to read surrounding files — though they should read prerequisites first.

---

## Tone & Voice

This is not a man page. It is not documentation. It is a veteran Linux engineer sitting
across from a junior, giving them the truth — not the sanitized version.

**The voice is:**
- **Direct.** Say the thing. Don't hedge unnecessarily.
- **Opinionated.** "The right way to do this is X." Not "some sysadmins prefer X."
- **Honest about pain.** "This has caused more outages than I can count." Not "note that."
- **Generous with context.** Always say why, not just what.
- **Occasionally blunt.** "This is a dangerous command. Here's exactly why."

**Phrases that are on-voice:**
- *"Here's what the man page won't tell you..."*
- *"The mistake most people make here is..."*
- *"In a real production system, you'd see this written as..."*
- *"I've watched this exact misunderstanding take down a server."*
- *"This looks safe. It isn't. Here's why."*
- *"The Unix way isn't just cleaner — it exists because..."*

**Phrases that are off-voice (never use):**
- *"It is worth noting that..."* — just say it
- *"One might consider..."* — who is "one"? say "you"
- *"In Linux, X is defined as..."* — sounds like a man page
- *"Simply..."* or *"Just..."* — nothing is simple to someone learning it
- *"Obviously..."* or *"Clearly..."* — condescending
- *"As mentioned earlier..."* — every file is self-contained; don't cross-reference prose
- *"Any real Linux user knows..."* — forbidden

**Length:** As long as the topic needs. Never pad to seem thorough. Never cut a
concept short to seem concise. The right length is when nothing can be added or
removed without making it worse.

---

## Code Block Conventions

### Language Tags
Always tag code blocks. No untagged fences.

```
```bash         ← all shell commands and scripts
```
```
```
```text         ← terminal output, ASCII diagrams, /proc content, config file snippets shown as output
```
```
```
```ini          ← systemd unit files, fstab, /etc/sysctl.conf style config
```
```
```
```c            ← kernel module code, system call examples
```
```

### Output Blocks
Always follow a runnable command with its expected output:

```bash
ls -la /etc/passwd
```

```text
-rw-r--r-- 1 root root 2847 Jan 15 09:23 /etc/passwd
```

If output is long, show the relevant lines and use `...` to indicate truncation.

### Comments in Code
- Comment every non-obvious flag or argument
- Never comment obvious lines
- Comments explain *why*, not *what* — the command already says what
- Exception: in Basic Example blocks, comments can explain *what* because
  the learner is still learning to read commands

### Pseudocode
Avoid pseudocode. If you must show a conceptual flow, tag it `text` and add a comment:

```text
# Conceptual flow — not a real command
kernel receives syscall → checks capabilities → grants or denies
```

Never put pseudocode in a `bash` block. If a learner runs it and it fails, trust is broken.

### Dangerous Commands
Before any command that could cause data loss or system damage, add an explicit warning block:

> ⚠️ **WARNING:** This command will overwrite the contents of `/dev/sdb` with zeros.
> There is no undo. Run `lsblk` first to confirm the target device. Test in a VM.

The warning must appear **before** the code block, never after.

---

## Heading Level Rules

```
# Topic Title                    ← H1 — appears once, at the very top
## Section Name                  ← H2 — each major section (Prerequisites, Theory, etc.)
### Sub-section Name             ← H3 — gotcha names, distro notes, sub-topics within a section
#### Deep sub-section            ← H4 — use sparingly, only when H3 is already used above
```

**Rules:**
- Never use H1 inside a topic file except for the title
- Never skip levels (don't go H2 → H4)
- Section names in the template are H2 — do not change them to H3 to "make room"
- If a section needs sub-sections, those are H3

---

## Cross-linking Rules

### When to link
- In **Prerequisites**: always link to the topic file that must be read first
- In **Theory** or **How It Works**: link when you reference a concept that has its
  own dedicated file elsewhere in the bible — do not re-explain it, link to it
- In **Gotchas**: link to the topic that explains the fix in depth if relevant
- In **Navigation** (top and bottom): always link to previous and next topic files

### When NOT to link
- Do not link to external sites mid-explanation — it breaks reading flow.
  External references go in Tools & Ecosystem or a dedicated Further Reading note.
- Do not link to a topic that hasn't been written yet — use bold text instead:
  `**inodes** (covered in 2.4)`

### Link format
Use relative paths from the current file:

```markdown
[2.4 — Inodes](../phase-2-filesystem/2.4-inodes.md)
```

Never use absolute paths. Never use bare URLs for internal links.

---

## Distro and Version Compatibility

### Where distro info goes
- In a **Distro Notes** table within the relevant section (see template)
- Inline in prose only when the difference is a single word: *"On Debian/Ubuntu, use `apt`; on RHEL/Fedora, use `dnf`."*

### What to note
- Package names that differ across distros
- Default paths that vary (`/etc/sysconfig/` vs `/etc/default/`)
- Tool availability — not every tool is installed by default everywhere
- Behavioral differences in the same command across distros
- Kernel version–specific features (e.g., cgroups v2 requires kernel 4.5+, unified hierarchy 5.2+)

### What not to note
- Distro wars or preferences — no editorializing on which distro is better
- Historical differences that no longer apply

### Distro Notes table format
```markdown
| Distro Family | Package / Path / Behavior |
|---|---|
| Debian / Ubuntu | `apt install <name>`, config at `/etc/default/` |
| RHEL / Fedora / CentOS / Rocky | `dnf install <name>`, config at `/etc/sysconfig/` |
| Arch | `pacman -S <name>` |
| Alpine (containers) | `apk add <name>` |
```

---

## The Mandatory File Template

```markdown
# [X.Y] — [Topic Name]

> [One sentence: the real-world reason this topic exists or the problem it solves.]

📍 Phase X → [Topic Name] | ⬅️ [Previous Topic](link) | [Next Topic](link) ➡️

---

## Prerequisites

- [Concept name](link-to-topic-file) — one-line reason why it's needed
- [Concept name](link-to-topic-file) — one-line reason why it's needed
- *None — this is the starting point.* (if it's the very first topic)

---

## The Problem This Solves

[Show the pain before the solution. What was broken, dangerous, or missing
before this tool or concept existed? Show the world without it.

For foundational topics with no "before" state — e.g. "What Linux is" — replace this
section with: "Why This Exists". Explain what problem it solves and why it was created.
The purpose of this section is always to create the question before giving the answer.]

---

## Mental Model

[One analogy. A concrete frame the learner can hang everything else on.
No jargon. No Linux-specific terminology. Written like you're explaining to a
smart friend who has never opened a terminal. One analogy only — two analogies
compete and cancel each other out.]

---

## Theory

[The conceptual foundation. No commands. A learner must be able to explain
this concept to someone else after reading this section alone.]

Cover all that apply:
- What is this, precisely? (plain-English definition)
- Why does it exist in the OS? What design decision or problem led here?
- What invariants always hold true?
- How does Linux / Unix think about this? (everything is a file, etc.)
- What is the relationship to surrounding or prerequisite concepts?

Style: clear prose, short paragraphs. Bullet lists only where items are genuinely
parallel. Never use bullets to avoid writing explanatory sentences.

---

## How It Works (Mechanics)

[The internal story. What the kernel actually does when this runs.]

Cover all that apply:
- Step-by-step execution trace
- What happens in kernel space vs user space
- System calls involved (when illuminating — use `strace` output where helpful)
- ASCII diagram or numbered trace where it helps more than prose

Code in this section is illustrative only — it exists to reveal the mechanics,
not to teach usage. Usage comes in the examples below.

---

## Basic Example

[The simplest possible working demonstration of the concept.]

Rules:
- Copy-pasteable — runs without modification on any standard Linux system
- Produces visible output — the learner sees something happen
- Every non-obvious flag or argument gets a comment
- No production concerns — just the concept, naked and clear

```bash
# [what this demonstrates]
[command]
```

```text
[expected output]
```

After the example, tell the learner what to look for in the output and
invite them to try it: *"Now try this yourself. If your output looks slightly
different, it's likely [reason] — that's normal on [distro/version]."*

---

## Real-World Example

[How this actually appears in a production context. Not a toy — closer to
what the learner will encounter on a real server.]

Rules:
- More complete than the basic example — realistic context, realistic data
- Always followed by a prose walkthrough — never drop commands without explanation
- Can show a full script, a config file interaction, a multi-step diagnostic

```bash
[production-relevant commands]
[comments on non-obvious parts only]
```

[Prose walkthrough: what each step does, why it's done this way, what a
senior sysadmin would notice about it.]

---

## ⚠️ Gotchas

[Every trap for this topic gets its own named sub-section. Do not bury gotchas in
other sections — they deserve prominence and a heading so they're scannable.]

[If this topic genuinely has no gotchas, write one sentence: "This topic has no
significant gotchas." Do not omit the section — its absence would signal it was
forgotten, not that it was checked.]

### [Name of the Trap — descriptive, not generic]

[What the learner expects to happen. Be specific — name the assumption.]

```bash
# what looks right but isn't
[command]
```

```text
[what actually happens — the surprising output or error or silent failure]
```

[Explain the rule that causes the surprise. Don't just show the fix — explain
the underlying reason so the learner won't fall into the same class of trap again.]

```bash
# the correct version
[fixed command]
```

[Repeat one ### block per gotcha.]

---

## Distro Notes

*Include when behavior, paths, package names, or tool availability differ
meaningfully across distributions. Omit if the topic is truly universal.*

| Distro Family | Package / Path / Behavior |
|---|---|
| Debian / Ubuntu | ... |
| RHEL / Fedora / CentOS / Rocky | ... |
| Arch | ... |
| Alpine (containers) | ... |

---

## Alternatives & Comparisons

*Include when there is a meaningful modern vs legacy contrast, or when multiple
tools solve the same problem and the learner needs guidance on which to use.
Omit entirely if there is no real alternative worth comparing.*

| Tool | When to Use | Notes |
|---|---|---|
| [tool] | [specific scenario] | [version, status, caveats] |

[One paragraph of honest recommendation: when you'd reach for each and why.]

---

## Trade-offs

*Required from Phase 3 onward. In Phases 1–2, include only when trade-offs are
real and teachable to a beginner. This section is about the COSTS AND BENEFITS of
the concept itself — not about when to use it (that's the next section).*

**Where this shines:**
- [specific scenario where this is the right choice and why]

**Where this costs you:**
- [specific cost: safety risk, performance, complexity, portability, debuggability]

**Performance note:** *(Include only if there is a concrete, measurable claim to make.
Never write vague statements like "may be slower in some cases.")*

---

## When to Use / When to Avoid

*This section is about DECISION GUIDANCE — when to reach for this and when not to.
It is not a repeat of Trade-offs. Trade-offs describe properties; this guides decisions.*

✅ **Use this when:**
- [concrete, specific scenario]

❌ **Avoid this when:**
- [concrete, specific scenario — name the safer alternative if there is one]

⚠️ **Common mistakes:**
- [mistakes that don't rise to the level of a full gotcha — quick callouts]

---

## Veteran Perspective

[Write this like you're at a whiteboard with a junior after an incident review.
Honest. Direct. Occasionally opinionated. This is the section that separates this
curriculum from a man page. Say what you'd actually say — not what official docs say.]

Cover all that apply:
- What a newcomer misunderstands about this (the surface-level mistake)
- What an intermediate sysadmin misses (the subtler gap)
- The deeper design principle behind this feature or tool
- What you'd say in an incident review when you see this done wrong
- What this topic leads to in technical interviews (only where genuine and common)
- A brief war story: a real scenario where knowing or not knowing this mattered

---

## Try It Yourself

[3–5 concrete prompts. Not formal exercises — nudges that make the learner
open a terminal and type something. Increase in difficulty.]

1. [Directly applies what was just shown — almost no thinking required]
2. [Slight variation or extension of the basic example]
3. [Combines this topic with a concept from a previous topic]
4. [Requires genuine thinking — not just copying the example]
5. **Challenge:** [Production-level — something they'd be proud of; safe to run in a VM]

---

## Summary

[3–5 bullet points. The things the learner must walk away knowing.
Written as statements of fact, not questions. If a learner reads only this section,
they should know exactly what to look up to go deeper.]

- [fact / rule / invariant]
- [fact / rule / invariant]
- [fact / rule / invariant]

---

📍 Phase X → [Topic Name]
⬅️ [Previous Topic](../phaseX/filename.md) | [Next Topic](../phaseX/filename.md) ➡️
```

---

## Section-by-Section Rules

### The Problem This Solves
- Never open with *"In Linux, X is..."* — that's theory, not a problem
- Show the world without the tool — what was painful, dangerous, or impossible
- For foundational topics with no "before" state, rename to **"Why This Exists"**
- End by setting up the solution: *"Linux has a better way. That's what this section is about."*

### Mental Model
- One analogy only. Two analogies fight each other.
- The analogy must survive contact with the actual mechanics — don't use analogies
  that break when you go deeper
- Write it without any Linux-specific terminology

### Theory
- No commands whatsoever in this section
- After reading Theory, the learner can explain the concept verbally to someone else
- Cover invariants — the things that are always true, no matter what

### How It Works (Mechanics)
- Commands here are illustrative only — they exist to expose kernel or system behavior
- `strace` output is encouraged when system calls illuminate the concept
- ASCII diagrams are preferred over walls of prose when showing memory layout,
  process trees, filesystem structure, or network flows

### Gotchas
- Each gotcha gets a descriptive H3 name — not *"Gotcha 1"* but *"Trailing Slash Changes rsync Behavior"*
- Show the trap → the surprise → the explanation → the fix. In that order, always.
- Explain the underlying rule, not just the fix.
- Safety gotchas (commands that destroy data) get an explicit ⚠️ WARNING before the broken example

### Trade-offs vs. When to Use/Avoid
These are different sections. Do not repeat content between them.

| Trade-offs | When to Use / When to Avoid |
|---|---|
| What are the properties of this concept? | How do I decide whether to use it? |
| Costs and benefits as facts | Decision rules as guidance |
| *"Signals are asynchronous — a process can be killed at any point"* | *"Use SIGTERM first, wait, then SIGKILL — never jump straight to -9"* |
| Describes the concept | Guides a decision |

### Veteran Perspective
- Write what you'd actually say at 3am during an incident. Not what a textbook would say.
- If a tool is misused more than used correctly, say so.
- If something has a subtle trap that only emerges in production, say so.
- This is not a summary of the topic — it's an honest editorial on it.

### Try It Yourself
- Prompt 1 is trivial by design — success builds confidence
- Prompt 5 (Challenge) should require a VM and produce something the learner could demo
- Never write prompts that are just re-typing the examples
- Always note when a prompt requires `sudo` or a VM

### Summary
- 3–5 bullets maximum. Force yourself to cut.
- Each bullet is a standalone fact — not *"We learned about permissions"*
  but *"Execute permission on a directory means traverse, not run — you need it to `cd` into it"*

---

## Section Reference Table

| Section | Required? | Has Commands? | Length |
|---|---|---|---|
| Title (H1) | Always | No | 1 line |
| Hook (blockquote) | Always | No | 1 sentence |
| Navigation (top) | Always | No | 1 line |
| Prerequisites | Always | No | 1–7 bullets |
| The Problem This Solves | Always* | Bad example only | 2–4 paragraphs |
| Mental Model | Always | No | 1–3 paragraphs |
| Theory | Always | No | as long as needed |
| How It Works (Mechanics) | Always | Illustrative only | as long as needed |
| Basic Example | Always | Yes + output | short |
| Real-World Example | Always | Yes + prose | medium |
| Gotchas | Always (even if empty) | Yes | 1 block per trap |
| Distro Notes | When relevant | No | table |
| Alternatives & Comparisons | When relevant | No | table + paragraph |
| Trade-offs | Phase 3+ | No | bullets |
| When to Use / When to Avoid | Always | No | bullets |
| Veteran Perspective | Always | No | 4–8 points |
| Try It Yourself | Always | No | 3–5 prompts |
| Summary | Always | No | 3–5 bullets |
| Navigation (bottom) | Always | No | 1 line |

*\* For foundational topics with no "before" state, rename to "Why This Exists"*

---

## Theory vs. How It Works — The Critical Distinction

These two sections are the most commonly collapsed. They must remain separate.

| Theory | How It Works (Mechanics) |
|---|---|
| The *what* and *why* | The *how* |
| Definition, design reasoning, invariants | Kernel behavior, system calls, internal flow |
| Unix philosophy, design history | Step-by-step execution trace |
| No commands | Commands used only to illustrate mechanics |
| Readable completely standalone | Builds on Theory |
| *"A pipe is a unidirectional byte stream connecting stdout of one process to stdin of another"* | *"When the shell sees `|`, it calls `pipe()` to create an anonymous pipe, then `fork()` twice, redirecting stdout/stdin in each child before calling `exec()`"* |

**Theory** answers: *"What is this and why does it exist?"*
**How It Works** answers: *"What does the kernel actually do when I use this?"*

---

## Trade-offs vs. When to Use/Avoid — The Distinction

| Trade-offs | When to Use / When to Avoid |
|---|---|
| Describes properties of the concept | Gives decision guidance |
| Facts about cost and benefit | Rules about situations |
| *"SIGKILL cannot be caught — the process has no chance to clean up open files or flush buffers"* | *"Use SIGTERM first, give the process a few seconds, then SIGKILL only if it doesn't exit"* |
| Answers: *"What does this cost me?"* | Answers: *"Should I use this here?"* |

Do not repeat content between these two sections.

---

## Phase-Specific Weight Shifts

The template is identical across all phases. The *weight* — how much depth and length
each section gets — shifts based on where the learner is.

| Phase | Heaviest sections | Lightest sections |
|---|---|---|
| 1 — Getting Comfortable | Mental Model, Basic Example, Try It Yourself | Trade-offs, Veteran Perspective |
| 2 — Filesystem | Theory, How It Works (kernel internals) | Alternatives |
| 3 — Permissions | Gotchas, Real-World Example, When to Use | Alternatives |
| 4 — Text Processing | Basic Example, Real-World Example, How It Works | Trade-offs |
| 5 — Shell & Scripting | Gotchas, How It Works, Veteran Perspective | Distro Notes |
| 6 — Processes | Theory, How It Works (kernel), Gotchas | Alternatives |
| 7 — Users & Auth | Real-World Example, Veteran Perspective, Security notes | Mental Model |
| 8 — Package Management | Distro Notes, Real-World Example | How It Works |
| 9 — Networking | Basic Example (diagnostic sequences), Gotchas | Trade-offs |
| 10 — Storage | ⚠️ Safety warnings, Real-World Example, When to Use | Mental Model |
| 11 — Init & Services | Theory (systemd internals), Real-World Example | Alternatives |
| 12 — Performance | Real-World Example (diagnostic flow), How It Works | Mental Model |
| 13 — Security | Veteran Perspective, When to Use/Avoid, Gotchas | Basic Example |
| 14 — Advanced | Theory, How It Works (deep kernel), Trade-offs | Try It Yourself |

---

## Teaching Principles

These are non-negotiable. Every topic file must honor all of them.

1. **Show the problem before the solution.**
   Learners don't absorb answers to questions they haven't asked yet.

2. **Every command in a `bash` fence must run.**
   If a conceptual trace is unavoidable, tag it `text` and label it explicitly.

3. **Gotchas get their own section with a heading.**
   Never bury a trap in a paragraph where it can be skimmed past.

4. **Theory before mechanics before examples. Always.**
   This order exists because understanding must precede observation.

5. **Teach the why, not just the what.**
   Commands are man-pageable. Understanding why is not.

6. **Safety warnings appear before dangerous commands, never after.**
   A learner who runs first and reads later is the norm, not the exception.

7. **The veteran perspective is honest, not diplomatic.**
   Write what you'd actually say at 3am during an incident — not what a man page says.

8. **Try It Yourself are nudges, not assignments.**
   They are invitations. The learner should want to open a terminal, not feel they have to.

9. **Navigation at the top and bottom of every file.**
   A learner should never need to go back to the table of contents to move forward.

10. **No forward references in prose.**
    If a concept is needed to explain this topic, either teach it in place or link to
    where it's taught. Never write "we'll cover this later."

11. **Summary is the minimum viable takeaway.**
    If a learner reads only the Summary, they should know what to look up to go deeper.

12. **One analogy in Mental Model.**
    Two analogies compete. One analogy sticks.

13. **Distro differences are facts, not opinions.**
    Note them without editorializing about which distro is better.
