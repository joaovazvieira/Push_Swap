/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:25:10 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:23:07 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct t_buck
{
	int	current;
	int	bucket;
	int	pos;
	int	i_top;
	int	i_bot;
}				t_buck;

// --Push Swap main functions--
void	indexing(t_list **stack_a);
void	stack_init(t_list ***stack_a, t_list ***stack_b);
void	sorter(t_list **stack_a, t_list **stack_b, t_buck *bs_data);

// --Push swap Parsing function--
void	input_check(int argc);
void	double_num(t_list *stack);
t_list	**parse(t_list **stack_a, char *argv[]);

// --Push swap function moves--
void	rotate(t_list **stack, char def);
void	reverse_rot(t_list **stack, char def);
void	swap(t_list **stack_a);
void	push(t_list **stack, t_list **dest, char def);
void	ss(t_list **stack_a, t_list **stack_b);
void	sort_push(t_list **stack_a, t_list **stack_b, t_buck *bs_data);
void	push_back(t_list **stacka, t_list **stackb);

// --Push swap sorting functions--
int		sort_checker(t_list **stack_a);
void	sorted_push(t_list **stack_a, t_list **stack_b, int pos);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack, t_list **stack_b);
void	sort_five(t_list **stack, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b, t_buck *bs_data);

// --Push swap logical functions--
int		search_big(t_list *stack_b);
void	small_man(t_list **stack);
void	low_move(t_list **stack, int i);

// --Push swap error handling--
int		msg(int i, char **input);
void	free_list(t_list **stack);
void	free_array(char **array);

// --Push swap extras--
int		ft_atoi_error(const char *str, char **input);

#endif
