/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:40:29 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/13 09:56:15 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_is(va_list args, char format, int *count)
{
	if (format == 'c')
		ft_print_c(va_arg(args, int), count);
	if (format == 's')
		ft_print_s(va_arg(args, char *), count);
	if (format == 'p')
		ft_print_p(va_arg(args, char *), count);
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (format == 'u')
		ft_print_u(va_arg(args, unsigned int), count);
	if (format == 'x')
		ft_print_x_minus(va_arg(args, unsigned int), count);
	if (format == 'X')
		ft_print_x_mayus(va_arg(args, unsigned int), count);
	if (format == '%')
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
	ft_printf("%d\n\n", ft_printf("format c = %c %c %c\n", 'x', 'x', 'x'));
	printf("%d\n\n", printf("format c = %c %c %c\n", 'x', 'x', 'x'));

	// Test string
	ft_printf("returns = %d bytes\n\n", ft_printf("format s = %s\n", "str"));
	printf("returns = %d bytes\n\n", printf("format s = %s\n", "str"));

	// Test integer
	ft_printf("returns = %d bytes\n\n", ft_printf("%d\n", 47483648));
	printf("returns = %d bytes\n\n", printf("%d\n", 47483648));

 	// Test integer with negative value
 	ft_printf("returns = %d bytes\n\n", ft_printf("format d = %d\n", -42));
	printf("returns = %d bytes\n\n", printf("format d = %d\n", -42));

	// Test integer with INT_MAX
	ft_printf("returns = %d bytes\n\n", ft_printf("format d = %d\n", INT_MAX));
	printf("returns = %d bytes\n\n", printf("format d = %d\n", INT_MAX));

	// Test integer with INT_MIN
	ft_printf("returns = %d bytes\n\n", ft_printf("format d = %i\n", INT_MIN));
	printf("returns = %d bytes\n\n", printf("format d = %i\n", INT_MIN));

	// Test unsigned integer
	ft_printf("returns = %d bytes\n\n", ft_printf("format u = %u\n", 42));
	printf("returns = %d bytes\n\n", printf("format u = %u\n", 42));

	// Test unsigned integer with negative value
	ft_printf("returns = %d bytes\n\n", ft_printf("format u = %u\n", -42));
	printf("returns = %d bytes\n\n", printf("format u = %u\n", -42));

	// Test unsigned integer with UINT_MAX
	ft_printf("returns = %d bytes\n\n", ft_printf("format u = %u\n", UINT_MAX));
	printf("returns = %d bytes\n\n", printf("format u = %u\n", UINT_MAX));

	// Test hexadecimal (lowercase)
	ft_printf("returns = %d bytes\n\n", ft_printf("format x = %x\n", 42));
	printf("returns = %d bytes\n\n", printf("format x = %x\n", 42));

	// Test hexadecimal (uppercase)
	ft_printf("returns = %d bytes\n\n", ft_printf("format X = %X\n", 42));
	printf("returns = %d bytes\n\n", printf("format X = %X\n", 42));

	// Test pointer
	ft_printf("returns = %d bytes\n\n", ft_printf("format p = %p\n", &ft_printf));
	printf("returns = %d bytes\n\n", printf("format p = %p\n", &ft_printf));
	
	// Test NULL pointer
	ft_printf("returns = %d bytes\n\n", ft_printf("format p = %p\n", NULL));
	printf("returns = %d bytes\n\n", printf("format p = %p\n", NULL));

	// Test percent sign
	ft_printf("returns = %d bytes\n\n", ft_printf("format %% = %%\n"));
	printf("returns = %d bytes\n\n", printf("format %% = %%\n"));

	// Test all
	ft_printf("returns = %d bytes\n\n", ft_printf("All = %d %i %u %x %X %p %%\n", 1, -2, 3, 42, 52, &ft_printf));
	printf("returns = %d bytes\n\n", printf("All = %d %i %u %x %X %p %%\n", 1, -2, 3, 42, 52, &ft_printf));
	return 0;
}