/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:08:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/14 19:37:52 by jquivogn         ###   ########.fr       */
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
		ptr->x1 += 15;
		ft_fractol(ptr);
	}
	else if (x == 13)
	{
		ptr->y1 += 15;
		ft_fractol(ptr);
	}
	else if (x == 2)
	{
		ptr->x1 -= 15;
		ft_fractol(ptr);
	}
	else if (x == 1)
	{
		ptr->y1 -= 15;
		ft_fractol(ptr);
	}
	return (0);
}

int		ft_changefract(int x, t_env *ptr)
{
	if (x == 8)
	{
		ptr->fract += 1;
		ptr->fract %= 3;
		ft_fractol(ptr);
	}
	return (0);
}

int		ft_zoom(int x, t_env *ptr)
{
	if (x == 126)
	{
		ptr->x1 += ptr->x1 / 4;
		ptr->y1 += ptr->y1 / 4;
		ptr->name.zoom *= 1.3;
		ptr->name.xz *= 1.3;
		ptr->name.yz *= 1.3;
	}
	else
	{
		ptr->x1 -= ptr->x1 / 4;
		ptr->y1 -= ptr->y1 / 4;
		ptr->name.zoom /= 1.3;
		ptr->name.xz /= 1.3;
		ptr->name.yz /= 1.3;
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

int		select_color(int x, t_env *ptr)
{
	if (x == 18)
	{
		ptr->name.rd += 8;
		ptr->name.rd %= 24;
		ptr->name.color = 1;
	}
	ptr->name.color = x == 19 ? 2 : ptr->name.color;
	ptr->name.color = x == 20 ? 3 : ptr->name.color;
	ptr->name.color = x == 21 ? 4 : ptr->name.color;
	ft_fractol(ptr);
	return (1);
}

int		mouse_click_hook(int k, int x, int y, t_env *ptr)
{
	if (k == 5)
	{
		ptr->x1 += (x - WIDTH / 2);
		ptr->y1 += (y - HEIGH / 2);
		ptr->name.zoom = ptr->name.zoom * 1.2;
		ptr->name.yz = ptr->name.yz * 1.2;
		ptr->name.xz = ptr->name.xz * 1.2;
	}
	if (k == 4)
	{
		ptr->x1 -= (x - WIDTH / 2);
		ptr->y1 -= (y - HEIGH / 2);
		ptr->name.zoom = ptr->name.zoom / 1.2;
		ptr->name.yz = ptr->name.yz / 1.2;
		ptr->name.xz = ptr->name.xz / 1.2;
	}
	ft_fractol(ptr);
	return (0);
}

int		ft_toogle(t_env *ptr)
{
	ptr->toogle += 1;
	ptr->toogle %= 2;
	ft_fractol(ptr);
	return (0);
}

int		ft_itmax(int x, t_env *ptr)
{
	if (x == 69)
		ptr->name.itmax += 10;
	else if (x == 78)
		ptr->name.itmax -= 10;
	ft_fractol(ptr);
	return (0);
}

int		key_hook(int x, t_env *ptr)
{
	ft_bzero(ptr->buff, HEIGH * WIDTH * 4);
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
	x == 17 ? ft_toogle(ptr) : 1;
	x == 78 ? ft_itmax(x, ptr) : 1;
	x == 69 ? ft_itmax(x, ptr) : 1;
	if (x >= 18 && x <= 21)
		select_color(x, ptr);
	return (0);
}
