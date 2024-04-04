/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:37 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:14:55 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0'
			&& ch <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char test = '9';
	if (ft_isalnum(test))
		printf("%c is alphanumeric\n", test);
	else
		printf("%c is not alphanumeric\n", test);
	return (0);
}*/