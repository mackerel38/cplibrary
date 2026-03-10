This repository is a competitive programming C++ library.

Compiler:
C++23 (gcc 15.2.0)

Directory structure:
graph/
structure/
math/
geometry/
other/
verify/
docs/
scripts/

Rules for code generation:
- Each library must be header-only (.hpp).
- Each header must start with:
  #pragma once
  #include <bits/stdc++.h>
  using namespace std;
- Do not use "bit" as variable
- No inline comments in code.
- Keep function/class names short and idiomatic for CP.
- Prefer templates and header-only utilities.
- Allow including other headers from this repo to avoid duplication.
- Combine very common helpers (e.g., modint + comb) into one file.

Verification rules:
- Use online-judge-verify-helper (oj-verify).
- Put tests in verify/ named: [site]_[problem_or_id][_n].test.cpp
- Test files must start with:
  #define PROBLEM "https://..."
  #include "<relative path to required .hpp>"
- If verify URL is provided, create test file; otherwise skip.

Docs rules:
- Write in Japanese.
- Put markdown for each module at docs/<category>/<name>.md
- Each doc must start with "Definition" (operations) and "Complexity" with big-O.
- Show a minimal usage snippet.

Commit & push conventions:
- Use SSH remote (git@github.com:...).
- Commit message default: "update: <short description>".
- Scripts must be used for verify+docs+push automation.

Script usage (available scripts/):
- scripts/push.sh [commit-message]  -> git add/commit/push
- scripts/verify_push.sh [commit-message] -> run oj-verify run, oj-verify docs, git add/commit/push

Codex instructions (how to interact):
- Read AGENTS.md first.
- When ready to apply changes, ask to run one of the scripts by name:
  e.g. "Run scripts/verify_push.sh 'add segtree'"
- If tests fail, report errors and propose fixes; do not auto-force-push failing commits.
- Always run scripts/verify_push.sh after implementing a new library.
