/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:43:04 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/15 16:40:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp_list;

	if (!lst)
		return (NULL);
	tmp_list = f(lst);
	fresh = tmp_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp_list->next = f(lst)))
		{
			free(tmp_list->next);
			return (NULL);
		}
		tmp_list = tmp_list->next;
	}
	return (fresh);
}
