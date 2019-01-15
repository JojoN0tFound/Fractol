/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:16:01 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/15 14:15:57 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*ft_init(t_env *ptr, char *fract)
{
	ptr->toogle = 1;
	ptr->init = 0;
	ptr->fract = -1;
	if (!(ptr->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGH, fract)))
	{
		free(ptr->mlx_ptr);
		return (NULL);
	}
	if (!(ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGH)))
	{
		free(ptr->mlx_ptr);
		free(ptr->win_ptr);
		return (NULL);
	}
	if (!(ptr->buff = mlx_get_data_addr(ptr->img_ptr, &ptr->bpp, &ptr->pix,\
					&ptr->endian)))
	{
		free(ptr->mlx_ptr);
		free(ptr->win_ptr);
		free(ptr->img_ptr);
		return (NULL);
	}
	return (ptr);
}

t_env		*julia_init(t_env *ptr)
{
	t_fract julia;

	julia.zoom = 200;
	julia.itmax = 50;
	julia.xmin = -2;
	julia.ymin = -1.9;
	julia.xmax = 2;
	julia.ymax = 1.9;
	julia.color = 2;
	julia.rd = 0;
	ptr->name = julia;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*mandelbrot_init(t_env *ptr)
{
	t_fract mandelbrot;

	mandelbrot.zoom = 200;
	mandelbrot.itmax = 50;
	mandelbrot.xmin = -2.35;
	mandelbrot.ymin = -1.9;
	mandelbrot.xmax = 2.35;
	mandelbrot.ymax = 1.9;
	mandelbrot.color = 2;
	mandelbrot.rd = 0;
	ptr->name = mandelbrot;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*burningship_init(t_env *ptr)
{
	t_fract burningship;

	burningship.zoom = 200;
	burningship.itmax = 50;
	burningship.xmin = -2.5;
	burningship.ymin = -2.4;
	burningship.xmax = 2.5;
	burningship.ymax = 2.4;
	burningship.color = 2;
	burningship.rd = 0;
	ptr->name = burningship;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}
