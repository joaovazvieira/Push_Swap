/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:45:27 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:11:21 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **stack, t_list **dest, char def)
{
	t_list	*temp;

	if (!(*stack))
		return ;
	temp = *dest;
	*dest = *stack;
	*stack = (*stack)->next;
	(*dest)->next = temp;
	if (def == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
