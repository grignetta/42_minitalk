/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:04:48 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/22 10:20:00 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_global_msg;

void	append_to_buffer(char c)
{
	int		new_capacity;
	char	*new_buffer;
	int		i;

	if (g_global_msg.buffer_size >= g_global_msg.buffer_capacity)
	{
		new_capacity = g_global_msg.buffer_capacity * 2;
		new_buffer = malloc(new_capacity);
		if (!new_buffer)
		{
			write(2, "Failed to allocate memory\n", 26);
			free(g_global_msg.buffer);
			exit(1);
		}
		i = 0;
		while (i < g_global_msg.buffer_size)
		{
			new_buffer[i] = g_global_msg.buffer[i];
			i++;
		}
		free(g_global_msg.buffer);
		g_global_msg.buffer = new_buffer;
		g_global_msg.buffer_capacity = new_capacity;
	}
	g_global_msg.buffer[g_global_msg.buffer_size++] = c;
}

void	sigact(int sig, siginfo_t *siginfo, void *context)
{
	char	received_char;

	(void)context;
	if (sig == SIGUSR1)
		g_global_msg.value |= 1 << g_global_msg.bit_counter;
	if (--g_global_msg.bit_counter < 0)
	{
		received_char = (char)g_global_msg.value;
		if (received_char == '\0')
		{
			append_to_buffer(received_char);
			ft_printf("%s\n", g_global_msg.buffer);
			free(g_global_msg.buffer);
			initialize_global_msg();
		}
		else
			append_to_buffer(received_char);
		g_global_msg.bit_counter = 7;
		g_global_msg.value = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sigact;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Cannot handle SIGUSR1\n", 22);
		free(g_global_msg.buffer);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Cannot handle SIGUSR2\2", 22);
		free(g_global_msg.buffer);
		exit(1);
	}
}

void	initialize_global_msg(void)
{
	g_global_msg.bit_counter = 7;
	g_global_msg.value = 0;
	g_global_msg.buffer_size = 0;
	g_global_msg.buffer_capacity = 1024;
	g_global_msg.buffer = malloc(g_global_msg.buffer_capacity);
	if (g_global_msg.buffer == NULL)
	{
		write(2, "Failed to allocate initial buffer\n", 34);
		free(g_global_msg.buffer);
		exit(1);
	}
}

int	main(void)
{
	initialize_global_msg();
	setup_signal_handlers();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	free(g_global_msg.buffer);
	return (0);
}
