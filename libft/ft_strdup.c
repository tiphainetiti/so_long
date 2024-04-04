/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:04:39 by tlay              #+#    #+#             */
/*   Updated: 2024/01/04 14:55:09 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*table;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	table = (char *)malloc((size + 1) * sizeof(char));
	if (!table)
		return (NULL);
	while (s[i] && i < size)
	{
		table[i] = s[i];
		i++;
	}
	table[i] = '\0';
	return (table);
}
/*
int	main(void)
{
	const char	*original = "Hello, world!";
	char		*duplicate;

	duplicate = ft_strdup(original);
	if (duplicate != NULL)
	{
		printf("Chaîne originale : %s\n", original);
		printf("Copie : %s\n", duplicate);
		free(duplicate); // Libérer la mémoire allouée pour la copie
	}
	else
	{
		fprintf(stderr, "Erreur lors de la duplication de la chaîne.\n");
	}
	return (0);
}*/