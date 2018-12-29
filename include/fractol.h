/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:15:02 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 00:53:57 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

#include "../../../minilibx_macos/mlx.h"
#include <stdio.h>

# define WIDTH 1200
# define HEIGH 900

typedef struct	s_fract
{
	int		fract;
	void	*win_ptr;
	void	*img_ptr;
	void	*mlx_ptr;
	char	*buff;
	int		endian;
	int		bpp;
	int		pix;
	int		color;
}				t_fract;

int				main(int ac, char **av);
int				ft_princ(char *fract);

int				ft_fractol(t_fract *ptr);
void			put_pixel(t_fract *ptr, int x, int y, int color);

int				ft_julia(t_fract *ptr);
int				ft_mandelbrot(t_fract *ptr);

t_fract			*ft_init(t_fract *ptr, char *fract);
int				ft_good_arg(char **av);

int				ft_error(char *fract);
int				ft_usage(void);

#endif