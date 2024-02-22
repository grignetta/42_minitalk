/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:48:42 by dpadenko          #+#    #+#             */
/*   Updated: 2023/10/11 09:08:10 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char (va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit (va_arg(ap, int));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (specifier == 'u')
		count += ft_print_undigit(va_arg(ap, unsigned long));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else if (specifier == '\0')
		count += write(1, "%", 1);
	else
	{
		count += write(1, "%", 1);
		count += write(1, &specifier, 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(ap);
	return (count);
}
/*
int main()
{
	//ft_printf("%w  %%  %");
	//ft_printf("%w  %%  ", "hello");
	//printf("%d", printf("%w%"));
	//printf("New line:/n");
	printf("%d", ft_printf("%w  %"));
	//printf("%   %");
}
*/
