/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:34:48 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/12 16:54:39 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long int nbr, char *base)
{
	char	str[20];
	int		i;
	int		base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	i = 19;
	str[i--] = '\0';
	if (nbr == 0)
		str[i--] = '0';
	if (nbr < 0)
	{
    	ft_print_c('-', count);
    	nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i--] = base[nbr % base_len];
		nbr /= base_len;
		count++;
	}
	write(1, &str[i + 1], 19 - i);
}
