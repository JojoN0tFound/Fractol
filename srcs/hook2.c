/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:01:51 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/21 13:11:18 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
		ptr->fract %= 7;
		ptr->init = 0;
		ft_fractol(ptr);
	}
	return (0);
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
