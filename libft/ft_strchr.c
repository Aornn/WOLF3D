/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:37:57 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/07 12:30:37 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	i = 0;
	tmp_s = (char *)s;
	if ((unsigned char)c == '\0')
	{
		while (tmp_s[i] != (unsigned char)c)
			i++;
		return (&tmp_s[i]);
	}
	while (tmp_s[i])
	{
		if (tmp_s[i] == (unsigned char)c)
			return (&tmp_s[i]);
		i++;
	}
	return (0);
}
