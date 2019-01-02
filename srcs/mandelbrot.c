/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:23:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/02 16:26:26 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*mandelbrot_init(t_env *ptr)
{
	t_fract mandelbrot;

	mandelbrot.zoom = 400;
	mandelbrot.itmax = 50;
	mandelbrot.x = 0;
	mandelbrot.x1 = -1;
	mandelbrot.y = 0;
	mandelbrot.y1 = -1.2;
	mandelbrot.color = 0x1ca1f2;
	ptr->name = mandelbrot;
	return (ptr);
}

t_env		*ft_draw_mandelbrot(t_env *ptr)
{
	int		i;
	double	tmp;

	while(ptr->name.x < WIDTH)
	{
		ptr->name.y = 0;
		while(ptr->name.y < HEIGH)
		{
			i = 0;
			ptr->name.c_r = ptr->name.x / ptr->name.zoom + ptr->name.x1;
			ptr->name.c_i = ptr->name.y / ptr->name.zoom + ptr->name.y1;
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
				put_pixel(ptr, ptr->name.x, ptr->name.y, 0xdc143c + (ptr->name.x - ptr->name.y));
			else
				put_pixel(ptr, ptr->name.x, ptr->name.y, ptr->name.color + (ptr->name.x + ptr->name.y));
			ptr->name.y += 1;
		}
		ptr->name.x += 1;
	}
	return(ptr);
}

t_env		*ft_mandelbrot(t_env *ptr)
{
	if (ptr->init == 0)
		ptr = mandelbrot_init(ptr);
	ptr = ft_draw_mandelbrot(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	return (ptr);
}

/*définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
définir iteration_max = 50

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1 
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = x / zoom + x1
        définir c_i = y / zoom + y1
        définir z_r = 0
        définir z_i = 0
        définir i = 0

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i = iteration_max
            dessiner en noir le pixel de coordonné (x; x)
        sinon
            dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
        finSi
    finPour
finPour*/