/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:26:30 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/10 17:21:31 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sum;

	sum = 0;
	i = 0;
	sign = 1;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}
