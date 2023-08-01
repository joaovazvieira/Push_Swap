/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 03:05:11 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:07:47 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	low_move(t_list **stack, int i)
{
	if (i == 2)
		swap(stack);
	if (i == 3)
	{
		rotate(stack, 'a');
		rotate(stack, 'a');
	}
	if (i == 4 && ft_lstsize((*stack)) == 4)
		reverse_rot(stack, 'a');
	if (i == 4 && ft_lstsize((*stack)) == 5)
	{
		reverse_rot(stack, 'a');
		reverse_rot(stack, 'a');
	}
	if (i == 5)
		reverse_rot(stack, 'a');
}

void	double_num(t_list	*stack)
{
	t_list	*temp_first;
	t_list	*temp_second;

	temp_first = stack;
	temp_second = stack->next;
	while (temp_first)
	{
		temp_second = temp_first->next;
		while (temp_second)
		{
			if (temp_first->content == temp_second->content)
			{
				write(2, "Error\nthere are duplicates\n", 28);
				ft_lstclear_mod(&stack);
				exit (1);
			}
			temp_second = temp_second->next;
		}
		temp_first = temp_first->next;
	}
}
