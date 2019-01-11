/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:15:02 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/11 20:22:53 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

//#include "../../../minilibx_macos/mlx.h"
#include <stdio.h>

# define WIDTH 1500
# define HEIGH 900

typedef	struct	s_fract
{
	double		x1;
	double		x2;
	double		img_x;
	double		y1;
	double		y2;
	double		img_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			itmax;
	double		zoom;
	int			color;
	int			rd;
}				t_fract;

typedef struct	s_env
{
	int		init;
	int		fract;
	void	*win_ptr;
	void	*img_ptr;
	void	*mlx_ptr;
	char	*buff;
	int		endian;
	int		bpp;
	int		pix;
	double	x;
	double	y;
	double	x1;
	double	y1;
	t_fract	name;
}				t_env;

int				main(int ac, char **av);
int				ft_princ(char *fract);

int				ft_fractol(t_env *ptr);
t_env			*ft_draw(t_env *ptr);
t_env			*put_pixel(t_env *ptr, int x, int y, int color);
int				random_color(t_env *ptr);
double			ft_abs(double a);

t_env			*ft_julia(t_env *ptr);
t_env			*julia_init(t_env *ptr);
int				mouse_julia(int x, int y, t_env *data);
t_env			*ft_mandelbrot(t_env *ptr);
t_env			*mandelbrot_init(t_env *ptr);

t_env			*ft_init(t_env *ptr, char *fract);
int				ft_good_arg(char **av);

int				ft_close(t_env *ptr);
int				key_hook(int x, t_env *ptr);
int				color(t_env *ptr, int it);

int				ft_error(char *fract);
int				ft_usage(void);

#endif
