/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:45:14 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:15:01 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	buffer[10];

	// Remplir le buffer avec des valeurs non-nulles pour la démonstration
	for (int i = 0; i < 10; i++)
	{
		buffer[i] = 'a' + i; // Cela mettra 'a', 'b', 'c', etc. dans le buffer
	}
	// Afficher le buffer avant ft_bzero
	printf("Buffer avant ft_bzero: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", buffer[i]);
	}
	printf("\n");
	// Appel de ft_bzero pour mettre à zéro le buffer
	ft_bzero(buffer, 10);
	// Afficher le buffer après ft_bzero
	printf("Buffer après ft_bzero: ");
	for (int i = 0; i < 10; i++)
	{
		if (buffer[i] == 0)
			printf("0 "); // Affiche 0 pour les caractères mis à zéro
		else
			printf("%c ", buffer[i]);
	}
	printf("\n");
	return (0);
}*/