/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:27:04 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/13 14:16:21 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	mlx_put_pixel_image_square(t_env *env, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i++ <= 5)
	{
		j = 0;
		while (j++ <= 5)
			mlx_put_pixel_image(x + i, y + j, env, color);
	}
}

void		radar(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->map_width)
	{
		j = 0;
		while (j < e->map_height)
		{
			if (e->world_map[j][i] == 0 || e->world_map[j][i] == 5)
				mlx_put_pixel_image_square(e, i * 5, j * 5, 0x0000FF);
			else
				mlx_put_pixel_image_square(e, i * 5, j * 5, 0xFFFFFF);
			if (((int)e->pos_x == j && (int)e->pos_y == i))
				mlx_put_pixel_image_square(e, i * 5, j * 5, 0xFF0000);
			j++;
		}
		i++;
	}
}
