/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:17:50 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/14 20:17:19 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h" 

t_env		*ft_draw(t_env *ptr)
{
	t_env	*(*draw[3])(t_env *);

	draw[0] = &ft_julia;
	draw[1] = &ft_mandelbrot;
	draw[2] = &ft_burningship;
	ptr->x = 0;
	while(ptr->x < WIDTH)
	{
		ptr->y = 0;
		while(ptr->y < HEIGH)
		{
			ptr = draw[ptr->fract](ptr);
			ptr->y += 1;
		}
		ptr->x += 1;
	}
	return(ptr);
}

int			ft_fractol(t_env *ptr)
{
	if (!(ptr = ft_draw(ptr)))
		return (0);
	put_pixel(ptr, 450, 375, 0x0);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	if (ptr->toogle == 1)
		ft_command(ptr);
	if (ptr->fract == 0)
		mlx_hook(ptr->win_ptr, 6, 1L << 6, mouse_julia, ptr);
	mlx_mouse_hook(ptr->win_ptr, mouse_click_hook, ptr);
	mlx_hook(ptr->win_ptr, 2, 1L << 0, key_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->mlx_ptr);
	return (1);
}
