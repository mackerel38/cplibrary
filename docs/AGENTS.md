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
config/
scripts/
docs/

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

Config rules (日本語):
- ドキュメントの先頭には YAML front matter を入れてください。形式は以下のとおりです。
  ---
  title: [タイトル]
  documentation_of: [ライブラリのパス(例: //structure/segtree.hpp)]
  ---
- config/<category>/<name>.md にドキュメントを作成すること。
- 各ドキュメントは必ず先頭に "Definition"（操作の定義）と "Complexity"（計算量：Big-O）を書くこと。
- ドキュメント本文は日本語で書くこと。

Docs front-matter 例（必須）:
---
title: セグメント木
documentation_of: structure/segtree.hpp
---

Commit & push conventions:
- Use SSH remote (git@github.com:...).
- Commit message default: "update: <short description>".
- Scripts must be used for verify+docs+push automation.

Script usage (available scripts/):
- scripts/push.sh [commit-message]  -> git add/commit/push
- scripts/verify_push.sh [commit-message] -> run oj-verify run, oj-verify docs, copy .verify-helper/markdown -> docs, git add/commit/push

Codex instructions (how to interact):
- Read AGENTS.md first.
- When ready to apply changes, ask to run one of the scripts by name:
  e.g. "Run scripts/verify_push.sh 'add segtree'"
- If tests fail, report errors and propose fixes; do not auto-force-push failing commits.
- Always run scripts/verify_push.sh after implementing a new library.