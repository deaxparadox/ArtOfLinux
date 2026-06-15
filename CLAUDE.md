# ArtOfLinux — Project Instructions for Claude

This is a Linux teaching curriculum project. Every session working on this project
must follow the rules below without exception. These rules apply whether writing new
content, editing existing content, updating structure, or answering questions.

---

## Mandatory Rules — Always Active

### Rule 1: Always Follow the Writing Guides

Before writing or editing ANY content in this project, read the relevant guide first.
Do not write from memory of a previous session. The guides may have changed.

| What you are writing | Which guide to read first |
|---|---|
| A bible topic file (`bible/**/*.md`) | [`docs/content-writing-guide.md`](docs/content-writing-guide.md) |
| The learning roadmap (`roadmap/README.md`) | [`docs/roadmap-writing-guide.md`](docs/roadmap-writing-guide.md) |
| Both | Read both |

**This is non-negotiable.** The guides define the mandatory section order, template,
tone, code conventions, heading levels, safety rules, and teaching principles.
Writing content without reading the guide first will produce files that are
structurally inconsistent and must be rewritten.

### Rule 2: Never Assume — Always Research and Verify

**Never write Linux content from memory or training data alone.**

Before writing any technical content — commands, flags, kernel behavior, config files,
version information, or anything factual about Linux — you must verify it using:

1. **Web search** — for current best practices, distro-specific differences, recent
   changes, man page updates, and anything that could have changed since training data cutoff

2. **Context7** (`mcp__plugin_context7_context7__query-docs`) — for official
   documentation on tools covered in the curriculum (systemd, bash, kernel docs, etc.)

**What to verify before writing:**
- Command flags and syntax (man pages change between versions and distros)
- Distro-specific paths, package names, and tool availability (Debian vs RHEL vs Arch)
- Kernel version–specific behavior (e.g., cgroups v2 availability, eBPF features)
- systemd unit directives and their supported versions
- Whether a tool is deprecated and what replaces it (e.g., `ifconfig` → `ip`)
- Security recommendations that evolve over time (cipher suites, kernel hardening)
- Performance claims — never make vague claims; cite a source or omit

**The standard:** If you are not 100% certain a fact is current and correct,
research it before writing it. A wrong command in a teaching document — especially
one that could damage a system — is worse than a missing command.

### Rule 3: Continue Without Asking Permission — But Never Rush

When given a multi-phase or multi-step task (e.g. "verify all phases", "write all
topics"), proceed through every step without stopping to ask "shall I continue?" or
"ready for Phase N?" between steps. The user has already given the instruction — execute
it fully.

**However, continuing without asking does NOT mean rushing. These are different things.**

Rushing produces: compressed content, skipped sections, combined findings, abbreviated
research, and content that looks done but isn't. This is worse than stopping to ask.

**What "don't rush" means concretely:**
- Each phase gets the same research depth as the first phase — no shortcuts
- Each finding is applied as a discrete, precise edit — not batched into vague rewrites
- Research agents run in parallel where independent, but results are fully read before applying
- No combining multiple unrelated changes into a single edit to "save time"
- No summarising research findings — apply every specific finding or note why it was skipped
- The work is finished when every item is verified and every correction is applied — not when it looks approximately done

**If a step genuinely requires a decision the user must make**, ask exactly one
specific question, state the two options clearly, then wait. Do not proceed past a
genuine fork. Do not invent a decision to avoid asking.

### Rule 4: Safety First — Always

Linux content can cause irreversible damage if written carelessly. Before publishing
any command that could destroy data or destabilize a system:

- Add an explicit `⚠️ WARNING` before dangerous commands (`rm -rf`, `dd`, `mkfs`, `fdisk`, etc.)
- Always suggest testing in a VM or container before running on a real system
- Never write `rm -rf` without showing how to verify the path first
- Explain what elevated privilege (`sudo`) actually does in the specific context shown

---

## Project Structure

```
ArtOfLinux/
├── CLAUDE.md                          ← you are here
├── README.md                          ← root navigation
├── roadmap/
│   └── README.md                      ← learning path, phase ordering, checkpoints
├── bible/
│   └── README.md                      ← complete curriculum table of contents
│   └── phase-1-getting-comfortable/   ← topic files go here (one file per topic)
│   └── phase-2-filesystem/
│   └── ...
└── docs/
    ├── content-writing-guide.md       ← MUST READ before writing bible files
    └── roadmap-writing-guide.md       ← MUST READ before editing the roadmap
```

## Key Files

| File | Purpose |
|---|---|
| `docs/content-writing-guide.md` | Mandatory template for every bible topic file |
| `docs/roadmap-writing-guide.md` | Mandatory structure for the learning roadmap |
| `roadmap/README.md` | The learning path — phases, topics, checkpoints |
| `bible/README.md` | Complete curriculum bible — table of contents |

## Curriculum Overview

14 phases of Linux teaching content:

| Phase | Name |
|---|---|
| 1 | Getting Comfortable with Linux |
| 2 | The Linux Filesystem |
| 3 | File Operations & Permissions |
| 4 | Text Processing & The Unix Philosophy |
| 5 | Shell & Scripting |
| 6 | Processes & System Resources |
| 7 | Users, Groups & Authentication |
| 8 | Package Management |
| 9 | Networking |
| 10 | Storage & Filesystems |
| 11 | Init Systems & Service Management |
| 12 | Performance & Observability |
| 13 | Security |
| 14 | Advanced Topics |

Each phase has topics numbered `N.X`. Each topic lives in its own file under
`bible/phase-N-name/N.X-topic-name.md`.

---

## Before Starting Any Writing Task

Run through this checklist before writing a single word of content:

- [ ] Have I read `docs/content-writing-guide.md` (for bible files)?
- [ ] Have I read `docs/roadmap-writing-guide.md` (for roadmap edits)?
- [ ] Have I used web search to verify command syntax and flags?
- [ ] Have I checked distro-specific differences where relevant?
- [ ] Have I added safety warnings for any dangerous commands?
- [ ] Do I know which phase and topic number this content belongs to?
- [ ] Do I know the previous and next topic for navigation links?
