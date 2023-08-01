/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:18:07 by jovieira          #+#    #+#             */
/*   Updated: 2023/08/01 17:22:14 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"
#include <limits.h>

int	ft_atoi_error(const char *str, char **input)
{
	int		i;
	int		sign;
	long	sum;

	sum = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + (str[i] - '0');
		if (sum > INT_MAX || sum < INT_MIN)
			msg(1, input);
		i++;
	}
	return (sign * sum);
}
