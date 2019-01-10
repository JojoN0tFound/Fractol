/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:18:41 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/10 14:11:12 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_julia(int x, int y, t_env *data)
{
	if (data->fract == 0)
	{
		data->name.c_r = x * 2;
		data->name.c_i = y * 2 - 800;
		ft_fractol(data);
	}
	return (0);
}

t_env		*ft_draw_julia(t_env *ptr)
{
	int		i;
	double	tmp;

	i = 0;
	ptr->name.c_r = 0.285;
	ptr->name.c_i = 0.01;
	ptr->name.z_r = ptr->x / ptr->name.zoom + ptr->name.x1;
	ptr->name.z_i = ptr->y / ptr->name.zoom + ptr->name.y1;
	while (ptr->name.z_r * ptr->name.z_r + ptr->name.z_i * ptr->name.z_i < 4 && i < ptr->name.itmax)
	{
		tmp = ptr->name.z_r;
		ptr->name.z_r = ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i - 0.8 + (ptr->name.c_r / WIDTH);
    	ptr->name.z_i = 2 * ptr->name.z_i * tmp + ptr->name.c_i / WIDTH;
		i++;
	}
	if (i == ptr->name.itmax)
		put_pixel(ptr, ptr->x, ptr->y, /*ft_abs((ptr->x - ptr->y) / 2 - (WIDTH + HEIGH) / 2) * 27500*/random_color());
	else
		put_pixel(ptr, ptr->x, ptr->y, 0x0);
	return(ptr);
}

t_env		*ft_julia(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = julia_init(ptr);
	ptr = ft_draw_julia(ptr);
	return (ptr);
}
