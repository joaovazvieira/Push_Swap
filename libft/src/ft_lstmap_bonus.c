/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:55:40 by jovieira          #+#    #+#             */
/*   Updated: 2023/07/10 19:40:20 by jovieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*head;
	int		data;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		data = f(lst->content);
		if (!data)
			return (ft_lstclear(&head, del), NULL);
		new = ft_lstnew(data);
		if (!new)
		{
			del(data);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
