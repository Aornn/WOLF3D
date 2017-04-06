/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:01 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/03 17:47:42 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# define WH 800
# define BLUE 0x0093AF
# define RED 0x00FF0033
# define WHITE 0x00FFFFFF
# define GREEN 0x0033FF00
# define ORANGE 0x00FF6600
# define YELLOW 0x00FFFF00
# define PURPLE 0x00660099
# define BLACK 0x00000000

typedef struct	s_env
{
	void		*mlx;
	void		*window;
	void		*img;
	int			*data;
	int			bpp;
	int			sizeline;
	int			endian;
	float		move_speed;
	float		rot_speed;
	int			**world_map;
	int			map_height;
	int			map_width;
	int			fd;
	double		dir_x;
	double		dir_y;
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		camera;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	double		perp_wall_dist;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			color;
	int			x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;

}				t_env;

void			mlx_put_pixel_image(int x, int y, t_env *env, int color);
void			ft_stroke(int x1, int y1, int x2, int y2, t_env *e, int color);
int				ft_check_all(int argc, char *argv);
int				ft_calc_tmp_x(char *argv, char **tmp);
int				**init_grid(t_env *e, char *line, int *nb_rows);
void			ray(t_env *e);
int				ft_event(int keycode, t_env *e);

#endif
