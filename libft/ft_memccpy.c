/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:01:52 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/10 12:06:50 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;

	i = 0;
	src_tmp = (unsigned char *)src;
	dest_tmp = (unsigned char *)dest;
	while (i < n)
	{
		dest_tmp[i] = src_tmp[i];
		if (dest_tmp[i] == ((unsigned char)c))
			return (&dest_tmp[i + 1]);
		i++;
	}
	return (NULL);
}
