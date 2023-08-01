/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:23:16 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:25:49 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	function(void)
// {
// 	system("leaks -q push_swap");
// }
// atexit(function);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_buck	bs_data;

	stack_a = NULL;
	stack_b = NULL;
	input_check(argc);
	stack_init(&stack_a, &stack_b);
	stack_a = parse(stack_a, argv);
	double_num(*stack_a);
	indexing(stack_a);
	sorter(stack_a, stack_b, &bs_data);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
