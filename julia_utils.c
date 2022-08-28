/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:14:37 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 02:32:47 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "mapping.h"

int	ft_mouse_hook_julia(int button, int x, int y, void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP)
		ft_zoom(&p->base);
	else if (button == MOUSE_WHEEL_DOWN)
		ft_dezoom(&p->base);
	ft_julia(p, p->img);
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->img->img, 0, 0);
	ft_img_swap(p);
	return (0);
}

int	ft_julia_exit(int keycode, void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	if (keycode == MAP_ESC)
	{
		destroy_img(p->mlx, p->img);
		destroy_img(p->mlx, p->tmp);
		mlx_destroy_window(p->mlx, p->mlx_win);
		exit (0);
	}
	ft_move(keycode, a, 1);
	ft_julia(p, p->img);
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->img->img, 0, 0);
	ft_img_swap(p);
	return (0);
}
