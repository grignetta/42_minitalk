/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:02:29 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/21 21:09:35 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

//#define _POSIX_C_SOURCE 199309L
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_msg
{
	int		bit_counter;
	int		value;
	char	*buffer;
	int		buffer_size;
	int		buffer_capacity;
}	t_msg;

extern t_msg	g_global_msg;

void	sigact(int sig, siginfo_t *info, void *context);
void	append_to_buffer(char c);
void	setup_signal_handlers(void);
void	initialize_global_msg(void);

#endif