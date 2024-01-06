#!/bin/bash

MINISHELL="../build/minishell"
TMP_FILE="tmp_test_script.sh"

cd "$(dirname "$0")"

while IFS= read -r token; do
    echo "Testing token: $token"

    echo "echo $token" > $TMP_FILE

    bash_output=$(bash $TMP_FILE)

    minishell_output=$($MINISHELL $TMP_FILE | awk 'NR==1 {print $2}')

    if [ "$bash_output" != "$minishell_output" ]; then
        echo "Errore nel token: $token"
        echo "Bash output: $bash_output"
        echo "Minishell output: $minishell_output"
    else
        echo "Token $token gestito correttamente"
    fi
done < "tokens.txt"

rm $TMP_FILE