/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:12:22 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:07:16 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// void	*ft_memchr(const void *s, int c, size_t n)
//{
//	size_t i;

//	i = 0;
//	while (i < n)
//	{
//		if (*(unsigned char *)(s + i) == (unsigned char)c)
//			return ((void *)(s + i));
//		i++;
//	}
//	return (NULL);
//}