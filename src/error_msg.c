/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:35:18 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:30:21 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	input_check(int argc)
{
	if (argc < 3)
		exit(write(2, "ERROR\nGive at least two argumment\n", 35));
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	if (array)
		free(array);
}

void	free_list(t_list **stack)
{
	ft_lstclear_mod(stack);
	if (stack)
		free(stack);
}

int	msg(int i, char **input)
{
	if (input != NULL)
		free_array(input);
	if (i == 1)
		exit(write(2, "ERROR\nSome arguments arent integers\n", 37));
	return (0);
}
