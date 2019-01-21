/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birdofprey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:28:42 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/18 18:34:17 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*birdofprey_init(t_env *ptr)
{
	t_fract birdofprey;

	birdofprey.zoom = 200;
	birdofprey.itmax = 50;
	birdofprey.xmin = -2.1;
	birdofprey.ymin = -1.7;
	birdofprey.xmax = 1.6;
	birdofprey.ymax = 1.5;
	birdofprey.color = 2;
	birdofprey.rd = 0;
	ptr->name = birdofprey;
	ptr->x1 = 0;
	ptr->y1 = 0;
	return (ptr);
}

t_env		*ft_draw_birdofprey(t_env *ptr)
{
	int		i;
	double	tmp;

	ptr->name.c_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.c_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	ptr->name.z_r = 0;
	ptr->name.z_i = 0;
	i = 0;
	while (ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i <= 4
			&& i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		ptr->name.z_r = (3 * tmp * tmp - ptr->name.z_i * ptr->name.z_i) * fabs(ptr->name.z_i) + ptr->name.c_r;
		ptr->name.z_i = (tmp * tmp - 3 * ptr->name.z_i * ptr->name.z_i) * fabs(ptr->name.z_r) + ptr->name.c_i;
		i++;
	}
	return (put_pixel(ptr, ptr->x, ptr->y, i == ptr->name.itmax ? 0 : color(ptr, i)));
}

t_env		*ft_birdofprey(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = birdofprey_init(ptr);
	ptr = ft_draw_birdofprey(ptr);
	return (ptr);
}
