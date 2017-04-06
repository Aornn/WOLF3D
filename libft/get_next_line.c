/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:25:10 by rqueverd          #+#    #+#             */
/*   Updated: 2017/03/29 11:35:16 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strfreejoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	l1;
	size_t	l2;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = ft_strnew(l1 + l2);
	while (i < l1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		dest[i + l1] = s2[i];
		i++;
	}
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (dest);
}

static void		read_to_n(int fd, char **buf)
{
	char	*tmp;
	int		ret;

	tmp = ft_strnew(BUFF_SIZE);
	ret = 0;
	if ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		*buf = ft_strfreejoin(*buf, tmp);
		if (!(ft_strrchr(*buf, 10)))
			read_to_n(fd, buf);
	}
}

static char		*ft_freestrsub(char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = s[i + start];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int				get_next_line(int const fd, char **line)
{
	static char *buf = NULL;
	int			i;
	int			ret;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	if (read(fd, NULL, 0) == -1)
		return (-1);
	if (!buf)
		buf = ft_strnew(0);
	read_to_n(fd, &buf);
	if (ft_strlen(buf) == 0)
	{
		ft_strdel(&buf);
		return (0);
	}
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, buf, i);
	buf = ft_freestrsub(buf, i + 1, ft_strlen(buf) - i);
	return (1);
}
