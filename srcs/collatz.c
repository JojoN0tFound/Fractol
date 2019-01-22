/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collatz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:59:08 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/21 14:08:19 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*collatz_init(t_env *ptr)
{
	t_fract collatz;

	collatz.zoom = 200;
	collatz.itmax = 50;
	collatz.xmin = -2.1;
	collatz.ymin = -1.7;
	collatz.xmax = 1.6;
	collatz.ymax = 1.5;
	collatz.color = 2;
	collatz.rd = 0;
	ptr->name = collatz;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*ft_draw_collatz(t_env *ptr)
{
	int		i;
	double	tmp;
	double	c;
	double	s;

	ptr->name.z_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.z_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	ptr->name.c_r = 0.25;
	ptr->name.c_i = 0.25;
	i = 0;
	while (ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i <= 4
			&& i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		c = cos(M_PI * tmp) * cosh(M_PI * ptr->name.z_i);
		s = sin(M_PI * tmp) * sinh(M_PI * ptr->name.z_i);
		ptr->name.z_r = (1 + 4 * tmp - c - 2 * tmp * c - 2 *
			ptr->name.z_i * s) * ptr->name.c_r;
		ptr->name.z_i = (4 * ptr->name.z_i + s + 2 * tmp * s - 2 *
			ptr->name.z_i * c) * ptr->name.c_i;
		i++;
	}
	return (put_pixel(ptr, ptr->x, ptr->y, i == ptr->name.itmax ?
			0 : color(ptr, i)));
}

t_env		*ft_collatz(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = collatz_init(ptr);
	ptr = ft_draw_collatz(ptr);
	return (ptr);
}
