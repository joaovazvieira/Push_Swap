/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:11:29 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/20 14:41:44 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_init(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = ft_calloc(sizeof(t_list *), 1);
	if (!*stack_a)
		exit(write(2, "malloc fail\n", 13));
	*stack_b = ft_calloc(sizeof(t_list *), 1);
	if (!*stack_b)
		exit(write(2, "malloc fail\n", 13));
}

void	indexing(t_list **stack_a)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	i = 1;
	temp_a = (*stack_a);
	temp_b = (*stack_a)->next;
	while (temp_a)
	{
		if (temp_a->content > temp_b->content)
			i++;
		temp_b = temp_b->next;
		if (!temp_b)
		{
			temp_a->index = i;
			temp_a = temp_a->next;
			temp_b = (*stack_a);
			i = 1;
		}
	}
}
