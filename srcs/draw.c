/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:17:50 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/21 13:11:26 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env		*put_pixel(t_env *ptr, int x, int y, int color)
{
	int	*img;

	img = (int *)ptr->buff;
	if (x < WIDTH && y < HEIGH && x > 0 && y > 0)
		img[x + WIDTH * y] = color;
	return (ptr);
}

t_env		*ft_draw(t_env *ptr)
{
	t_env	*(*draw[7])(t_env *);

	draw[0] = &ft_julia;
	draw[1] = &ft_mandelbrot;
	draw[2] = &ft_burningship;
	draw[3] = &ft_bimandelbrot;
	draw[4] = &ft_negmandelbrot;
	draw[5] = &ft_newton;
	draw[6] = &ft_collatz;
	ptr->x = 0;
	while (ptr->x < WIDTH)
	{
		ptr->y = 0;
		while (ptr->y < HEIGH)
		{
			if (!(ptr = draw[ptr->fract](ptr)))
				return (NULL);
			ptr->y += 1;
		}
		ptr->x += 1;
	}
	return (ptr);
}

int			ft_fractol(t_env *ptr)
{
	if (!(ptr = ft_draw(ptr)))
		return (0);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ft_name(ptr);
	if (ptr->toogle == 1)
		ft_command(ptr);
	mlx_hook(ptr->win_ptr, 2, 1L << 0, key_hook, ptr);
	mlx_mouse_hook(ptr->win_ptr, mouse_zoom, ptr);
	if (ptr->jmouse == 0)
		mlx_hook(ptr->win_ptr, 6, 1L << 6, mouse_julia, ptr);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->mlx_ptr);
	return (1);
}
