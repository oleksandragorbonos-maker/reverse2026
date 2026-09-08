# Reverse Engineering Course Materials

This repository stores the course guide, laboratory assignments, source code, submitted work, examples, and reference disassembly outputs.

## Repository layout

| Path | Contents |
| --- | --- |
| [`materials/`](materials/) | Shared course documents and instructions |
| [`labs/`](labs/) | Numbered laboratory work |
| [`labs/lab-01/`](labs/lab-01/) | First laboratory: submissions, examples, and task files |

Each lab keeps its implementation files under `tasks/`. Generated `.cod` and `.lst` files are retained under the relevant task's `reference/` directory so they can be compared with the source code.

## Naming conventions

- Use lowercase English names with hyphens for directories and document filenames.
- Use `task-01`, `task-02`, and so on for assignment parts.
- Keep source code in `source/`.
- Keep platform-specific disassembly and listing files in `reference/<platform>/`.
- Keep completed documents in `submissions/` and examples in `examples/`.
