/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:56:48 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:24:12 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_num(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((input[i][0] == '-' || input[i][0] == '+') && j == 0)
				j++;
			if (ft_isdigit(input[i][j]) == 0)
				msg (1, NULL);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	**parse(t_list	**stack_a, char *argv[])
{
	t_list	*temp;
	char	**input;
	int		i;
	int		j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		input = ft_split(argv[j], ' ');
		while (input[i])
		{
			check_num(input);
			temp = ft_lstnew(ft_atoi_error(input[i], input));
			if (temp == NULL)
				ft_lstclear_mod(&temp);
			ft_lstadd_back(stack_a, temp);
			i++;
		}
		j++;
		free_array(input);
	}
	return (stack_a);
}
