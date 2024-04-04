/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:24:23 by tlay              #+#    #+#             */
/*   Updated: 2023/12/07 16:13:00 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*table;

	if (nmemb > 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	table = malloc(nmemb * size);
	if (!table)
		return (NULL);
	ft_bzero(table, nmemb * size);
	return (table);
}
/*
int	main(void)
{
	size_t	nmemb;
	size_t	size;
	int		*tableau;

	nmemb = 5;
	size = sizeof(int);
	// Appel de votre fonction my_calloc
	tableau = (int *)ft_calloc(nmemb, size);
	if (tableau == NULL)
	{
		fprintf(stderr, "Échec de l'allocation mémoire.\n");
		return (1); // Quitter avec un code d'erreur
	}
	// Utilisation du tableau alloué
	for (size_t i = 0; i < nmemb; i++)
	{
		tableau[i] = i * 10;
	}
	// Affichage des valeurs du tableau
	for (size_t i = 0; i < nmemb; i++)
	{
		printf("tableau[%zu] = %d\n", i, tableau[i]);
	}
	// Libération de la mémoire allouée
	free(tableau);
	return (0); // Tout s'est bien passé
}*/