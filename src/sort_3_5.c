/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:23:14 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/20 14:57:31 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content && \
		(*stack)->content < (*stack)->next->next->content \
		&& (*stack)->next->content > (*stack)->next->next->content)
		swap(stack);
	if ((*stack)->content > (*stack)->next->content && \
		(*stack)->content < (*stack)->next->next->content \
		&& (*stack)->next->content < (*stack)->next->next->content)
		swap(stack);
	if ((*stack)->content > (*stack)->next->content && \
		(*stack)->content > (*stack)->next->next->content \
		&& (*stack)->next->content > (*stack)->next->next->content)
		swap(stack);
	if ((*stack)->content > (*stack)->next->content && \
		(*stack)->content > (*stack)->next->next->content \
		&& (*stack)->next->content < (*stack)->next->next->content)
		rotate(stack, 'a');
	if ((*stack)->content < (*stack)->next->content && \
		(*stack)->content > (*stack)->next->next->content \
		&& (*stack)->next->content > (*stack)->next->next->content)
		reverse_rot(stack, 'a');
}

void	sort_four(t_list **stack, t_list **stack_b)
{
	small_man(stack);
	if (sort_checker(stack))
		return ;
	push(stack, stack_b, 'b');
	sort_three(stack);
	push(stack_b, stack, 'a');
}

void	sort_five(t_list **stack, t_list **stack_b)
{
	small_man(stack);
	if (sort_checker(stack))
		return ;
	push(stack, stack_b, 'b');
	sort_four(stack, stack_b);
	push(stack_b, stack, 'a');
}
