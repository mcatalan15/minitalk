/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:06 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/05/02 19:07:01 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function that add a given character to a given string */

void	ft_add_str(char *str, char character)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = character;
}	
