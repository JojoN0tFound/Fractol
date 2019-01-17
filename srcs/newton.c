/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:20:31 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/16 23:56:03 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*newton_init(t_env *ptr)
{
	t_fract newton;

	newton.zoom = 200;
	newton.itmax = 50;
	newton.xmin = -1.4;
	newton.ymin = -1.5;
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
	double	itmp;
	double	d;

	i = 0;
	ptr->name.z_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.z_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	ptr->name.c_r = -0.00508;
	ptr->name.c_i = 0.33136;
	while (ptr->name.z_r + ptr->name.c_r - ptr->name.z_i + ptr->name.c_i < 2
			&& i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		itmp = ptr->name.z_i;
		d = 9 * pow(tmp, 4) + 18 * pow(tmp, 2) * pow(itmp, 2) + 9 * pow(itmp, 4);
		ptr->name.z_r = (2 * pow(tmp, 3) - 6 * tmp * pow(itmp, 2) + 1) / d;
		ptr->name.z_i = (6 * pow(tmp, 2) * itmp - 6 * itmp) / d;
		i++;
	}
	tmp = ptr->name.z_r + ptr->name.c_r - ptr->name.z_i + ptr->name.c_i;
	if (tmp < 1.5 && tmp > 0.5)
		put_pixel(ptr, ptr->x, ptr->y, blue(i, 0));
	else if (tmp < -1 && tmp > 0)
		put_pixel(ptr, ptr->x, ptr->y, green(i, 0));
	else if (tmp < 1 && tmp > 0)
		put_pixel(ptr, ptr->x, ptr->y, red(i, 0));
	else
		put_pixel(ptr, ptr->x, ptr->y, 0x0);
	return (ptr);
}

t_env		*ft_newton(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = newton_init(ptr);
	ptr = ft_draw_newton(ptr);
	return (ptr);
}
