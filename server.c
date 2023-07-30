/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:01:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/07/28 10:29:21 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static int	i = 0;
	static char	c = 0;
	// static int	count = 0;

	c = c << 1;
	i++;
	if (signum == SIGUSR2)
		c = c | 0x01;
	if (i == 8)
	{
		ft_putchar(c);
		// count++;
		if (c == '\0')
			ft_printf("\nConnection Closed");
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa;

	if (argc == 1)
	{
		sa.sa_handler = sig_handler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;

		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("\nError signal\n");
			exit(EXIT_FAILURE);
		}
		ft_printf("Server PID: %d\n", getpid());
		while (1)
		{
			
		}
	}
	return (0);
}
