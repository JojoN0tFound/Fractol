/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:18:41 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/02 16:16:03 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*julia_init(t_env *ptr)
{
	t_fract julia;

	julia.zoom = 400;
	julia.itmax = 50;
	julia.x = 0;
	julia.x1 = -1;
	julia.y = 0;
	julia.y1 = -1.2;
	julia.color = 0x1ca1f2;
	ptr->name = julia;
	return (ptr);
}

t_env		*ft_draw_julia(t_env *ptr)
{
	int		i;
	double	tmp;

	while(ptr->name.x < WIDTH)
	{
		ptr->name.y = 0;
		while(ptr->name.y < HEIGH)
		{
			i = 0;
			ptr->name.c_r = 0.285;
			ptr->name.c_i = 0.01;
			ptr->name.z_r = ptr->name.x / ptr->name.zoom + ptr->name.x1;
			ptr->name.z_i = ptr->name.y / ptr->name.zoom + ptr->name.y1;
			while (ptr->name.z_r * ptr->name.z_r + ptr->name.z_i * ptr->name.z_i < 4 && i < ptr->name.itmax)
			{
				tmp = ptr->name.z_r;
				ptr->name.z_r = ptr->name.z_r * ptr->name.z_r - ptr->name.z_i * ptr->name.z_i - 0.8 + (ptr->name.c_r / WIDTH);
				ptr->name.z_i = 2 * ptr->name.z_i * tmp + ptr->name.c_i / WIDTH;
				i++;
			}
			if (i == ptr->name.itmax)
				put_pixel(ptr, ptr->name.x, ptr->name.y, ptr->name.color + (ptr->name.x + ptr->name.y));
			else
				put_pixel(ptr, ptr->name.x, ptr->name.y, 0x0);
			ptr->name.y += 1;
		}
		ptr->name.x += 1;
	}
	return(ptr);
}

t_env		*ft_julia(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = julia_init(ptr);
	ptr = ft_draw_julia(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	return (ptr);
}

/*définir x1 = -1
définir x2 = 1
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100
définir iteration_max = 150

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1 
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = 0.285
        définir c_i = 0.01
        définir z_r = x / zoom + x1
        définir z_i = y / zoom + y1
        définir i = 0

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i = iteration_max
            dessiner le pixel de coordonné (x; y)
        finSi
    finPour
finPour*/