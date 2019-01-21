/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:08:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/18 17:12:16 by julesqvgn        ###   ########.fr       */
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

int		mouse_zoom(int k, int x, int y, t_env *ptr)
{
	double	xtmp;
	double	ytmp;
	double	xtmp2;
	double	ytmp2;
	double	scale;

	x += ptr->x1;
	y += ptr->y1;
	xtmp = ptr->name.xmax - ptr->name.xmin;
	ytmp = ptr->name.ymax - ptr->name.ymin;
	scale = (k == 4) ? 1.2 : 0.8;
	xtmp2 = (ptr->name.xmin + ((double)x / ptr->name.zoom));
	ytmp2 = (ptr->name.ymin + ((double)y / ptr->name.zoom));
	ptr->name.xmin = xtmp2 - (xtmp2 - ptr->name.xmin) * scale;
	ptr->name.xmax = ptr->name.xmin + xtmp * scale;
	ptr->name.ymin = ytmp2 - (ytmp2 - ptr->name.ymin) * scale;
	ptr->name.ymax = ptr->name.ymin + ytmp * scale;
	ptr->name.zoom = WIDTH / (ptr->name.xmax - ptr->name.xmin);
	ptr->name.zoom <= 0 ? ptr->name.zoom = 0 : 1;
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
	if (x == 12)
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
	x == 8 ? ft_changefract(x, ptr) : 1;
	x == 15 ? ft_reset(ptr) : 1;
	x == 17 ? ft_toogle(ptr) : 1;
	x == 78 ? ft_itmax(x, ptr) : 1;
	x == 12 ? ft_itmax(x, ptr) : 1;
	if (x >= 18 && x <= 21)
		select_color(x, ptr);
	if (x == 49)
	{
		ptr->jmouse += 1;
		ptr->jmouse %= 2;
		ft_fractol(ptr);
	}
	return (0);
}
