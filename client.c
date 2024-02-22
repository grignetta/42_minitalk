/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:04:48 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/22 09:48:57 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_confirmed;

void	wait_for_confirmation(void)
{
	while (!g_confirmed)
		pause();
	g_confirmed = 0;
}

void	confirm_act(int signum)
{
	(void)signum;
	g_confirmed = 1;
}

void	send_bit(int pid, char c)
{
	int	bit;
	int	bit_value;

	bit = 7;
	while (bit >= 0)
	{
		bit_value = (c >> bit--) & 1;
		if (bit_value)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				write(2, "Error sending bit\n", 18);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				write(2, "Error sending bit\n", 18);
				exit(1);
			}
		}
		wait_for_confirmation();
	}
}

void	send_message(int pid, const char *message)
{
	char	c;

	while (*message)
	{
		send_bit(pid, *message);
		message++;
	}
	c = '\0';
	send_bit(pid, c);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(2, "Error Input: ./client [server_pid] [message]\n", 45);
		return (1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 4194304)
	{
		write(2, "Error: PID should be > 0 and < 4194305\n", 39);
		return (1);
	}
	sa.sa_handler = &confirm_act;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error setting up signal handler\n", 32);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
