/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:50:12 by ialashqa          #+#    #+#             */
/*   Updated: 2024/04/20 20:58:46 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int sig)
{
	static unsigned char	c;
	static int				bit;

	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printfchar(c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printfint(getpid());
	ft_printfchar('\n');
	sa.sa_handler = &handle_signal;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
