#!/usr/bin/env bash
set -euo pipefail

if (( $# < 2 )); then
    printf 'Usage: %s [filename] [argv...]\nExample: %s sample.txt -e\n' "$0" "$0" >&2
    exit 2
fi

project_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$project_dir/build"
executable="$build_dir/Encryption_Algorithm"
filename="$1"
shift

trap 'rm -f -- "$executable"' EXIT

cmake -S "$project_dir" -B "$build_dir"
cmake --build "$build_dir" --target Encryption_Algorithm

cd -- "$project_dir"

"$executable" "$@" "$filename"