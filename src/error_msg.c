/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:35:18 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/10 21:36:06 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	if (array)
		free(array);
}

int	msg(int	i, char **temp, t_list *input)
{
	(void) temp;
	(void) input;
	if (i == 1)
	{
		ft_lstclear(&input);
		free_array(temp);
		exit(write(2, "This is the kenny virus\n", 25));
		
	}
		// write(2, "Wrong number imput\n", 20);
	// exit(1);
	return (0);
}