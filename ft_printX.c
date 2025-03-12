/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:42:11 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/12 16:51:03 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x_mayus(unsigned int nbr, int *count)
{
	char	*hex_digits;

	hex_digits = BASE_UPPER;
	if (nbr >= 16)
	{
		ft_print_x_mayus(nbr / 16, count);
	}
	ft_print_c(hex_digits[nbr % 16], count);
}
