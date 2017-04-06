/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/06 12:09:26 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_var_main(t_env *e, char ***line, char **line2)
{
	e->move_speed = 0.099;
	e->rot_speed = 0.05;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->x = 0;
	e->pos_x = 7;
	e->pos_y = 7;
	e->dir_x = -1;
	e->dir_y = 0;
	line = NULL;
	line2 = NULL;
}

int		main(int argc, char **argv)
{
	char	**line;
	t_env	e;
	char	*line2;

	if (argc != 2)
		return (0);
	init_var_main(&e, &line, &line2);
	e.map_width = ft_calc_tmp_x(argv[1], line);
	e.fd = open(argv[1], O_RDONLY);
	e.map_height = 0;
	e.world_map = (int **)(malloc(e.map_width * sizeof(int *)));
	init_grid(&e, line2, &e.map_height);
	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, WH, WH, "WOLF3D");
	e.img = mlx_new_image(e.mlx, WH, WH);
	e.data = (int *)mlx_get_data_addr(e.img, &e.bpp,
		&e.sizeline, &e.endian);
	ray(&e);
	mlx_hook(e.window, 2, 0, ft_event, &e);
	mlx_loop(e.mlx);

	return (0);
}
