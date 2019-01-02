/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:08:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/02 16:13:23 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_close(t_env *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
	return (0);
}

int		key_hook(int x, t_env *ptr)
{
	ft_bzero(ptr->buff, HEIGH * WIDTH * 4);
	ptr->init = 1;
	x == 53 ? ft_close(ptr) : 1;
	// x == 0 ? ft_move(ptr, x) : 1;
	// x == 1 ? ft_move(ptr, x) : 1;
	// x == 2 ? ft_move(ptr, x) : 1;
	// x == 13 ? ft_move(ptr, x) : 1;
	// x == 126 ? ft_zoom(x, ptr) : 1;
	// x == 125 ? ft_zoom(x, ptr) : 1;
	// x == 8 ? ft_color(x, ptr) : 1;
	return (0);
}
