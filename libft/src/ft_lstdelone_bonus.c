/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:01:09 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/20 15:25:20 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstdelone(t_list *lst)
// {
// 	if (!lst)
// 		return ;
// 	free(lst->content);
// 	free(lst);
// }

void	ft_lstdelone_mod(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
