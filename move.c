/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/13 14:36:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	strafe(int keycode, t_env *e)
{
	if (keycode == 2)
	{
		if (e->world_map[(int)(e->pos_x + e->plane_x * e->move_speed)]
			[(int)(e->pos_y)] == 0 || e->world_map[(int)(e->pos_x +
				e->plane_x * e->move_speed)][(int)(e->pos_y)] == 5)
			e->pos_x += e->plane_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->plane_y
			* e->move_speed)] == 0 || e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y + e->plane_y * e->move_speed)] == 5)
			e->pos_y += e->plane_y * e->move_speed;
	}
	if (keycode == 0)
	{
		if (e->world_map[(int)(e->pos_x - e->plane_x * e->move_speed)]
			[(int)(e->pos_y)] == 0 || e->world_map[(int)(e->pos_x -
				e->plane_x * e->move_speed)][(int)(e->pos_y)] == 5)
			e->pos_x -= e->plane_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y - e->plane_y
			* e->move_speed)] == 0 || e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y - e->plane_y * e->move_speed)] == 5)
			e->pos_y -= e->plane_y * e->move_speed;
	}
}

static void	forward_backward(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)]
			[(int)(e->pos_y)] == 0 || e->world_map[(int)(e->pos_x +
				e->dir_x * e->move_speed)][(int)(e->pos_y)] == 5)
			e->pos_x += e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y
			* e->move_speed)] == 0 || e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y + e->dir_y * e->move_speed)] == 5)
			e->pos_y += e->dir_y * e->move_speed;
	}
	if (keycode == 125)
	{
		if (e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)]
			[(int)(e->pos_y)] == 0 || e->world_map[(int)(e->pos_x -
				e->dir_x * e->move_speed)][(int)(e->pos_y)] == 5)
			e->pos_x -= e->dir_x * e->move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y
			* e->move_speed)] == 0 | e->world_map[(int)(e->pos_x)]
			[(int)(e->pos_y - e->dir_y * e->move_speed)] == 5)
			e->pos_y -= e->dir_y * e->move_speed;
	}
	strafe(keycode, e);
}

static void	right_left(int keycode, t_env *e)
{
	e->old_dir_x = e->dir_x;
	e->old_plane_x = e->plane_x;
	if (keycode == 124)
	{
		e->dir_x = e->dir_x * cos(-e->rot_speed)
			- e->dir_y * sin(-e->rot_speed);
		e->dir_y = e->old_dir_x * sin(-e->rot_speed)
			+ e->dir_y * cos(-e->rot_speed);
		e->plane_x = e->plane_x * cos(-e->rot_speed)
			- e->plane_y * sin(-e->rot_speed);
		e->plane_y = e->old_plane_x * sin(-e->rot_speed)
			+ e->plane_y * cos(-e->rot_speed);
	}
	if (keycode == 123)
	{
		e->dir_x = e->dir_x * cos(e->rot_speed)
			- e->dir_y * sin(e->rot_speed);
		e->dir_y = e->old_dir_x * sin(e->rot_speed)
			+ e->dir_y * cos(e->rot_speed);
		e->plane_x = e->plane_x * cos(e->rot_speed)
			- e->plane_y * sin(e->rot_speed);
		e->plane_y = e->old_plane_x *
			sin(e->rot_speed) + e->plane_y * cos(e->rot_speed);
	}
}

static void	win(t_env *e)
{
	if (e->world_map[(int)e->pos_x][(int)e->pos_y] == 5)
	{
		mlx_clear_window(e->mlx, e->window);
		mlx_string_put(e->mlx, e->window, 350, 300, BLUE, "VICTORY");
		mlx_string_put(e->mlx, e->window, 300, 350, BLUE, "PRESS ESC TO EXIT");
		e->state = 5;
	}
}

void		move(t_env *e, int keycode)
{
	forward_backward(keycode, e);
	right_left(keycode, e);
	if (keycode == 78 && e->move_speed > 0.1)
		e->move_speed -= 0.1;
	if (keycode == 69 && e->move_speed < 1.1)
		e->move_speed += 0.1;
	if (keycode == 43 && e->rot_speed > 0.06)
		e->rot_speed -= 0.1;
	if (keycode == 47 && e->rot_speed < 1.0)
		e->rot_speed += 0.1;
	win(e);
}
