/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:25:10 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/10 22:06:52 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

// typedef struct f_stack
// {
// 	void			*num;
// 	struct f_stack	*next;
// }				t_stack;

// --Push Swap main functions--
int	msg(int	i, char **temp, t_list *input);
int	ft_atoi_error(const char *str, char **temp, t_list *input);
// void	swap(int *stack, int size);
// void	multy_swap(int *stack_a, int *stack_b, int size_a, int size_b);

# endif
