/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:21:06 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/20 15:16:29 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lst_pos(t_list **stack, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (i < size - 1)
	{
		i++;
		temp = temp->next;
	}
	return (temp);
}
