/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:35:42 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:10:49 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//--funcao encarregue de determnar tamanho do bucket--
static int	get_size(t_list	*stack)
{
	int	i;
	int	n;
	int	size;

	size = ft_lstsize(stack);
	i = 1;
	n = 0;
	while (n < size)
	{
		n = i * i;
		i++;
	}
	i--;
	return (size / (i / 2));
}
//--funcao procura top--

int	top_search(t_list *stack, int stack_size, int bucket_size)
{
	int	pos;

	pos = 0;
	while (pos < stack_size)
	{
		if (stack->index <= bucket_size)
			return (pos);
		if (stack->next)
			stack = stack->next;
		pos++;
	}
	return (0);
}

//--funcao procura bot
static int	bot_search(t_list **stack, int stack_size, int bucket_size)
{
	t_list	*i;
	int		pos;

	pos = stack_size;
	while (pos >= 0)
	{
		i = ft_lst_pos(stack, pos);
		if (i->index <= bucket_size)
			return (pos);
		pos--;
	}
	return (0);
}

//--funcao com defenicao de index por tamanho de bucket--
//--e consquentes procuras de top e bot--
static void	index_buck(t_list **stack_a, t_list **stack_b, t_buck *bs_data)
{
	int	i;

	i = 0;
	bs_data->i_top = 0;
	bs_data->i_bot = 0;
	while (*stack_a)
	{
		if (ft_lstsize(*stack_a) % bs_data->bucket == 0)
			i += bs_data->bucket;
		bs_data->current = i;
		bs_data->i_top = top_search(*stack_a, ft_lstsize(*stack_a), i);
		bs_data->i_bot = bot_search(stack_a, ft_lstsize(*stack_a), i);
		sort_push(stack_a, stack_b, bs_data);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_buck *bs_data)
{
	bs_data->current = 0;
	bs_data->pos = 0;
	bs_data->bucket = get_size((*stack_a));
	index_buck(stack_a, stack_b, bs_data);
	sorted_push(stack_a, stack_b, bs_data->pos);
}
