/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fracmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:07:17 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 02:32:32 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mapping.h"
#include "mlx/mlx.h"

void	ft_droite(t_fract *base)
{
	base->minr += base->distx * MOVE;
	base->maxr += base->distx * MOVE;
}

void	ft_gauche(t_fract *base)
{
	base->minr -= base->distx * MOVE;
	base->maxr -= base->distx * MOVE;
}

void	ft_down(t_fract *base)
{
	base->mini += base->disty * MOVE;
	base->maxi += base->disty * MOVE;
}

void	ft_up(t_fract *base)
{
	base->mini -= base->disty * MOVE;
	base->maxi -= base->disty * MOVE;
}

int	ft_exit(int keycode, void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	ft_move(keycode, a, 0);
	if (keycode == MAP_ESC)
		exit (0);
	ft_mandelbrot(p, p->img);
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->img->img, 0, 0);
	ft_img_swap(p);
	return (0);
}
