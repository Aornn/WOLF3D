/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:17:59 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/10 12:06:51 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	*s3;

	i = 0;
	s2 = (unsigned char *)src;
	s3 = (unsigned char *)dest;
	while (i < n)
	{
		s3[i] = s2[i];
		i++;
	}
	return (s3);
}
