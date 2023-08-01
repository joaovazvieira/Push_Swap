/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:55:35 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:12:28 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_checker(t_list **stack_a)
{
	t_list	*temp_l;

	temp_l = (*stack_a);
	while (temp_l->next)
	{
		if (temp_l->index < temp_l->next->index)
			temp_l = temp_l->next;
		else
			return (0);
	}
	return (1);
}

// -- function looks for the smallest number of moves--
void	small_man(t_list **stack)
{
	t_list	*temp_s;
	t_list	*temp_b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	temp_s = (*stack);
	temp_b = (*stack)->next;
	while (temp_b && (*stack))
	{
		j++;
		if ((*stack)->index < temp_b->index)
			temp_b = temp_b->next;
		else
		{
			i += j;
			j = 0;
			(*stack) = temp_b;
			temp_b = temp_b->next;
		}
	}
	(*stack) = temp_s;
	low_move(stack, i);
}

void	sorter(t_list **stack_a, t_list **stack_b, t_buck *bs_data)
{
	while (!sort_checker(stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			swap(stack_a);
		if (ft_lstsize(*stack_a) == 3)
			sort_three(stack_a);
		if (ft_lstsize(*stack_a) == 4)
			sort_four(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		if (ft_lstsize(*stack_a) > 5)
			big_sort(stack_a, stack_b, bs_data);
	}
}
