/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:47:20 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/26 18:14:02 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		hook_exit(void *param)
{
	(void)param;
	exit(0);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->bool == 1)
		julia_motion(x, y, mlx);
	return (0);
}

int unlock(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 1)
		mlx->bool = 0;
	return (0);
}

void	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fractol");
	img_new(mlx);
	mlx->min.re = -2.0;
	mlx->max.re = 2.0;
	mlx->min.im = -2.0;
	mlx->max.im = mlx->min.im + (mlx->max.re - mlx->min.re) * HEIGHT / WIDTH;
	mlx->r = 0x000000;
	mlx->g = 0x000000;
	mlx->b = 0x000005;
	mlx->delta = (mlx->max.re - mlx->min.re) / 300;
	mlx->depth = 50;
	mlx->bool = 0;
	mlx->k.re = -0.4;
	mlx->k.im = -0.6;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		die("Usage:\t./fractol [-MJZ]\n");
	(void)av;
	input(av[1], &mlx);
	init(&mlx);
	peaces(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 4, 0, zoom, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.win, 5, 0, unlock, &mlx);
	mlx_hook(mlx.win, 17, 0, hook_exit, mlx.mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
