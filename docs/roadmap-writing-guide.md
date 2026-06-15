# Roadmap Writing Guide — roadmap/README.md

This document defines the structure, conventions, and rules for writing and updating
the learning roadmap. The roadmap is fundamentally different from bible topic files —
it navigates the learning journey, it does not teach concepts.

**Read this before editing `roadmap/README.md` or adding new phases.**

---

## Table of Contents

- [Purpose of the Roadmap](#purpose-of-the-roadmap)
- [Tone & Voice](#tone--voice)
- [What the Roadmap Is NOT](#what-the-roadmap-is-not)
- [Roadmap File Structure](#roadmap-file-structure)
- [Section Templates](#section-templates)
  - [File Header](#file-header)
  - [How to Progress Block](#how-to-progress-block)
  - [Phase Entry](#phase-entry)
  - [Phase Goal Statement](#phase-goal-statement)
  - [Outcomes List](#outcomes-list)
  - [Topic Tree](#topic-tree)
  - [Phase Checkpoint](#phase-checkpoint)
  - [Transition Note](#transition-note)
  - [Progression Diagram](#progression-diagram)
- [Rules for Each Element](#rules-for-each-element)
- [What Belongs in the Roadmap vs. the Bible](#what-belongs-in-the-roadmap-vs-the-bible)
- [Updating the Roadmap](#updating-the-roadmap)

---

## Purpose of the Roadmap

The roadmap answers three questions for the learner:

1. **Where am I going?** — what each phase achieves
2. **In what order?** — the correct learning sequence and why
3. **How do I know I'm ready to move on?** — phase checkpoints

It is a navigation document. It motivates, orients, and directs.
It does not teach. It does not explain how things work.
Every time you feel the urge to explain a concept in the roadmap, stop —
that explanation belongs in a bible topic file.

---

## Tone & Voice

The roadmap speaks directly to the learner. It is motivating but honest.
It does not oversell ("you'll master Linux in 14 phases!").
It does not undersell ("this will be extremely difficult").
It tells the learner what they will gain and what is expected of them.

**On-voice:**
- *"The goal of this phase is to..."* — clear, direct, outcome-focused
- *"A weak understanding of permissions in Phase 3 becomes a security hole in Phase 13."* — honest, specific
- *"Phases 8 and 9 can be taken in either order — they don't depend on each other."* — practical
- *"This is the phase most people skip. Don't."* — candid, sets expectation

**Off-voice:**
- *"In this exciting phase, you will discover the power of..."* — marketing
- *"Simply complete the following topics..."* — condescending
- *"It is recommended that learners..."* — passive, distant
- Any explanation of how a concept works — that belongs in the bible

**Person:** Second person ("you", "your"). Never "the learner" or "one should".

**Tense:** Present tense for descriptions ("this phase covers"), future for outcomes
("you will be able to").

---

## What the Roadmap Is NOT

| What the roadmap IS | What the roadmap IS NOT |
|---|---|
| A navigation guide | A teaching document |
| Outcome statements | Concept explanations |
| Topic names and brief sub-topic hints | Full topic coverage |
| Phase checkpoints (what to build or do) | Tutorial walkthroughs |
| Ordering rationale | Theory or mechanics |
| Motivating context | Commands or code |
| A living document (updated as curriculum grows) | A substitute for the bible |

If you find yourself writing more than 2 sentences of explanation about a concept
in the roadmap, stop. Move that content to the appropriate bible topic file.

---

## Roadmap File Structure

The roadmap file has these top-level sections, in this order:

```
# Linux Learning Roadmap          ← H1 title

[intro paragraph]                  ← 2–3 sentences max

---

## How to Progress               ← H2, always present

[4–6 bullet points]

---

## Phase 1 — [Phase Name]        ← H2, one per phase

[phase content — see Phase Entry below]

---

## Phase N — [Phase Name]

...

---

## Quick Reference               ← H2, always last before link

[table: common goals → starting phase]

---

→ Full topic reference link to bible
```

---

## Section Templates

### File Header

```markdown
# Linux Learning Roadmap

A structured path from zero to veteran. Each phase builds on the last, but you
can jump to any topic — the roadmap is a map, not a cage.

For the complete reference on every topic, see the [Bible](../bible/README.md).

---
```

Rules:
- The intro is 2–3 sentences maximum
- Always link to the bible — the roadmap is the spine, the bible is the flesh
- Never expand the intro to explain concepts

---

### How to Progress Block

```markdown
## How to Progress

- **[Short imperative label].** [One sentence of honest explanation.]
- **[Short imperative label].** [One sentence of honest explanation.]
- **[Short imperative label].** [One sentence of honest explanation.]
- **[Short imperative label].** [One sentence of honest explanation.]
```

Rules:
- 4–6 bullets only
- Each bullet: bold label (imperative verb phrase) + one sentence of honest explanation
- The explanation must be specific — not generic advice
- These apply to the entire curriculum, not to any specific phase

**On-target bullets:**
- **Don't just read — type it.** Linux is a physical skill as much as a mental one; your fingers need to know the commands, not just your eyes.
- **Break things in a VM.** You will not truly understand `rm -rf` until you've accidentally nuked something in a safe environment.

**Off-target bullets:**
- **Be patient.** Learning takes time. *(too generic)*
- **Study the theory.** It's important. *(says nothing)*

---

### Phase Entry

Each phase follows this exact structure:

```markdown
## Phase N — [Phase Name]

> [Phase Goal Statement]

**What you'll be able to do after this phase:**
[Outcomes List]

**Topics in learning order:**
[Topic Tree]

**Phase N checkpoint:** [Phase Checkpoint]

---
```

The `---` separator comes after every phase entry, including the last one before
the Quick Reference section.

---

### Phase Goal Statement

The blockquote directly under the H2 heading.

```markdown
> The goal of this phase is to [concrete outcome in one sentence].
```

Rules:
- One sentence. Never two.
- Describes what the learner will be able to **do** — not what they will **know**
- Concrete and specific — not "understand Linux better"
- Written from the learner's perspective — what changes for them

**Good:**
> The goal of this phase is to navigate any Linux system confidently from the command line without reaching for a GUI.

**Bad:**
> The goal of this phase is to learn about the terminal, navigation commands, and how to read files.
*(This is a topic list, not a goal.)*

---

### Outcomes List

```markdown
**What you'll be able to do after this phase:**
- [verb] [specific capability]
- [verb] [specific capability]
- [verb] [specific capability]
```

Rules:
- 4–7 bullets
- Every bullet starts with an action verb: *Navigate, Write, Diagnose, Configure, Explain, Debug, Harden*
- Each capability is specific and verifiable
- Outcomes describe ability, not knowledge. "Know about X" is not an outcome.
  "Use X to accomplish Y" is.

**Good outcomes:**
- Diagnose a process that is consuming unexpected CPU using only command-line tools
- Write a shell script that safely handles errors, signals, and cleanup on exit
- Configure SSH key-based authentication and disable password login on a server

**Bad outcomes:**
- Know what processes are *(knowledge, not ability)*
- Understand shell scripting *(vague — understand how much?)*
- Learn about SSH *("learn about" is not an outcome)*

---

### Topic Tree

```markdown
**Topics in learning order:**

```
N.X  Topic Name
     └─ key concept covered
     └─ key concept covered
     └─ key concept that has a notable gotcha or subtlety
N.Y  Topic Name
     └─ key concept
     └─ key concept
```
```

Rules:
- Use a plain code block (no language tag) so the tree renders in monospace
- List topics in the recommended learning order — not alphabetical, not arbitrary
- Sub-bullets show what is specifically covered — they are hints, not exhaustive lists
  (the bible has the exhaustive list)
- 2–5 sub-bullets per topic
- Sub-bullets use `└─` — it's a visual cue, not a strict tree structure
- If a sub-bullet calls out a specific gotcha, write it — these are useful navigation
  cues: *"rm -rf — why the path matters more than the flags"*

---

### Phase Checkpoint

```markdown
**Phase N checkpoint:** [Description of the task or mini-project.]
```

Rules:
- One sentence — dense and specific
- Must be a concrete, doable thing — not "review the topics"
- Must require combining multiple concepts from the phase
- Must produce something observable — output, a running service, a working config
- Safe to complete on a standard Linux VM or container
- The checkpoint should be achievable in a few hours by someone who has genuinely
  absorbed the phase

**Good checkpoints:**
> Write a shell script that monitors a log file for error patterns, sends a signal to a named process when found, and logs its own activity with timestamps — using `set -euo pipefail` throughout.

> Configure SSH on a fresh VM: disable root login and password auth, create a dedicated user with key-based access only, add a firewall rule allowing only port 22, and verify each step before moving to the next.

**Bad checkpoints:**
> Review Phase 5 and make sure you understand the concepts. *(not buildable)*
> Write a script. *(too vague)*
> Set up a Linux system however you want. *(no constraint = no learning)*

---

### Transition Note

*Optional.* Used when a phase relationship is non-obvious or when a phase reframes
earlier learning.

```markdown
> *(Transition note: [one sentence explaining the relationship to the next or previous phase.])*
```

Use transition notes sparingly — only when the phase boundary needs explanation.
Example: Phase 14 (Advanced Topics) assumes everything from Phases 1–13.
Phase 5 (Shell & Scripting) is where Phase 4 (Text Processing) pays off — worth noting.

Do not add a transition note to every phase — it dilutes the ones that need it.

---

### Progression Diagram

The final section. Shows the dependency graph of phases.

```markdown
## Quick Reference

| I want to... | Start here |
|---|---|
| Learn Linux from scratch | Phase 1 |
| ... | ... |

---

→ **Full topic reference:** [The Linux Bible](../bible/README.md)
```

---

## Rules for Each Element

| Element | Rule |
|---|---|
| Phase goal statement | One sentence. Describes ability, not knowledge. |
| Outcomes list | 4–7 bullets. Action verb + specific capability. Never "understand X". |
| Topic tree | Code block. Topics in recommended learning order. 2–5 sub-bullets per topic. |
| Sub-bullets | Key concepts and notable gotchas. Not exhaustive — the bible is exhaustive. |
| Phase checkpoint | One sentence. Concrete. Doable on a VM. Combines multiple phase concepts. |
| Transition notes | Optional. One sentence. Only when the relationship is non-obvious. |
| Intro paragraph | 2–3 sentences. Links to bible. Never expands into explanation. |
| How to Progress | 4–6 bullets. Bold label + one honest sentence. Curriculum-wide, not phase-specific. |

---

## What Belongs in the Roadmap vs. the Bible

| Content | Roadmap | Bible |
|---|---|---|
| What a phase achieves | ✅ | ❌ |
| Why this tool or concept exists | ❌ | ✅ |
| What concepts a topic covers (brief hints) | ✅ | ❌ |
| How those concepts work | ❌ | ✅ |
| That a gotcha exists (named in sub-bullet) | ✅ | ❌ |
| What the gotcha is and how to avoid it | ❌ | ✅ |
| Phase ordering and dependencies | ✅ | ❌ |
| Commands and examples | ❌ | ✅ |
| Phase checkpoint (what to build/do) | ✅ | ❌ |
| How to complete the checkpoint | ❌ | ✅ |
| Safety warnings | ❌ (no commands here) | ✅ |
| Links to bible topic files | ✅ (topic tree sub-bullets can link) | ✅ (Prerequisites, cross-references) |

---

## Updating the Roadmap

### Adding a new phase
1. Add the phase entry following the Phase Entry template exactly
2. Update the Quick Reference table if the new phase answers a common learning goal
3. Update `bible/README.md` to add the phase's table of contents section
4. Create the corresponding `bible/phase-N-name/` directory
5. Update `README.md` at the root if the curriculum overview table needs updating

### Adding a new topic to an existing phase
1. Add the topic to the Topic Tree in the correct learning order position
2. Add 2–5 sub-bullets for its key concepts
3. Update `bible/README.md` to add the topic under the correct phase section
4. Create the topic file in the correct `bible/phase-N-name/` directory
5. Update the navigation links in adjacent topic files (Previous / Next)

### Reordering topics
1. Update the Topic Tree order in the roadmap
2. Update the navigation links (top and bottom) in all affected bible topic files
3. If a topic's prerequisites change, update its Prerequisites section in the bible

### Updating a phase checkpoint
- Keep it concrete and doable on a standard VM
- Ensure it still covers multiple topics from the updated phase
- Test it yourself — if you can't describe exactly how to complete it, it's too vague
