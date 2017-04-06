/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:23:24 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/15 09:34:57 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = ft_strlen(little);
	if (tmp == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[j] == big[i])
		{
			while (little[j] == big[i + j] && little[j] != '\0')
				++j;
			if ((j + i) > len)
				return (NULL);
			if (j == tmp)
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
