/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:37:12 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/19 19:47:34 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list **stack)
{
	t_list	*temp_l;

	temp_l = (*stack)->next;
	(*stack)->next = temp_l->next;
	temp_l->next = (*stack);
	(*stack) = temp_l;
	write(1, "sa\n", 3);
}

// void	ss(t_list **stack_a, t_list **stack_b)
// {
// 	swap(stack_a);
// 	swap(stack_b);
// 	write(1, "ss\n", 3);
// }