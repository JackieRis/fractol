/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:01:59 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/06 12:20:19 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define WIN_W 1600
# define WIN_H 900
# define MAX_ITER 128
# define ZOOM 0.90
# define MOVE 0.05

typedef long double	t_ld;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_vec
{
	t_ld		x;
	t_ld		y;
}				t_vec;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_fract
{
	t_ld	minr;
	t_ld	maxr;
	t_ld	mini;
	t_ld	maxi;
	t_ld	distx;
	t_ld	disty;
	t_ld	zminr;
	t_ld	zmaxr;
	t_ld	zmini;
	t_ld	zmaxi;
	t_vec	c;
	t_vec	z;
}	t_fract;

typedef struct s_prg
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_img	*tmp;
	t_fract	base;
	int		boole;
}	t_prg;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_putpx(t_img *img, int x, int y, int color);
void	ft_cercle(t_img *img, int x, int y, int color);
void	ft_mandelbrot(t_prg *p, t_img *img);
int		ft_color(int iter);
void	ft_zoom(t_fract *base);
t_fract	ft_base(void);
void	ft_dezoom(t_fract *base);
void	ft_droite(t_fract *base);
void	ft_gauche(t_fract *base);
void	ft_down(t_fract *base);
void	ft_up(t_fract *base);
void	launch_mandelbrot(void);
int		ft_exit(int keycode, void *a);
int		ft_mouse_hook(int button, int x, int y, void *a);
t_img	*new_img(void *mlx, int w, int h);
void	launch_julia(void);
void	ft_julia(t_prg *p, t_img *img);
int		mlx_mouse_get_pose(void *win_ptr, int *x, int *y);
int		loop_hook(void *a);
int		ft_mouse_hook_julia(int button, int x, int y, void *a);
int		ft_julia_exit(int keycode, void *a);
t_fract	ft_julia_base(void);
void	ft_img_swap(t_prg *p);
void	destroy_img(void *p, t_img *i);
void	ft_move(int keycode, void *a, int f);
int		quit_hook_func(void *a);

#endif