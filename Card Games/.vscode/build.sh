#!/bin/bash
DIR="$(cd "$(dirname "$0")" && pwd)"
ACTIVE="$1"
OUTPUT="${ACTIVE%.cpp}"

# Collect all .cpp files EXCEPT other "main" files
# Only compile: the active file + class implementation files (no main)
HELPERS=()
for f in "$DIR"/*.cpp; do
    if [ "$f" != "$ACTIVE" ]; then
        # Only include if it does NOT contain a main function
        if ! grep -q "int main" "$f"; then
            HELPERS+=("$f")
        fi
    fi
done

echo "Building: $ACTIVE ${HELPERS[@]}"
g++ -g -std=c++17 -I "$DIR" "$ACTIVE" "${HELPERS[@]}" -o "$OUTPUT"