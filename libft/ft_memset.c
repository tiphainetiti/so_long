/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:07:51 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:14:18 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t numElements;

	numElements = sizeof(arr) / sizeof(arr[0]);
	printf("Tableau avant l'appel à ft_memset :\n");
	for (size_t i = 0; i < numElements; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	ft_memset(arr, 0, sizeof(arr));
	printf("Tableau après l'appel à ft_memset :\n");
	for (size_t i = 0; i < numElements; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return (0);
}*/