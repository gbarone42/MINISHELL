#include "../../include/minishell.h"





// int	ft_isvalid(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strlen(s) < 1 || ft_strlen(s) > INPUT_SIZE)
// 		return (1);
// 	while (s[i])
// 	{
// 		if (s[i] < 32 && s[i] == 127) //should it be '||' or '&&' //This function's logic needs clarification.
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }


int ft_isvalid(const char *input)
{
    if (input == NULL)
	{
        return 0; // Invalid input
    }
    size_t length = ft_strlen(input);
    if (length == 0 || length > INPUT_SIZE)
	{
        return 0; // Invalid input due to length constraints
    }
    size_t i = 0; // Declare i once
    while (input[i])
	{
        if (input[i] < 32 || input[i] == 127)
		{ // Use logical OR to check for control characters
            return 0;
        }
        i++;
    }
    return 1; // Input is valid
}




// int ft_isvalid(const char *input) {
//     // Check if input is NULL
//     if (input == NULL) {
//         return 0; // Invalid input
//     }

//     // Check the length of the input to be at least 1 character
//     size_t length = strlen(input);
//     if (length == 0) {
//         return 0; // Invalid input
//     }

//     // Add more specific checks based on what 'valid' means for your application
//     // For example, checking for alphanumeric characters only:
//     for (size_t i = 0; i < length; ++i) {
//         if (!isalnum((unsigned char)input[i])) {
//             return 0; // Invalid input
//         }
//     }

//     // If input passes all checks, return 1 indicating it's valid
//     return 1;
// }