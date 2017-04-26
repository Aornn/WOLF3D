/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:01 by rqueverd          #+#    #+#             */
/*   Updated: 2017/04/18 12:37:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# define WH 800
# define BLUE 0x0093AF
# define RED 0x00FFA8A8
# define WHITE 0x00BBACAC
# define GREEN 0x0027DE55
# define ORANGE 0x00FF6600
# define YELLOW 0x00FFFF00
# define PURPLE 0x00660099
# define BLACK 0x00000000

typedef struct	s_mmain
{
	char	**tmp;
	int		x;
	int		len;
}				t_mmain;

typedef struct	s_skybox
{
	void		*im;
	int			*img_data;
	int			len;
	int			bpp;
	int			endi;

}				t_skybox;

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
	int			state;
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
	double		pwd;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		old_dir_x;
	double		old_plane_x;
	int			color;
	int			x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	t_skybox	sky;
	t_skybox	welc;
	char		*path;
}				t_env;

void			radar(t_env *e);
void			mlx_put_pixel_image(int x, int y, t_env *env, int color);
void			ft_stroke(int x1, int y1, int y2, t_env *e);
int				*ft_calc_tmp_x(char *argv);
void			init_grid(t_env *e, char *line, int *map_h, t_mmain *mmain);
void			ray(t_env *e);
int				ft_event(int keycode, t_env *e);
void			choice_color(t_env *e);
void			init_var_main(t_env *e, char **line2);
void			move(t_env *e, int keycode);
#endif
