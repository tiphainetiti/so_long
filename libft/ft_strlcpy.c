/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:55:27 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:13:59 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char dest[20];
	const char *src = "Hello, world!";
	size_t size = sizeof(dest);

	size_t result = ft_strlcpy(dest, src, size);

	printf("Result: %zu\n", result);
	printf("Destination: %s\n", dest);

	return (0);
}*/