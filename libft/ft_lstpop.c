/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:32:28 by robernar          #+#    #+#             */
/*   Updated: 2024/02/24 13:43:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list *ft_lstpop(t_list **lst)
{
    t_list  *last;
    t_list  *before_last;
    t_list  *current;

    if (!lst || !*lst)
        return NULL;
    last = NULL;
    before_last = NULL;
    current = *lst;
    while (current->next)
    {
        before_last = current;
        current = current->next;
    }
    if (before_last)
        before_last->next = NULL;
    else
        *lst = NULL;
    last = current;
    return last;
}