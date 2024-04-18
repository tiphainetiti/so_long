/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:40 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:15:26 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char *big = "Hello, World!coucou";
	const char *little = "World";
	size_t len = 13; // Longueur de la chaîne "Hello, World!"

	char *result = ft_strnstr(big, little, len);

	if (result != NULL)
	{
		printf("Sous-chaîne trouvée : %s\n", result);
	}
	else
	{
		printf("Sous-chaîne non trouvée.\n");
	}

	return (0);
}*/