/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/06 13:54:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_check_all(int argc, char *argv)
{
	int		fd;
	int		nb_r;
	char	*line;

	if (argc != 2)
		return (0);
	nb_r = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{	nb_r++;
		free(line);
	}
	close(fd);
	return (nb_r);
}

static int	ft_summ_len(char **tmp, int len)
{
	while (tmp[len] != '\0')
	{
		len++;
	}
//	free(tmp);
	return (len);
}

int			ft_calc_tmp_x(char *argv, char **tmp)
{
	int		x;
	int		tmp_x;
	char	*line;
	int		fd;

	x = 0;
	tmp_x = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		while (tmp[x])
		{	
			free(tmp[x]);
			x++;
		}
		if (tmp_x < x)
			tmp_x = x;
		x = 0;
		free(line);
	}
	close(fd);
	return (tmp_x);
}

int			**init_grid(t_env *e, char *line, int *map_height)
{
	char	**tmp;
	int		x;
	int		len;

	while (get_next_line(e->fd, &line) > 0)
	{
		x = 0;
		len = 0;
		e->world_map[*map_height] = (int*)malloc(e->map_width * sizeof(int));
		tmp = ft_strsplit(line, ' ');
		len = ft_summ_len(tmp, len);
		while (x < e->map_width)
		{
			while (x < len)
			{
				e->world_map[*map_height][x] = ft_atoi(tmp[x]);
				free(tmp[x]);
				x++;
			}
			if ((x < e->map_width) && (x >= len))
			{
				e->world_map[*map_height][x] = 1;
				x++;
			}
		}
		free(line);
		*map_height = *map_height + 1;
	}
	return (e->world_map);
}
