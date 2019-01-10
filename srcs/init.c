/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:16:01 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/10 18:38:08 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*ft_init(t_env *ptr, char *fract)
{
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

	julia.zoom = 400;
	julia.itmax = 150;
	julia.x1 = -1;
	julia.y1 = -1.2;
	julia.color = 1;
	ptr->name = julia;
	return (ptr);
}

t_env		*mandelbrot_init(t_env *ptr)
{
	t_fract mandelbrot;

	mandelbrot.zoom = 400;
	mandelbrot.itmax = 50;
	mandelbrot.x1 = -1;
	mandelbrot.y1 = -1.2;
	mandelbrot.color = 1;
	ptr->name = mandelbrot;
	return (ptr);
}
