/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/03/29 13:38:14 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			mlx_put_pixel_image(int x, int y, t_env *env, int color)
{
	int pos;

	pos = (y * WH) + x;
	env->data[pos] = color;
}

static float	*ft_init_mult_int(int x1, int y1, int x2, int y2, float *mult_int)
{
	mult_int[1] = ft_abs(x2 - x1);
	mult_int[2] = x1 < x2 ? 1 : -1;
	mult_int[3] = -ft_abs(y2 - y1);
	mult_int[4] = y1 < y2 ? 1 : -1;
	mult_int[5] = mult_int[1] + mult_int[3];
	return (mult_int);
}

void			ft_stroke(int x1, int y1, int x2, int y2, t_env *e, int color)
{
	float *mult_int;

	mult_int = malloc(6 * sizeof(float));
	mult_int = ft_init_mult_int(x1, y1, x2, y2, mult_int);
	while (1)
	{
		mlx_put_pixel_image(x1, y1, e, color);
		mult_int[0] = 2 * mult_int[5];
		if (mult_int[0] >= mult_int[3])
		{
			if (x1 == x2)
				break ;
			mult_int[5] += mult_int[3];
			x1 += mult_int[2];
		}
		if (mult_int[0] <= mult_int[1])
		{
			if (y1 == y2)
				break ;
			mult_int[5] += mult_int[1];
			y1 += mult_int[4];
		}
	}
	free(mult_int);
}
