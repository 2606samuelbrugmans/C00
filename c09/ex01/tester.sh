#!/bin/bash
output=$(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +")
if [ "$output" != "Result: 42" ]; then
    echo "Test failed: expected 'Result: 42' but got '$output'"
else
    echo "Test 1 passed"
fi
output=$(./RPN "7 7 * 7 -")
if [ "$output" != "Result: 42" ]; then
    echo "Test failed: expected 'Result: 42' but got '$output'"
else
    echo "Test 2 passed"
fi
output=$(./RPN "1 2 * 2 / 2 * 2 4 - +")
if [ "$output" != "Result: 0" ]; then
    echo "Test failed: expected 'Result: 0' but got '$output'"
else
    echo "Test 3 passed"
fi
output=$(./RPN "(1 + 1)")
if [ "$output" != "Error: invalid character found" ]; then
    echo "Test failed: expected 'Error: invalid character found' but got '$output'"
else
    echo "Test 4 passed"
fi
output=$(./RPN "1 2 + +")
if [ "$output" != "Error: not enough numbers in the stack" ]; then
    echo "Test failed: expected 'Error: not enough numbers in the stack' but got '$output'"
else
    echo "Test 5 passed"
fi
