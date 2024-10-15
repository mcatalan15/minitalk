/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:38 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/22 20:19:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_error(void)
{
	ft_printf("error\n");
	exit(EXIT_FAILURE);
}

void	ft_binari(int pid, char msg)
{
	int	x;
	int	bit;

	x = 0;
	while (x < 8)
	{
		bit = (msg & 0x80) >> 7;
		if (bit == 0)
		{
			if (kill (pid, SIGUSR1) == -1)
				ft_print_error();
		}
		else if (kill (pid, SIGUSR2) == -1)
			ft_print_error();
		usleep (150);
		msg = msg << 1;
		x++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			ft_binari(pid, argv[2][i]);
			i++;
		}
		ft_binari(pid, '\0');
	}
	else
		ft_printf("Wrong arguments\n");
	return (0);
}
