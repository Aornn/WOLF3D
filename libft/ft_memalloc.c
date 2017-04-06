/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:20:14 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/29 16:38:25 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char*)malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (dest[i])
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
