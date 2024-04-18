/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:36:47 by tlay              #+#    #+#             */
/*   Updated: 2024/01/29 13:11:49 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static size_t	ft_size_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_put_word(const char *s, size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	while (s[i] && i < size)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	ft_protection(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		words;
	size_t	size;
	char	**result;

	if (!s)
		return (NULL);
	i = -1;
	words = ft_count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (++i < words)
	{
		while (*s && *s == c)
			s++;
		size = ft_size_word(s, c);
		result[i] = ft_put_word(s, size);
		if (!result[i])
			return (ft_protection(result), NULL);
		s += size;
	}
	result[i] = NULL;
	return (result);
}

//#include <stdio.h>

// int	main(void)
//{
//	char	**str;
//	int		i;

//	str = ft_split("xxxxxxxxhello!xxxhi!!", 'x');
//	i = 0;
//	while (str[i])
//	{
//		printf("%s\n", str[i]);
//		i++;
//	}
//}
