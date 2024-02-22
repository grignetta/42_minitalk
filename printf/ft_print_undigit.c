/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:34:41 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/21 19:37:44 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uni_to_a(unsigned int n, int *count)
{
	if (n / 10 != 0)
		ft_uni_to_a(n / 10, count);
	ft_putchar_fd(((n % 10) + '0'), 1);
	(*count)++;
	return ;
}

int	ft_print_undigit(unsigned int n)
{
	int		count;

	count = 0;
	ft_uni_to_a(n, &count);
	return (count);
}
