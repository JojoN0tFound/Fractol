/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:16:01 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/14 19:21:40 by jquivogn         ###   ########.fr       */
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
	julia.xz = 1;
	julia.yz = 1;
	julia.rd = 0;
	julia.color = 2;
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
	mandelbrot.xz = 1;
	mandelbrot.yz = 1;
	ptr->name = mandelbrot;
	ptr->name.color = ptr->init == 1 ? ptr->name.color : 2;
	ptr->name.rd = ptr->init == 1 ? ptr->name.rd : 0;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*burningship_init(t_env *ptr)
{
	t_fract burningship;

	burningship.zoom = 200;
	burningship.itmax = 50;
	burningship.xz = 1;
	burningship.yz = 1;
	ptr->name = burningship;
	ptr->name.color = ptr->init == 1 ? ptr->name.color : 2;
	ptr->name.rd = ptr->init == 1 ? ptr->name.rd : 0;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}