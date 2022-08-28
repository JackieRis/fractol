/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:03:26 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/23 23:39:23 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpx(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel);
	*(unsigned int *)dst = color;
}

void	ft_cercle(t_img *img, int x, int y, int color)
{
	int		i;
	float	tmp;

	i = 0;
	while (i < 3600)
	{
		tmp = (float)i / 1800 * M_PI;
		ft_putpx(img, x + sin(tmp) * 300, y + cos(tmp) * 300, color);
		i++;
	}
}

unsigned char	ft_lerp(unsigned char v0, unsigned char v1, float t)
{
	return (v0 + t * (v1 - v0));
}

int	ft_color(int iter)
{
	int		color;
	float	t;
	t_color	c;

	t = (float)iter / (float)MAX_ITER;
	c.r = ft_lerp(0x69, 0xFB, t);
	c.g = ft_lerp(0x1E, 0xBA, t);
	c.b = ft_lerp(0x06, 0x72, t);
	color = c.r * 256 * 256 + c.g * 256 + c.b;
	return (color);
}

void	ft_img_swap(t_prg *p)
{
	t_img	*t;

	t = p->img;
	p->img = p->tmp;
	p->tmp = t;
}
