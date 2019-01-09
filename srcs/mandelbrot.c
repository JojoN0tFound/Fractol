/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:23:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/04 16:49:06 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*ft_draw_mandelbrot(t_env *ptr)
{
	int		i;
	double	tmp;

	i = 0;
	ptr->name.c_r = ptr->x / ptr->name.zoom + ptr->name.x1;
	ptr->name.c_i = ptr->y / ptr->name.zoom + ptr->name.y1;
	ptr->name.z_r = 0;
	ptr->name.z_i = 0;
	while (ptr->name.z_r * ptr->name.z_r + ptr->name.z_i * ptr->name.z_i < 4 && i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		ptr->name.z_r = ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i + ptr->name.c_r;
		ptr->name.z_i = 2 * ptr->name.z_i * tmp + ptr->name.c_i;
		i++;
	}
	if (i == ptr->name.itmax)
		put_pixel(ptr, ptr->x, ptr->y, 0);
	else
		put_pixel(ptr, ptr->x, ptr->y, ptr->name.z_r * 500);
	return(ptr);
}

t_env		*ft_mandelbrot(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = mandelbrot_init(ptr);
	ptr = ft_draw_mandelbrot(ptr);
	return (ptr);
}
