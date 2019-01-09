/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:08:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/04 22:08:57 by julesqvgn        ###   ########.fr       */
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

int		ft_move(t_env *ptr, int x)
{
	if (x == 0)
	{
		ptr->x += 15;
		ft_fractol(ptr);
	}
	else if (x == 13)
	{
		ptr->y += 15;
		ft_fractol(ptr);
	}
	else if (x == 2)
	{
		ptr->x -= 15;
		ft_fractol(ptr);
	}
	else if (x == 1)
	{
		ptr->y -= 15;
		ft_fractol(ptr);
	}
	return (0);
}

int		ft_changefract(int x, t_env *ptr)
{
	if (x == 8)
	{
		ptr->fract += 1;
		ptr->fract %= 2;
		ft_fractol(ptr);
	}
	return (0);
}

int		ft_zoom(int x, t_env *ptr)
{
	if (x == 126)
	{
		ptr->name.zoom *= 1.3;
	}
	else
	{
		ptr->name.zoom /= 1.3;
	}
	ft_fractol(ptr);
	return (1);
}

int		ft_reset(t_env *ptr)
{
	ptr->init = 0;
	ft_fractol(ptr);
	return (1);
}

int		key_hook(int x, t_env *ptr)
{
	ft_bzero(ptr->buff, HEIGH * WIDTH);
	ptr->init = 1;
	x == 53 ? ft_close(ptr) : 1;
	x == 0 ? ft_move(ptr, x) : 1;
	x == 1 ? ft_move(ptr, x) : 1;
	x == 2 ? ft_move(ptr, x) : 1;
	x == 13 ? ft_move(ptr, x) : 1;
	x == 126 ? ft_zoom(x, ptr) : 1;
	x == 125 ? ft_zoom(x, ptr) : 1;
	x == 8 ? ft_changefract(x, ptr) : 1;
	x == 15 ? ft_reset(ptr) : 1;
	return (0);
}
