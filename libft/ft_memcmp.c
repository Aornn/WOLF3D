/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:22:49 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/10 12:06:50 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s2_tmp;
	unsigned char	*s1_tmp;

	i = 0;
	s2_tmp = (unsigned char *)s2;
	s1_tmp = (unsigned char *)s1;
	while ((i != n) && (s1_tmp[i] == s2_tmp[i]))
		i++;
	if (i == n)
		return (0);
	return (s1_tmp[i] - s2_tmp[i]);
}
