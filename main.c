/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/13 14:50:56 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_var_main(t_env *e, char **line2)
{
	int w;
	int h;

	w = WH;
	h = WH / 2;
	e->move_speed = 0.099;
	e->rot_speed = 0.05;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->x = 0;
	e->pos_x = 7;
	e->pos_y = 7;
	e->dir_x = -1;
	e->dir_y = 0;
	e->sky.im = mlx_xpm_file_to_image(e->mlx, "pictures/hdelaby.xpm", &w, &h);
	e->sky.img_data = (int *)mlx_get_data_addr(e->sky.im, &e->sky.bpp,
			&e->sky.len, &e->sky.endi);
	e->welc.im = mlx_xpm_file_to_image(e->mlx, "pictures/welcome.xpm", &w, &h);
	e->welc.img_data = (int *)mlx_get_data_addr(e->welc.im, &e->welc.bpp,
			&e->welc.len, &e->welc.endi);
	line2 = NULL;
	e->state = 0;
}

int		close_win(t_env *e)
{
	(void)e->mlx;
	ft_putstr("Exit success.\n");
	exit(0);
	return (0);
}

int		main(void)
{
	t_env		e;
	char		*line2;

	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, WH, WH, "WOLF3D");
	e.img = mlx_new_image(e.mlx, WH, WH);
	e.data = (int *)mlx_get_data_addr(e.img, &e.bpp,
			&e.sizeline, &e.endian);
	init_var_main(&e, &line2);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 0, 0);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 250, 0);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 500, 0);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 750, 0);
	mlx_put_image_to_window(e.mlx, e.window, e.welc.im, 0, 300);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 0, 500);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 250, 500);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 500, 500);
	mlx_put_image_to_window(e.mlx, e.window, e.sky.im, 750, 500);
	mlx_hook(e.window, 2, 0, ft_event, &e);
	mlx_hook(e.window, 17, 18, close_win, e.mlx);
	mlx_loop(e.mlx);
	return (0);
}
