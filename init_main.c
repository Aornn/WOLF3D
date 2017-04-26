/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/18 12:37:36 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	ft_summ_len(char **tmp, int len)
{
	len = 0;
	while (tmp[len] != '\0')
		len++;
	return (len);
}

static int	*init_tmp_x(int *tmp_x)
{
	tmp_x = (int*)malloc(2 * sizeof(int));
	tmp_x[0] = 0;
	tmp_x[1] = 0;
	return (tmp_x);
}

static void	calc_width(int *tmp_x, int *x)
{
	if (*tmp_x < *x)
		*tmp_x = *x;
	*x = 0;
}

int			*ft_calc_tmp_x(char *argv)
{
	int		x;
	int		*tmp_x;
	char	*line;
	int		fd;
	char	**tmp;

	x = 0;
	tmp_x = NULL;
	tmp_x = init_tmp_x(tmp_x);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		while (tmp[x])
		{
			ft_strdel(&tmp[x]);
			x++;
		}
		ft_memdel((void **)&tmp);
		ft_strdel(&line);
		calc_width(&tmp_x[0], &x);
		tmp_x[1] += 1;
	}
	close(fd);
	return (tmp_x);
}

void		init_grid(t_env *e, char *line, int *map_h, t_mmain *mmain)
{
	while (get_next_line(e->fd, &line) > 0)
	{
		mmain->x = 0;
		e->world_map[*map_h] = (int *)malloc(e->map_width * sizeof(int));
		mmain->tmp = ft_strsplit(line, ' ');
		mmain->len = ft_summ_len(mmain->tmp, mmain->len);
		while (mmain->x < e->map_width)
		{
			while (mmain->x < mmain->len)
			{
				e->world_map[*map_h][mmain->x] = ft_atoi(mmain->tmp[mmain->x]);
				ft_strdel(&mmain->tmp[mmain->x]);
				mmain->x++;
			}
			ft_memdel((void **)&mmain->tmp);
			if ((mmain->x < e->map_width) && (mmain->x >= mmain->len))
			{
				e->world_map[*map_h][mmain->x] = 1;
				ft_strdel(&mmain->tmp[mmain->x]);
				mmain->x++;
			}
		}
		ft_strdel(&line);
		*map_h = *map_h + 1;
	}
}
