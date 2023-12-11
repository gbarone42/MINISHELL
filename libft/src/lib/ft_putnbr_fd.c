/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:02:16 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/08 15:02:17 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_rec(long n, int fd)
{
	char	digit[1];

	if (n == 0)
		return ;
	ft_putnbr_fd_rec(n / 10, fd);
	digit[0] = '0' + (n % 10);
	write(fd, digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	input;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		input = n;
		if (n < 0)
		{
			write(fd, "-", 1);
			input *= -1;
		}
		ft_putnbr_fd_rec(input, fd);
	}
}
