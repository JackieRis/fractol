/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:10:59 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/23 15:49:00 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_dezoom(t_fract *base)
{
	t_ld	d2;
	t_ld	dy;

	d2 = base->distx / ZOOM;
	base->minr += (base->distx - d2) / 2;
	base->maxr -= (base->distx - d2) / 2;
	base->distx = d2;
	dy = base->disty / ZOOM;
	base->mini += (base->disty - dy) / 2;
	base->maxi -= (base->disty - dy) / 2;
	base->disty = dy;
}

void	ft_zoom(t_fract *base)
{
	t_ld	d2;
	t_ld	dy;

	d2 = base->distx * ZOOM;
	base->minr += (base->distx - d2) / 2;
	base->maxr -= (base->distx - d2) / 2;
	base->distx = d2;
	dy = base->disty * ZOOM;
	base->mini += (base->disty - dy) / 2;
	base->maxi -= (base->disty - dy) / 2;
	base->disty = dy;
}
