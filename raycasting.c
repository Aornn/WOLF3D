/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/13 13:56:10 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	ray_init(t_env *e, int x)
{
	e->camera = 2 * x / (double)WH - 1;
	e->raypos_x = e->pos_x;
	e->raypos_y = e->pos_y;
	e->raydir_x = e->dir_x + e->plane_x * e->camera;
	e->raydir_y = e->dir_y + e->plane_y * e->camera;
	e->map_x = e->raypos_x;
	e->map_y = e->raypos_y;
	e->deltadist_x = sqrt(1 + (e->raydir_y * e->raydir_y)
			/ (e->raydir_x * e->raydir_x));
	e->deltadist_y = sqrt(1 + (e->raydir_x * e->raydir_x)
			/ (e->raydir_y * e->raydir_y));
	e->hit = 0;
}

static void	side(t_env *e)
{
	if (e->raydir_x < 0)
	{
		e->step_x = -1;
		e->sidedist_x = (e->raypos_x - e->map_x) * e->deltadist_x;
	}
	else
	{
		e->step_x = 1;
		e->sidedist_x = (e->map_x + 1.0 - e->raypos_x) * e->deltadist_x;
	}
	if (e->raydir_y < 0)
	{
		e->step_y = -1;
		e->sidedist_y = (e->raypos_y - e->map_y) * e->deltadist_y;
	}
	else
	{
		e->step_y = 1;
		e->sidedist_y = (e->map_y + 1.0 - e->raypos_y) * e->deltadist_y;
	}
}

static void	dist(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedist_x < e->sidedist_y)
		{
			e->sidedist_x += e->deltadist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->sidedist_y += e->deltadist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->world_map[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

static void	draw(t_env *e, int x)
{
	int		height;
	int		start;
	int		end;

	if (e->side == 0)
		e->pwd = (e->map_x - e->raypos_x + (1 - e->step_x) / 2) / e->raydir_x;
	else
		e->pwd = (e->map_y - e->raypos_y + (1 - e->step_y) / 2) / e->raydir_y;
	height = (int)(WH / e->pwd);
	start = (-1 * height) / 2 + WH / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + WH / 2;
	if (end >= WH)
		end = WH - 1;
	e->color = BLUE;
	ft_stroke(x, 0, start, e);
	e->color = 0x696969;
	ft_stroke(x, end, WH - 1, e);
	choice_color(e);
	ft_stroke(x, start, end, e);
}

void		ray(t_env *e)
{
	int x;

	x = 0;
	while (x < WH)
	{
		ray_init(e, x);
		side(e);
		dist(e);
		draw(e, x);
		x++;
	}
	radar(e);
	mlx_put_image_to_window(e->mlx, e->window, e->sky.im, 0, 0);
	mlx_put_image_to_window(e->mlx, e->window, e->img, 0, 0);
	mlx_string_put(e->mlx, e->window, 600, 20, BLACK, "MOVE SPEED = ");
	mlx_string_put(e->mlx, e->window, 750, 20,
			BLACK, ft_itoa(e->move_speed * 1000));
	mlx_string_put(e->mlx, e->window, 600, 40, BLACK, "ROTATION SPEED = ");
	mlx_string_put(e->mlx, e->window, 770, 40,
			BLACK, ft_itoa(e->rot_speed * 1000));
}
