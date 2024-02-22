/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:36:33 by dpadenko          #+#    #+#             */
/*   Updated: 2023/10/03 20:30:25 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	ft_put_hex(unsigned int n, const char specifier)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, specifier);
		ft_put_hex(n % 16, specifier);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (specifier == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (specifier == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char specifier)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, specifier);
	return (ft_hex_count(n));
}
