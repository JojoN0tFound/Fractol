/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:11:20 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/16 02:27:54 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double		ft_abs(double a)
{
	return (a >= 0 ? a : -a);
}

double		ft_max(double b, double r, double v)
{
	if (b > r && b >= v)
		return (b);
	else if (r > v && r > b)
		return(r);
	else if (v > b && v >= r)
		return (v);
	return (b);
}
