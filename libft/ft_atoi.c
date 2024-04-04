/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:36:52 by tlay              #+#    #+#             */
/*   Updated: 2023/11/21 18:42:32 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
/*
int	main(void)
{
	char *test1 = "1234";
	char *test2 = "-1234";
	char *test3 = "   5678";
	char *test4 = "\t\n\v\f\r 345";
	char *test5 = "+123";
	char *test6 = "abc";
	char *test7 = "99999999999999999999999999"; // test pour un grand nombre
	char *test8 = "-99999999999999999999999999";
	// test pour un grand nombre négatif

	printf("'%s' => %d\n", test1, ft_atoi(test1));
	printf("'%s' => %d\n", test2, ft_atoi(test2));
	printf("'%s' => %d\n", test3, ft_atoi(test3));
	printf("'%s' => %d\n", test4, ft_atoi(test4));
	printf("'%s' => %d\n", test5, ft_atoi(test5));
	printf("'%s' => %d\n", test6, ft_atoi(test6));
	printf("'%s' => %d\n", test7, ft_atoi(test7));
	printf("'%s' => %d\n", test8, ft_atoi(test8));

	return (0);
}*/