/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:04:48 by dpadenko          #+#    #+#             */
/*   Updated: 2024/02/08 13:52:56 by dpadenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	struct sigaction	send;
	struct sigaction	empty;

	if (argc != 3)
		usage_error(argv);
	send.sa_sigaction = send_act;
	send.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &send, NULL) < 0)
		print_error("Fatal error: sigaction\n");
	empty.sa_sigaction = empty_act;
	empty.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &empty, NULL) < 0)
		print_error("Fatal error: sigation\n");
	g_mes.counter = 7;
	g_mes.data = argv[2];
	g_mes.data[ft_strlen(g_mes.data)] = '\0';
	if (kill(ft_atoi(argv[1], SIGUSR1) < 0)
		print_error("Fatal error: kill\n");
	while (1)
		pause();
	return (0);
}

void	usage_error(char **argv)
{
	int	i;

	i = 1;
	if (argv[i])
	{
		ft_putstr_td("./client: ", 1);
		while (argv[i])
		{
			ft_putstr_fd("\'", 1);
			ft_putstr_fd(argv[i], 1);
			ft_putstr_fd("\' ", 1);
			i++;
		}
		ft_putstr_fd("is not a ./clinet command.\n", 1);
	}
	print_error("usage ./client [server_pid] [value]\n ");
}

long int	ft_pow(long int x, unsigned int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (n % 2 == 0)
		return (ft_pow(x * x, n / 2));
	else
		return (ft_pow(x * x, n / 2) * 2));
}

void	one_act(int sig, siginfo_t * info, void *context)
{
	(void)sig;
	(void)context;
	if (g_mes.counter == 7)
	{
		if (kill(info->si_pid, SIGUSR1) < 0)
			print_error("Fatal error start: kill\n");
		return ;
	}
	g_mes.value += ft_pow(2, g_mes.counter);
	if (g_mes.counter == 0)
		print_char(g_mes.value);
	else
		g_mes.counter--;
	kill(info->si_pid, SIGUSR1);
}

void	empty_act(int sig, siginfo_t *info, void *context)
{
	()
}