#!/bin/bash

MINISHELL="build/minishell"
TMP_FILE="tests/tokens.txt"


for token in $(cat $TMP_FILE); do
    minishell_output=$($MINISHELL $token | awk 'NR==1 {print $2}')
    token=$(echo $token | sed 's/\\//g')
    bash_output=$(bash -c "echo $token")
    

    if [ "$bash_output" != "$minishell_output" ]; then
        echo "Errore nel token: $token"
        echo "Bash output: $bash_output"
        echo "Minishell output: $minishell_output"
        break
    fi
done
        echo "tutti i test corretti"

#while IFS= read -r token; do

 #   bash_output=$(bash $TMP_FILE)

  #  minishell_output=$($MINISHELL $TMP_FILE | awk 'NR==1 {print $2}')

   # if [ "$bash_output" != "$minishell_output" ]; then
    #    echo "Errore nel token: $token"
     #   echo "Bash output: $bash_output"
     #   echo "Minishell output: $minishell_output"
   # else
    #    echo "Token $token gestito correttamente"
   # fi
#done < "tokens.txt"
