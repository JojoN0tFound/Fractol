/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:20:31 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/18 17:53:37 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*newton_init(t_env *ptr)
{
	t_fract newton;

	newton.zoom = 200;
	newton.itmax = 50;
	newton.xmin = -2.1;
	newton.ymin = -1.7;
	newton.xmax = 1.6;
	newton.ymax = 1.5;
	newton.color = 2;
	newton.rd = 0;
	ptr->name = newton;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*ft_draw_newton(t_env *ptr)
{
	int		i;
	double	tmp;
	double	d;

	i = 0;
	ptr->name.z_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.z_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	while (ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i < 4
			&& i < ptr->name.itmax)
	{
		ptr->name.c_r = ptr->name.z_r * ptr->name.z_r;
		ptr->name.c_i = ptr->name.z_i * ptr->name.z_i;
		d = 3.0 * ((ptr->name.c_r - ptr->name.c_i) * (ptr->name.c_r - ptr->name.c_i) + 4.0 * ptr->name.c_r * ptr->name.c_i);
		if (d == 0.0)
			d = 0.000001;
		tmp = ptr->name.z_r;
		ptr->name.z_r = (2.0 / 3.0) * ptr->name.z_r + (ptr->name.c_r - ptr->name.c_i) / d;
		ptr->name.z_i = (2.0 / 3.0) * ptr->name.z_i - 2.0 * tmp * ptr->name.z_i / d;
		i++;
	}
	put_pixel(ptr, ptr->x, ptr->y, color(ptr, i == ptr->name.itmax ? 0 : i));
	return (ptr);
}

t_env		*ft_newton(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = newton_init(ptr);
	ptr = ft_draw_newton(ptr);
	return (ptr);
}
