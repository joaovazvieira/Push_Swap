/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:34:35 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/19 19:30:30 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **stack, char def)
{
	t_list	*temp;
	t_list	*first;

	temp = (*stack);
	first = (*stack);
	temp = ft_lstlast(temp);
	(*stack) = (*stack)->next;
	temp->next = first;
	first->next = NULL;
	if (def == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rot(t_list **stack, char def)
{
	t_list	*temp;
	t_list	*last;

	temp = (*stack);
	last = (*stack);
	temp = ft_lstlast(temp);
	last = ft_lstdbnext(last);
	temp->next = (*stack);
	last->next = NULL;
	(*stack) = temp;
	if (def == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
