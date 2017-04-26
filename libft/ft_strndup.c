/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:55:12 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/18 09:20:33 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * n + 1)))
		return (0);
	else
	{
		while (s1[i] != '\0' && i < n)
		{
			dest[i] = s1[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
