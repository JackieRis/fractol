/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:39:14 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 05:16:35 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mapping.h"
#include "mlx/mlx.h"

t_fract	ft_julia_base(void)
{
	t_fract	base;

	base.minr = -2.0;
	base.maxr = 2.0;
	base.mini = -1.2;
	base.maxi = 1.2;
	base.distx = base.maxr - base.minr;
	base.disty = base.maxi - base.mini;
	base.c.x = -0.577;
	base.c.y = 0.478;
	base.z.x = 0;
	base.z.y = 0;
	return (base);
}

static int	ft_julia_calcul(t_fract *base)
{
	t_vec	opti;
	int		iter;

	iter = 0;
	opti = (t_vec){base->z.x * base->z.x, base->z.y * base->z.y};
	while (iter < MAX_ITER)
	{
		if (opti.x + opti.y > 4)
			return (ft_color(iter));
		base->z.y = base->z.x * base->z.y;
		base->z.y += base->z.y + base->c.y;
		base->z.x = opti.x - opti.y + base->c.x;
		opti.x = base->z.x * base->z.x;
		opti.y = base->z.y * base->z.y;
		iter++;
	}
	return (0);
}

void	ft_julia(t_prg *p, t_img *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			p->base.z.y = p->base.mini + y * p->base.disty / WIN_H;
			p->base.z.x = p->base.minr + x * p->base.distx / WIN_W;
			ft_putpx(img, x, y, ft_julia_calcul(&p->base));
		}
	}
}

int	mouse_motion_hook_func(int x, int y, void *a)
{
	t_prg	*p;

	p = a;
	if (p->boole == 1)
		return (1);
	p->base.c.x = (t_ld)(x - WIN_W / 2) / WIN_W * p->base.distx;
	p->base.c.y = (t_ld)(y - WIN_H / 2) / WIN_H * p->base.disty;
	ft_julia(p, p->img);
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->img->img, 0, 0);
	ft_img_swap(p);
	return (0);
}

void	launch_julia(void)
{
	t_prg	prg;

	prg.mlx = mlx_init();
	prg.mlx_win = mlx_new_window(prg.mlx, WIN_W, WIN_H, "Fractol");
	prg.img = new_img(prg.mlx, WIN_W, WIN_H);
	prg.tmp = new_img(prg.mlx, WIN_W, WIN_H);
	prg.base = ft_julia_base();
	prg.boole = 0;
	ft_julia(&prg, prg.img);
	mlx_put_image_to_window(prg.mlx, prg.mlx_win, prg.img->img, 0, 0);
	ft_img_swap(&prg);
	mlx_mouse_hook(prg.mlx_win, ft_mouse_hook_julia, &prg);
	mlx_hook(prg.mlx_win, 17, (1L << 17), quit_hook_func, &prg);
	mlx_hook(prg.mlx_win, 6, (1L << 6), mouse_motion_hook_func, &prg);
	mlx_key_hook(prg.mlx_win, ft_julia_exit, &prg);
	mlx_loop(prg.mlx);
}
