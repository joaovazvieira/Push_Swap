/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:49:54 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:09:40 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// --roda stack dependendo do valor do bucket--
static void	rotate_sort(t_list	**stack, t_buck *bs_data)
{
	if (*stack && (*stack)->next)
		if ((*stack)->index > (bs_data->current - (bs_data->bucket / 2)))
			rotate(stack, 'b');
}

// --funçao que procura caminho mais viavel para dar push a -> b--
void	sort_push(t_list **stack_a, t_list **stack_b, t_buck *bs_data)
{
	int	j;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if ((stack_size - bs_data->i_bot) < bs_data->i_top)
	{
		j = 0;
		while (j < (stack_size - (bs_data->i_bot - 1)))
		{
			reverse_rot(stack_a, 'a');
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < bs_data->i_top)
		{
			rotate(stack_a, 'a');
			j++;
		}
	}
	push(stack_a, stack_b, 'b');
	rotate_sort(stack_b, bs_data);
}

// --funçao para encontrar maior numero no stack--
int	search_big(t_list *stack_b)
{
	int		stack_size;
	int		pos;
	t_list	*temp;

	temp = stack_b;
	pos = 0;
	while (temp)
	{
		stack_size = ft_lstsize(stack_b);
		if (temp->index == stack_size)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (0);
}

// --funçao para dar push b -> a--
void	sorted_push(t_list **stack_a, t_list **stack_b, int pos)
{
	while (*stack_b)
	{
		pos = search_big(*stack_b);
		if (pos == 0)
			push(stack_b, stack_a, 'a');
		else if (pos < (ft_lstsize(*stack_b) / 2))
		{
			while (pos > 0)
			{
				rotate(stack_b, 'b');
				pos--;
			}
			push(stack_b, stack_a, 'a');
		}
		else
		{
			while (pos < ft_lstsize(*stack_b))
			{
				reverse_rot(stack_b, 'b');
				pos++;
			}
			push(stack_b, stack_a, 'a');
		}
	}
}
