/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:15:02 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/21 14:09:55 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define WIDTH 900
# define HEIGH 750

typedef	struct	s_fract
{
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		itmax;
	double	zoom;
	int		color;
	int		rd;
	double	c_r_x;
	double	c_i_y;
}				t_fract;

typedef struct	s_env
{
	int		init;
	int		fract;
	char	*f;
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
	int		azoom;
	int		toogle;
	int		jmouse;
	t_fract	name;
}				t_env;

int				main(int ac, char **av);
int				ft_princ(char *fract);

t_env			*ft_init(t_env *ptr, char *fract);
t_env			*julia_init(t_env *ptr);
t_env			*mandelbrot_init(t_env *ptr);
t_env			*burningship_init(t_env *ptr);
t_env			*sierpinski_init(t_env *ptr);

int				ft_fractol(t_env *ptr);
t_env			*ft_draw(t_env *ptr);
t_env			*put_pixel(t_env *ptr, int x, int y, int color);

t_env			*ft_julia(t_env *ptr);
t_env			*ft_draw_julia(t_env *ptr);
int				mouse_julia(int x, int y, t_env *data);

t_env			*ft_mandelbrot(t_env *ptr);
t_env			*ft_draw_mandelbrot(t_env *ptr);

t_env			*ft_bimandelbrot(t_env *ptr);
t_env			*ft_draw_bimandelbrot(t_env *ptr);

t_env			*ft_negmandelbrot(t_env *ptr);
t_env			*ft_draw_negmandelbrot(t_env *ptr, int i, double tmp, double d);

t_env			*ft_burningship(t_env *ptr);
t_env			*ft_draw_burningship(t_env *ptr);

t_env			*ft_newton(t_env *ptr);
t_env			*ft_draw_newton(t_env *ptr);
t_env			*newton_init(t_env *ptr);

t_env			*ft_collatz(t_env *ptr);
t_env			*ft_draw_collatz(t_env *ptr);
t_env			*collatz_init(t_env *ptr);

int				color(t_env *ptr, int it);
int				random_color(t_env *ptr);
int				red(int i, size_t color);
int				blue(int i, size_t color);
int				green(int i, size_t color);

int				key_hook(int x, t_env *ptr);
int				ft_close(t_env *ptr);
int				mouse_zoom(int k, int x, int y, t_env *e);
int				ft_toogle(t_env *ptr);
int				ft_itmax(int x, t_env *ptr);

int				ft_move(t_env *ptr, int x);
int				ft_changefract(int x, t_env *ptr);
int				select_color(int x, t_env *ptr);
int				ft_reset(t_env *ptr);

int				ft_good_arg(char **av);

int				ft_error(char *fract);
int				ft_usage(void);
int				ft_command(t_env *ptr);
void			ft_name(t_env *ptr);

#endif
