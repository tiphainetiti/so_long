/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:03:09 by tlay              #+#    #+#             */
/*   Updated: 2023/11/16 18:14:43 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char test = '	';
	if (ft_isascii(test))
		printf("%c is ascii\n", test);
	else
		printf("%c is ascii\n", test);
	return (0);
}*/