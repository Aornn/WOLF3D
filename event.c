/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/03 17:47:17 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	forward_backward(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)]
			[(int)(e->pos_y)] == 0)
			e->pos_x += e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y + e->dir_y * e->move_speed)] == 0)
			e->pos_y += e->dir_y * e->move_speed;
	}
	if (keycode == 125)
	{
		if (e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)]
			[(int)(e->pos_y)] == 0)
			e->pos_x -= e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y - e->dir_y * e->move_speed)] == 0)
			e->pos_y -= e->dir_y * e->move_speed;
	}
}

static void	right_left(int keycode, t_env *e)
{
	double old_dir_x;
	double old_plane_x;

	if (keycode == 124)
	{
		old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
		e->dir_y = old_dir_x * sin(-e->rot_speed) + e->dir_y * cos(-e->rot_speed);
		old_plane_x = e->plane_x;
		e->plane_x = e->plane_x * cos(-e->rot_speed)
		- e->plane_y * sin(-e->rot_speed);
		e->plane_y = old_plane_x * sin(-e->rot_speed)
		+ e->plane_y * cos(-e->rot_speed);
	}
	if (keycode == 123)
	{
		old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(e->rot_speed) - e->dir_y * sin(e->rot_speed);
		e->dir_y = old_dir_x * sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
		old_plane_x = e->plane_x;
		e->plane_x = e->plane_x * cos(e->rot_speed) - e->plane_y * sin(e->rot_speed);
		e->plane_y = old_plane_x *
		sin(e->rot_speed) + e->plane_y * cos(e->rot_speed);
	}
}

int			ft_event(int keycode, t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->window);
	if (keycode == 53)
	{
		ft_putstr("Exit success.\n");
		exit(1);
	}
	forward_backward(keycode, e);
	right_left(keycode, e);
	if (keycode == 78)
		e->move_speed -= 0.1;
	if (keycode == 69)
		e->move_speed += 0.1;
	if (keycode == 43)
		e->rot_speed -= 0.1;
	if (keycode == 47)
		e->rot_speed += 0.1;
	e->img = mlx_new_image(e->mlx, WH, WH);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp,
		&e->sizeline, &e->endian);
	ray(e);
	return (0);
}
