/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:43:47 by tlay              #+#    #+#             */
/*   Updated: 2023/12/07 18:04:51 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	element = *lst;
	while (element && element->next)
		element = element->next;
	element->next = new;
	return ;
}
