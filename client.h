/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:02:44 by dpadenko          #+#    #+#             */
/*   Updated: 2025/08/26 15:57:23 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define _POSIX_C_SOURCE 199309L
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

extern volatile sig_atomic_t	g_confirmed;

void	wait_for_confirmation(void);
void	confirm_act(int signum);
void	send_message(int pid, const char *message);
void	send_bit(int pid, char c);

#endif
