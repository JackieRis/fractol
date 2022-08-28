/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:00:31 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 04:53:32 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "mapping.h"

t_img	*new_img(void *mlx, int w, int h)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	img->bits_per_pixel /= 8;
	img->w = w;
	img->h = h;
	return (img);
}

void	ft_dessin(t_img *img)
{
	int	x;
	int	y;

	y = 400;
	while (y++ < 600)
	{
		x = 700;
		while (x++ < 900)
			ft_putpx(img, x, y, 0xED7AD6);
	}
}

int	ft_mouse_hook(int button, int x, int y, void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP)
		ft_zoom(&p->base);
	else if (button == MOUSE_WHEEL_DOWN)
		ft_dezoom(&p->base);
	ft_mandelbrot(p, p->img);
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->img->img, 0, 0);
	ft_img_swap(p);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Fractals disponibles:\n -Julia\n -Mandelbrot", 1);
		return (0);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
		launch_julia();
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		launch_mandelbrot();
	else
	{
		ft_putstr_fd("Fractals disponibles:\n -Julia\n -Mandelbrot", 1);
		return (0);
	}
	return (0);
}
