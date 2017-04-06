/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/03 17:49:34 by rqueverd         ###   ########.fr       */
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
		e->perp_wall_dist = (e->map_x - e->raypos_x +
			(1 - e->step_x) / 2) / e->raydir_x;
	else
		e->perp_wall_dist = (e->map_y - e->raypos_y +
			(1 - e->step_y) / 2) / e->raydir_y;
	height = (int)(WH / e->perp_wall_dist);
	start = (-1 * height) / 2 + WH / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + WH / 2;
	if (end >= WH)
		end = WH - 1;
	if (e->world_map[e->map_x][e->map_y] == 1)
		e->color = RED;
	else if (e->world_map[e->map_x][e->map_y] == 2)
		e->color = GREEN;
	else if (e->world_map[e->map_x][e->map_y] == 3)
		e->color = PURPLE;
	else if (e->world_map[e->map_x][e->map_y] == 4)
		e->color = WHITE;
	else
		e->color = YELLOW;
	if (e->side == 1)
		e->color /= 2;
	ft_stroke(x, 0, x, start, e, BLUE);
	ft_stroke(x, start, x, end, e, e->color);
	ft_stroke(x, end, x, WH - 1, e, 0x696969);
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
	mlx_put_image_to_window(e->mlx, e->window, e->img, 0, 0);
	mlx_string_put(e->mlx, e->window, 600, 20, BLACK, "MOVE SPEED = ");
	mlx_string_put(e->mlx, e->window, 750, 20,
		BLACK, ft_itoa(e->move_speed * 1000));
	mlx_string_put(e->mlx, e->window, 600, 40, BLACK, "ROTATION SPEED = ");
	mlx_string_put(e->mlx, e->window, 770, 40,
		BLACK, ft_itoa(e->rot_speed * 1000));
}
