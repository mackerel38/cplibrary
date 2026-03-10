#!/usr/bin/env bash
set -euo pipefail

# start ssh-agent if needed
if ! ssh-add -l >/dev/null 2>&1; then
  eval "$(ssh-agent -s)"
  ssh-add ~/.ssh/id_ed25519
fi

MSG=${1:-"update"}

echo "[verify_push] running verify"
oj-verify run

echo "[verify_push] generating docs"
oj-verify docs

git add .

if git diff --cached --quiet; then
  echo "nothing to commit"
else
  git commit -m "$MSG"
  git push
fi
