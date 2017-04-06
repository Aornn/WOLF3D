/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:18:45 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/02 08:31:13 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;
	int		j;

	i = 0;
	j = 0;
	tmp_s = (char *)s;
	if (ft_strlen(s) == 0)
		return (NULL);
	if ((unsigned char)c == '\0')
	{
		while ((unsigned char)tmp_s[i] != (unsigned char)c)
			i++;
		return (&tmp_s[i]);
	}
	while ((unsigned char)tmp_s[i])
	{
		if ((unsigned char)tmp_s[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if ((unsigned char)tmp_s[j] == (unsigned char)c)
		return (&tmp_s[j]);
	else
		return (NULL);
}
