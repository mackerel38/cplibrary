#!/usr/bin/env bash
set -euo pipefail

MSG=${1:-"update: $(date -Iseconds)"}
echo "[verify_push] message: $MSG"

# Ensure LF endings (safety) -- no-op if already LF
# (This helps if files were checked out with CRLF.)
if command -v dos2unix >/dev/null 2>&1; then
  echo "[verify_push] normalizing line endings (dos2unix)..."
  find . -type f -name "*.sh" -o -name "*.md" -o -name "*.hpp" -o -name "*.cpp" | xargs -r dos2unix 2>/dev/null || true
fi

# start ssh-agent if needed, try to add default key
if ! ssh-add -l >/dev/null 2>&1; then
  echo "[verify_push] starting ssh-agent and adding key..."
  eval "$(ssh-agent -s)"
  # silence errors if key not present; if passphrase-protected, it will prompt once here
  ssh-add ~/.ssh/id_ed25519 || true
fi

echo "[verify_push] running oj-verify run..."
oj-verify run

echo "[verify_push] running oj-verify docs..."
oj-verify docs

# copy generated markdown from .verify-helper/markdown into docs/
SRC_DIR=".verify-helper/markdown"
DST_DIR="docs"

if [ -d "$SRC_DIR" ]; then
  echo "[verify_push] copying generated docs from $SRC_DIR to $DST_DIR..."
  mkdir -p "$DST_DIR"
  # use rsync if available for safe merge; fallback to cp
  if command -v rsync >/dev/null 2>&1; then
    rsync -a --delete "$SRC_DIR"/ "$DST_DIR"/
  else
    # remove only files that exist in src and copy
    # safer: copy recursively, overwrite existing
    cp -r "$SRC_DIR"/* "$DST_DIR"/ 2>/dev/null || true
  fi
else
  echo "[verify_push] no generated docs at $SRC_DIR; skipping copy."
fi

echo "[verify_push] staging changes..."
git add .

# if staging area is empty, do nothing
if git diff --cached --quiet; then
  echo "[verify_push] nothing to commit"
else
  echo "[verify_push] committing..."
  git commit -m "$MSG"
  echo "[verify_push] pushing to origin..."
  git push
fi

echo "[verify_push] done"