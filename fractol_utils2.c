/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:33:22 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 02:30:41 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "mapping.h"

void	destroy_img(void *mlx, t_img *i)
{
	mlx_destroy_image(mlx, i->img);
	free(i);
}

int	quit_hook_func(void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	destroy_img(p->mlx, p->img);
	destroy_img(p->mlx, p->tmp);
	mlx_destroy_window(p->mlx, p->mlx_win);
	exit (0);
}

void	ft_move(int keycode, void *a, int f)
{
	t_prg	*p;

	p = (t_prg *)a;
	if (keycode == MAP_Q)
		ft_zoom(&p->base);
	else if (keycode == MAP_E)
		ft_dezoom(&p->base);
	else if (keycode == MAP_S)
		ft_down(&p->base);
	else if (keycode == MAP_W)
		ft_up(&p->base);
	else if (keycode == MAP_D)
		ft_droite(&p->base);
	else if (keycode == MAP_A)
		ft_gauche(&p->base);
	else if (keycode == MAP_R && f == 1)
		p->base = ft_julia_base();
	else if (keycode == MAP_R && f == 0)
		p->base = ft_base();
	if (keycode == MAP_L)
		p->boole = !p->boole;
}
