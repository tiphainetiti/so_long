/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:18:00 by tlay              #+#    #+#             */
/*   Updated: 2023/12/15 13:28:34 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formats(va_list args, const char input)
{
	int	result;

	result = 0;
	if (input == 'c')
		result += ft_print_char(va_arg(args, int));
	else if (input == 's')
		result += ft_print_str(va_arg(args, char *));
	else if (input == 'p')
		result += ft_print_ptr(va_arg(args, void *));
	else if (input == 'd' || input == 'i')
		result += ft_print_nbr(va_arg(args, long long));
	else if (input == 'u')
		result += ft_print_unsigned(va_arg(args, unsigned long long));
	else if (input == 'x' || input == 'X')
		result += ft_print_hexa(va_arg(args, unsigned int), input);
	else if (input == '%')
		result += ft_print_percent();
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		result;
	va_list	args;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			result += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (result);
}
//#include <stdio.h>

// int	main(void)
//{
//	char	x;
//	char	*y;

//	x = 1;
//	y = &x;
//	ft_printf("MY c = %c\n", 'a');
//	printf("real c = %c\n", 'a');
//	ft_printf("MY s = %s\n", "ab c1 !");
//	printf("real s = %s\n", "ab c1 !");
//	ft_printf("MY p = %p\n", y);
//	printf("real p = %p\n", y);
//	ft_printf("MY d & i = %d || %i\n", -1, INT_MIN);
//	printf("real d & i = %d || %i\n", -1, INT_MIN);
//	ft_printf("MY u = %u\n", INT_MAX);
//	printf("real u = %u\n", INT_MAX);
//	ft_printf("MY x = %x\n", 42);
//	printf("real x = %x\n", 42);
//	ft_printf("MY X = %X\n", 42);
//	printf("real X = %X\n", 42);
//	ft_printf("MY percent = %%\n");
//	printf("real percent = %%\n");
//	printf("MY NULL = %i\n", ft_printf(NULL));
//	printf("real NULL = %i\n", printf(NULL));
//	return (0);
//}
