/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:31:31 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/05 08:48:16 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;

	i = n;
	src_tmp = (unsigned char *)src;
	dest_tmp = (unsigned char *)dest;
	if (i == 0)
		return (dest);
	if (dest > src)
	{
		while (i > 0)
		{
			i--;
			dest_tmp[i] = src_tmp[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
