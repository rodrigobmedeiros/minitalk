/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:19:46 by robernar          #+#    #+#             */
/*   Updated: 2024/02/24 19:18:23 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*clean_list(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*copy;
	t_list	*first_node;

	copy = NULL;
	if ((!lst) || (!f) || (!del))
		return (NULL);
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			return (clean_list(&first_node, del));
		if (!copy)
		{
			copy = new;
			first_node = new;
		}
		else
		{
			copy->next = new;
			copy = new;
		}
		lst = lst->next;
	}
	return (first_node);
}
