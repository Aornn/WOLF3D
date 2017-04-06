/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:02:47 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/15 16:03:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*fresh;

	while (*alst)
	{
		fresh = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = fresh;
	}
	*alst = NULL;
}
