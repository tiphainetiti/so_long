/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:24:22 by tlay              #+#    #+#             */
/*   Updated: 2023/12/05 14:14:30 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long long nbr)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(nbr);
	while (str[len])
		ft_putchar(str[len++]);
	free(str);
	return (len);
}

// int	main(void)
//{
//	printf(" -%d\n", ft_print_nbr(-1));
//	printf("vrai: %d\n", -1);
//}