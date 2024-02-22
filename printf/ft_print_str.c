/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:30:55 by dpadenko          #+#    #+#             */
/*   Updated: 2023/10/03 20:33:11 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write (1, s++, 1);
		count++;
	}
	return (count);
}
