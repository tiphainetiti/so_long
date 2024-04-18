/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:20 by tlay              #+#    #+#             */
/*   Updated: 2024/03/20 20:26:56 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && i < (n - 1))
		i++;
	return (str1[i] - str2[i]);
}

//#include <stdio.h>

// int	main(void)
//{
//	const char	s1[] = "1";
//	const char	s2[] = "1";

//	printf("%d\n", ft_strncmp(s1, s2, 6));
//	// printf("%d\n", strncmp(s1, s2, 6));
//}
