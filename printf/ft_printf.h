/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:54:12 by dpadenko          #+#    #+#             */
/*   Updated: 2023/10/03 20:19:24 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_digit(int n);
int	ft_print_hex(unsigned int n, const char specifier);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_str(char *s);
int	ft_print_undigit(unsigned int n);

#endif
