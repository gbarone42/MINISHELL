/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:19:47 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/07 17:21:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int main(void)
{
	char *input = "22222222222";

	ft_printf("\t\t%s\n", input);
	ft_printf("ft_atoi:\t%d\n", ft_atoi(input));
	ft_printf("atoi:\t\t%d\n", atoi(input));
	return (0);
}

