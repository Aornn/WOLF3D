/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:29:02 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/18 09:14:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl				*ft_lst_pbk(int fd, t_gnl **lst)
{
	t_gnl			*tmp;
	t_gnl			*newfd;

	tmp = *lst;
	while (tmp)
	{
		if ((tmp)->fid == fd)
			return (tmp);
		tmp = (tmp)->next;
	}
	if (!(newfd = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	newfd->fid = fd;
	newfd->r = ft_strnew(0);
	newfd->next = *lst;
	*lst = newfd;
	return (newfd);
}

char				*ft_allok_static(t_gnl **lst, char *buf)
{
	char			*tmp;

	tmp = ft_strjoin((*lst)->r, buf);
	free((*lst)->r);
	(*lst)->r = ft_strdup(tmp);
	free(tmp);
	return ((*lst)->r);
}

int					ft_return_good(char **line, t_gnl *beg)
{
	char			*w;
	char			*z;

	if (ft_strcmp(beg->r, "\0") != 0)
	{
		if ((w = ft_strchr(beg->r, '\n')) != NULL)
		{
			*line = ft_strndup(beg->r, (w - beg->r));
			beg->r = ft_strcpy(beg->r, w + 1);
			return (1);
		}
		if (w == NULL && ft_strcmp(beg->r, "\0") != 0)
		{
			z = ft_strchr(beg->r, '\0');
			*line = ft_strndup(beg->r, (z - beg->r));
			beg->r = ft_strcpy(beg->r, z);
			return (1);
		}
	}
	return (0);
}

int					ft_refill_r(t_gnl *beg, char **line)
{
	char			*x;

	if ((x = ft_strchr(beg->r, '\n')) != NULL)
	{
		*line = ft_strndup(beg->r, (x - beg->r));
		beg->r = ft_strcpy(beg->r, x + 1);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*lst;
	t_gnl			*beg;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	beg = ft_lst_pbk(fd, &lst);
	if (beg->r)
		if (ft_refill_r(beg, line) == 1)
			return (1);
	while ((beg->ret = read(beg->fid, buf, BUFF_SIZE)) > 0)
	{
		buf[beg->ret] = '\0';
		beg->r = ft_allok_static(&beg, buf);
		if (ft_refill_r(beg, line) == 1)
			return (1);
	}
	if (beg->ret == -1)
		return (-1);
	return (ft_return_good(line, beg));
}
