/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:01:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/12/12 11:12:44 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static int	i = 0;
	static char	c = 0;

	c = c << 1;
	i++;
	if (signum == SIGUSR2)
		c = c | 0x01;
	if (i == 8)
	{
		ft_putchar(c);
		if (c == '\0')
			ft_printf("\nConnection Closed\n");
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		if (signal(SIGUSR1, sig_handler) == SIG_ERR
			|| signal(SIGUSR2, sig_handler) == SIG_ERR)
		{
			ft_printf("Error setting signal handlers\n");
			exit(EXIT_FAILURE);
		}
		ft_printf("Server PID: %d\n", getpid());
		while (1)
			pause();
	}
	return (0);
}
