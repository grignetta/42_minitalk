/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:31:26 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/21 19:54:19 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i_to_a(int n, int *count)
{
	if (n / 10 != 0)
		ft_i_to_a(n / 10, count);
	ft_putchar_fd(((n % 10) + '0'), 1);
	(*count)++;
	return ;
}

int	ft_print_digit(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	ft_i_to_a(n, &count);
	return (count);
}
