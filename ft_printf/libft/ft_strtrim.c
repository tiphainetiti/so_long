/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:11:24 by tlay              #+#    #+#             */
/*   Updated: 2023/11/21 19:27:04 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tofind(const char *s, const char ch)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*table;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_tofind(set, s1[start]))
		start++;
	while (end > start && ft_tofind(set, s1[end - 1]))
		end--;
	table = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!table)
		return (NULL);
	while (start < end)
		table[i++] = s1[start++];
	table[i] = '\0';
	return (table);
}
