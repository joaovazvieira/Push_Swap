/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:23:16 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/10 22:07:37 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static void	free_array(char **array)
// {
// 	int	i;

// 	i = -1;
// 	while (array[++i])
// 		free(array[i]);
// 	if (array)
// 		free(array);
// }

int	check_num(char **temp)
{
	int	i;
	int	j;
	
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][0] == '-' && j == 0)
				j++;
			if (ft_isalnum(temp[i][j]) == 0)
				exit(1);
			j++;
		}
		i++;
	}
	return (0);
}

// static int	check_valid(t_list *input, char **temp)
// {
// 	printf(" check %i\n", input->content);
// 	msg(ft_atoi_error(*temp), temp, input);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	*input;
	char	**temp;
	// int		num;
	int		i;
	int		j;

	j = 1;
	stack_a = ft_calloc(sizeof(t_list *), 1);
	while (argv[j])
	{
		i = 0;
		temp = ft_split(argv[j], ' ');
		while (temp[i])
		{
			check_num(temp);
			// msg(ft_atoi_error(temp[i]), temp, input);
			input = ft_lstnew(ft_atoi_error(temp[i], temp, input));
			// check_valid(input, temp);
				// exit(1);
			ft_lstadd_back(stack_a, input);
			
			i++;
		}
		j++;
		free(temp);
	}
	if (argc < 2)
	{
		printf("ERROR\n");
		return (1);
	}
	while (*stack_a)
	{
		// printf("size %i\n", ft_lstsize(*stack_a));
		printf("%i\n", (*stack_a)->content);
		(*stack_a) = (*stack_a)->next;
	}
	return (0);
}

// push_swap "50 23 25 26 24" 0 20 20 

// argv[i] 2 3 4