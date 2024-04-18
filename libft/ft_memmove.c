/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:27:46 by tlay              #+#    #+#             */
/*   Updated: 2023/12/07 14:39:30 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (src == dest)
		return (dest);
	if (d > s && d < s + n)
	{
		i = n;
		while (i != 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}
/*
int	main(void)
{
	char str[] = "Exemple de memmove";

	// Exemple de déplacement avec chevauchement
	// Déplacer une partie de la chaîne vers la droite dans le même tableau
	printf("Avant memmove: %s\n", str);
	ft_memmove(str + 2, str + 5, 10);

	// Afficher le résultat après l'opération de memmove
	printf("Après memmove: %s\n", str);

	return (0);
}*/