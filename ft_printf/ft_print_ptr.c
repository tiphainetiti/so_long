/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:19:43 by tlay              #+#    #+#             */
/*   Updated: 2023/12/06 14:04:15 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbr_base(unsigned long nb)
{
	int				len;
	unsigned long	base;
	char			*str_base;

	len = 0;
	base = 16;
	str_base = "0123456789abcdef";
	if (nb >= base)
		len += ft_put_nbr_base(nb / base);
	ft_putchar(str_base[nb % base]);
	return (len + 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	nb;

	nb = (unsigned long)ptr;
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (write(1, "0x", 2) + ft_put_nbr_base(nb));
}
// int	main(void)
//{
//	void			*x;
//	unsigned long	*ptr;

//	x = NULL;
//	ptr = &x;
//	printf(" -%d\n", ft_print_ptr(x));
//	printf("vrai: %p\n", ptr);
//}
