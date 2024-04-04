/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:09:18 by tlay              #+#    #+#             */
/*   Updated: 2023/12/05 15:26:57 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
		return (0);
	if (nb >= 10)
		len += ft_print_unsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (len + 1);
}
