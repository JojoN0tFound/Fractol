/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:18:41 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/16 21:34:18 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			mouse_julia(int x, int y, t_env *data)
{
	if (data->fract == 0 && data->jmouse == 1)
	{
		data->name.c_r_x = x * 4;
		data->name.c_i_y = y * 4 + 200;
		ft_fractol(data);
	}
	return (0);
}

t_env		*ft_draw_julia(t_env *ptr)
{
	int		i;
	double	tmp;

	i = 0;
	ptr->name.c_r = 0.285 * ptr->name.c_r_x;
	ptr->name.c_i = 0.01 * ptr->name.c_i_y;
	ptr->name.z_r = (ptr->x + ptr->x1) / ptr->name.zoom + ptr->name.xmin;
	ptr->name.z_i = (ptr->y + ptr->y1) / ptr->name.zoom + ptr->name.ymin;
	while (ptr->name.z_r * ptr->name.z_r + ptr->name.z_i * ptr->name.z_i < 4 &&
			i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		ptr->name.z_r = ptr->name.z_r * ptr->name.z_r - ptr->name.z_i *
			ptr->name.z_i + (ptr->name.c_r / WIDTH);
		ptr->name.z_i = 2 * ptr->name.z_i * tmp + ptr->name.c_i / WIDTH;
		i++;
	}
	if (i == ptr->name.itmax)
		put_pixel(ptr, ptr->x, ptr->y, color(ptr, i));
	else
		put_pixel(ptr, ptr->x, ptr->y,
			ptr->name.color == 1 ? 0x0 : color(ptr, i));
	return (ptr);
}

t_env		*ft_julia(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = julia_init(ptr);
	ptr = ft_draw_julia(ptr);
	return (ptr);
}
