/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:16:39 by tlay              #+#    #+#             */
/*   Updated: 2023/11/21 21:26:23 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizeint(int nb)
{
	int	size;

	size = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	long	nb;
	char	*table;

	size = ft_sizeint(n);
	nb = n;
	table = (char *)malloc(sizeof(char) * (size + 1));
	if (!table)
		return (NULL);
	if (n == 0)
		table[0] = '0';
	table[size] = '\0';
	if (n < 0)
		nb = -nb;
	while (size > 0)
	{
		table[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		table[0] = '-';
	return (table);
}
/*#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int num;
	char *result;

	num = -2147483647;
	result = ft_itoa(num);
	if (result)
	{
		printf("Integer: %d\n", num);
		printf("String: %s\n", result);
		// N'oubliez pas de libérer la mémoire allouée
		free(result);
	}
	else
	{
		printf("Erreur lors de l'allocation mémoire.\n");
	}
	return (0);
}*/