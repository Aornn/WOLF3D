/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:19:28 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/10 12:07:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t tmp_size;

	i = 0;
	j = 0;
	tmp_size = 0;
	while (dst[i] != '\0' && i != n)
	{
		i++;
		tmp_size++;
	}
	if (i == n)
		return (n + ft_strlen((char *)src));
	while (j < (n - tmp_size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dst[i] = '\0';
	return (tmp_size + (size_t)ft_strlen((char *)src));
}
