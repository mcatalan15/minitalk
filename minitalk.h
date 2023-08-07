/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:01:31 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/08/07 17:55:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/time.h>

// server.c
void	sig_handler(int signum);

// client.c
void	ft_binari(int pid, char msg);
void	ft_print_error(void);

#endif