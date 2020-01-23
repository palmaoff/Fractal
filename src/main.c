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

int				key_press(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		hook_exit(void *param)
{
	(void)param;
	exit(0);
}

void	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "42");
	img_new(mlx);
}

int		main()
{
	t_mlx	mlx;

	init(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	fractal(&mlx);
//	mlx_hook(mlx.win, 4, 0, hook_mouse, &mlx);
//	mlx_hook(mlx.win, 5, 0, mouse_release, &mlx);
//	mlx_hook(mlx.win, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.win, 17, 0, hook_exit, mlx.mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
