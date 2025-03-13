/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:40:29 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/13 13:39:07 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_is(va_list args, char format, int *count)
{
    if (format == 'c')
        ft_print_c(va_arg(args, int), count);
    else if (format == 's')
        ft_print_s(va_arg(args, char *), count);
    else if (format == 'p')
        ft_print_p(va_arg(args, void *), count);
    else if (format == 'd' || format == 'i')
        ft_putnbr(va_arg(args, int), count);
    else if (format == 'u')
        ft_print_u(va_arg(args, unsigned int), count);
    else if (format == 'x')
        ft_print_x_minus(va_arg(args, unsigned int), count);
    else if (format == 'X')
        ft_print_x_mayus(va_arg(args, unsigned int), count);
    else if (format == '%')
        ft_print_c('%', count);
    return (*count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				format_is(args, *str++, &count);
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int main(void)
{
    // Test character
    ft_printf("returns = %d bytes\n\n", ft_printf("format c = %c %c %c\n", 'a', 'b', 'c'));
    printf("returns = %d bytes\n\n", printf("format c = %c %c %c\n", 'a', 'b', 'c'));

    // Test string
    ft_printf("returns = %d bytes\n\n", ft_printf("format s = %s %s %s\n", "hello", "world", "test"));
    printf("returns = %d bytes\n\n", printf("format s = %s %s %s\n", "hello", "world", "test"));

    // Test integer
    ft_printf("returns = %d bytes\n\n", ft_printf("format d = %d %d %d\n", 1, -2, 3));
    printf("returns = %d bytes\n\n", printf("format d = %d %d %d\n", 1, -2, 3));

    // Test unsigned integer
    ft_printf("returns = %d bytes\n\n", ft_printf("format u = %u %u %u\n", 1, 2, 3));
    printf("returns = %d bytes\n\n", printf("format u = %u %u %u\n", 1, 2, 3));

    // Test hexadecimal (lowercase)
    ft_printf("returns = %d bytes\n\n", ft_printf("format x = %x %x %x\n", 1, 42, 255));
    printf("returns = %d bytes\n\n", printf("format x = %x %x %x\n", 1, 42, 255));

    // Test hexadecimal (uppercase)
    ft_printf("returns = %d bytes\n\n", ft_printf("format X = %X %X %X\n", 1, 42, 255));
    printf("returns = %d bytes\n\n", printf("format X = %X %X %X\n", 1, 42, 255));

    // Test pointer
    ft_printf("returns = %d bytes\n\n", ft_printf("format p = %p %p %p\n", &ft_printf, &main, NULL));
    printf("returns = %d bytes\n\n", printf("format p = %p %p %p\n", &ft_printf, &main, NULL));

    // Test percent sign
    ft_printf("returns = %d bytes\n\n", ft_printf("format %% = %%\n"));
    printf("returns = %d bytes\n\n", printf("format %% = %%\n"));

    return 0;
}