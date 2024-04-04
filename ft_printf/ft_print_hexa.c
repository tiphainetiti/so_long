/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:58:21 by tlay              #+#    #+#             */
/*   Updated: 2023/12/07 17:10:36 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nb, char input)
{
	int				len;
	unsigned int	base;
	char			*str_base;

	len = 0;
	base = 16;
	if (!nb)
	{
		write(1, "0", 1);
		return (1);
	}
	if (input == 'x')
		str_base = "0123456789abcdef";
	else
		str_base = "0123456789ABCDEF";
	if (nb >= base)
		len += ft_print_hexa(nb / base, input);
	ft_putchar(str_base[nb % base]);
	return (len + 1);
}

// int	main(void)
//{
//	unsigned int number;

//	number = 9223372036854775807LL;
//	printf(" -%d\n", ft_print_hexa(number, 'X'));
//	printf("%llX", number);
//	ft_putchar('\n');
//	return (0);
//}