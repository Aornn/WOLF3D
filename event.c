/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/18 12:38:40 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	path_choice(t_env *e, int keycode)
{
	int *t;

	if (keycode == 83)
		e->path = "maps/map";
	if (keycode == 84)
		e->path = "maps/map2";
	if (keycode == 85)
		e->path = "maps/map3";
	e->map_height = 0;
	t = ft_calc_tmp_x(e->path);
	e->map_width = t[0];
	e->map_height = t[1];
	free(t);
	e->fd = open(e->path, O_RDONLY);
}

int			ft_event(int keycode, t_env *e)
{
	char		*line2;
	t_mmain		mmain;

	line2 = NULL;
	mlx_destroy_image(e->mlx, e->img);
	if (keycode == 53)
	{
		ft_putstr("Exit success.\n");
		exit(0);
	}
	if (e->state != 0 && e->state != 5)
		move(e, keycode);
	e->img = mlx_new_image(e->mlx, WH, WH);
	if (e->state == 0 && (keycode == 83 || keycode == 84 || keycode == 85))
	{
		path_choice(e, keycode);
		e->world_map = (int **)malloc(e->map_height * sizeof(int *));
		e->map_height = 0;
		init_grid(e, line2, &e->map_height, &mmain);
		e->state = 1;
	}
	if (e->state == 1)
		ray(e);
	return (0);
}
