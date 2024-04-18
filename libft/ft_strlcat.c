/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:44:31 by tlay              #+#    #+#             */
/*   Updated: 2023/11/23 17:17:50 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlength;

	if (!dst && size <= 0)
		return (0);
	i = 0;
	dlength = ft_strlen(dst);
	if (dlength >= size)
		dlength = size;
	if (dlength < size - 1 && size > 0)
	{
		while (src[i] && dlength + i < size - 1)
		{
			dst[dlength + i] = src[i];
			i++;
		}
		dst[dlength + i] = '\0';
	}
	return (dlength + ft_strlen(src));
}
