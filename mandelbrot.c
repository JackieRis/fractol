/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:24:50 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 02:27:18 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "mapping.h"

t_fract	ft_base(void)
{
	t_fract	base;

	base.minr = -2.0;
	base.maxr = 1.0;
	base.mini = -1.2;
	base.maxi = 1.2;
	base.distx = base.maxr - base.minr;
	base.disty = base.maxi - base.mini;
	return (base);
}

static int	ft_calcul(t_fract *base)
{
	t_vec	opti;
	int		iter;

	iter = 0;
	base->z.x = 0;
	base->z.y = 0;
	opti = (t_vec){0.0, 0.0};
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

void	ft_mandelbrot(t_prg *p, t_img *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		p->base.c.y = p->base.mini + y * p->base.disty / WIN_H;
		while (++x < WIN_W)
		{
			p->base.c.x = p->base.minr + x * p->base.distx / WIN_W;
			ft_putpx(img, x, y, ft_calcul(&p->base));
		}
	}	
}

void	launch_mandelbrot(void)
{
	t_prg	prg;

	prg.mlx = mlx_init();
	prg.mlx_win = mlx_new_window(prg.mlx, WIN_W, WIN_H, "Fractol");
	prg.img = new_img(prg.mlx, WIN_W, WIN_H);
	prg.tmp = new_img(prg.mlx, WIN_W, WIN_H);
	prg.base = ft_base();
	ft_mandelbrot(&prg, prg.img);
	mlx_put_image_to_window(prg.mlx, prg.mlx_win, prg.img->img, 0, 0);
	ft_img_swap(&prg);
	mlx_hook(prg.mlx_win, 17, (1L << 17), quit_hook_func, &prg);
	mlx_key_hook(prg.mlx_win, ft_exit, &prg);
	mlx_mouse_hook(prg.mlx_win, ft_mouse_hook, &prg);
	mlx_loop(prg.mlx);
}
