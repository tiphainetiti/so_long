/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:45:25 by tlay              #+#    #+#             */
/*   Updated: 2023/11/17 15:32:46 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s);
	ch = (char)c;
	if (!s)
		return ((char *)&s[0]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	if (!ch)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	const char s[] = "bonjour";
	char ch = 's';

	printf("%p\n", ft_strrchr(s, ch));
	printf("%p\n", strrchr(s, ch));
}*/