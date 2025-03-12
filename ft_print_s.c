/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:20:46 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/12 16:36:18 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_print_c(str[i], count);
		i++;
	}
}
