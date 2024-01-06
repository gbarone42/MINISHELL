#!/bin/bash
MINISHELL="../build/minishell"

cd "$(dirname "$0")"

for test_script in *.sh; do

    if [ "$test_script" == "run_tests.sh" ]; then
        continue
    fi

    echo "Running $test_script..."
    bash_output=$(bash "$test_script")
    minishell_output=$("$MINISHELL" < "$test_script")

    if [ "$bash_output" == "$minishell_output" ]; then
        echo "Test $test_script passed!"
    else
        echo "Test $test_script failed!"
        echo "Expected:"
        echo "$bash_output"
        echo "Got:"
        echo "$minishell_output"
    fi
done