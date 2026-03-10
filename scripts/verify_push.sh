#!/usr/bin/env bash
set -euo pipefail

MSG=${1:-"update: $(date -Iseconds)"}
echo "[verify_push] commit message: $MSG"

echo "[verify_push] running oj-verify..."
oj-verify run

echo "[verify_push] generating docs..."
oj-verify docs

echo "[verify_push] staging docs and changes..."
git add .

# If nothing to commit, continue gracefully
if git diff --cached --quiet; then
  echo "[verify_push] nothing to commit"
else
  git commit -m "$MSG"
  echo "[verify_push] pushing to origin (SSH remote expected)..."
  git push
fi
echo "[verify_push] done"
