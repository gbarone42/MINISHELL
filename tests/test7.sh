#!/bin/bash
echo "It's challenging to mix 'single' and \"double\" quotes correctly."
echo 'He said, "She said, '\''It\'s complicated.'\''"'
echo "A \"quote\" 'inside' another \"quote\""
echo 'This example uses '\''multiple'\'' '\''single'\'' '\''quotes'\'' concatenated.'
echo "A complex \"example\" with 'mixed' \"quotes\" and a backslash \\"
echo 'What about "nested \"double quotes\" inside" single quotes?'
echo "And 'nested \'single quotes\' inside' double quotes?"
echo "This is a \"complex $(echo 'nested') example\""
echo 'A '\''single quote'\'' inside '\''single quotes'\'' with an escape: \'