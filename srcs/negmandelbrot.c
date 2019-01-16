/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negmandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 02:34:16 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/16 17:34:27 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*ft_draw_negmandelbrot(t_env *ptr, int i, double tmp, double d)
{
	i = 0;
	ptr->name.c_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.c_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	ptr->name.z_r = 0;
	ptr->name.z_i = 0;
	while (ptr->name.z_r * ptr->name.z_r + ptr->name.z_i * ptr->name.z_i <= 4 &&
			i < ptr->name.itmax)
	{
		d = ptr->name.z_r * ptr->name.z_r * ptr->name.z_r * ptr->name.z_r + 2 *
			ptr->name.z_r * ptr->name.z_r * ptr->name.z_i * ptr->name.z_i +
			ptr->name.z_i * ptr->name.z_i * ptr->name.z_i * ptr->name.z_i;
		if (d == 0)
			d = 5;
		tmp = ptr->name.z_r;
		ptr->name.z_r = (ptr->name.z_r * ptr->name.z_r - ptr->name.z_i *
			ptr->name.z_i) / d + ptr->name.c_r;
		ptr->name.z_i = (-2 * ptr->name.z_i * tmp) / d + ptr->name.c_i;
		i++;
	}
	if (i == ptr->name.itmax)
		put_pixel(ptr, ptr->x, ptr->y, 0);
	else
		put_pixel(ptr, ptr->x, ptr->y, color(ptr, i * 100));
	return (ptr);
}

t_env		*ft_negmandelbrot(t_env *ptr)
{
	int		i;
	double	tmp;
	double	d;

	i = 0;
	tmp = 0;
	d = 0;
	if (ptr->init == 0)
		ptr = mandelbrot_init(ptr);
	if (!(ptr = ft_draw_negmandelbrot(ptr, i, tmp, d)))
		return (NULL);
	return (ptr);
}
