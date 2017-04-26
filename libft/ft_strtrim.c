/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:58:38 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/28 10:00:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*dest;
	int		start_s;
	int		end_s;
	int		i;

	i = 0;
	start_s = 0;
	if (s == NULL)
		return (NULL);
	end_s = ft_strlen(s) - 1;
	while (s[start_s] == ' ' || s[start_s] == '\n' || s[start_s] == '\t')
		start_s++;
	while ((s[end_s] == ' ' || s[end_s] == '\n' || s[end_s] == '\t') \
		&& (end_s > start_s))
		end_s--;
	dest = (char*)malloc(((ft_strlen(s) - \
	((ft_strlen(s) - end_s) + start_s)) + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (start_s <= end_s)
		dest[i++] = s[start_s++];
	dest[i] = '\0';
	return (dest);
}
