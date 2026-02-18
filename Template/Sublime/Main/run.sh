#!/bin/bash

while true; do
    ./gen > in
    ./source < in > out
    ./brute < in > ok

    if ! diff -q out ok > /dev/null; then
        echo "Mismatch found!"
        echo "Input:"
        cat in
        echo "Your Output:"
        cat out
        echo "Correct Output:"
        cat ok
        break
    fi

    echo "✅ Test passed"
done
