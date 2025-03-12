/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:38:17 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/12 16:50:44 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x_minus(unsigned int nbr, int *count)
{
	char	*hex_digits;

	hex_digits = BASE_LOWER;
	if (nbr >= 16)
	{
		ft_print_x_minus(nbr / 16, count);
	}
	ft_print_c(hex_digits[nbr % 16], count);
}
