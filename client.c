/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:37:10 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/24 20:20:02 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recieved(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printfstr("Message ackowledged by server\n");
	}
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printfstr("Usage: ./client <PID> <Message>\n");
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printfstr("Error: Server PID must only contain digits.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	send_message(int pid, char *message)
{
	int	bit;

	while (*message != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((*message >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit--;
		}
		message++;
	}
	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &recieved;
	sigaction(SIGUSR1, &sa, NULL);
	if (!check_input(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
