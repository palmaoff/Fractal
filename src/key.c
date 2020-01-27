/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:52:22 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/22 13:48:03 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void			die(char *str)
{
	ft_putstr(str);
	exit(0);
}
/*
static	int		key_press_again(int keycode, t_mlx *mlx)
{
	// code
	print_map(mlx);
	return (0);
}

static	int		key_press_too_too(int keycode, t_mlx *mlx)
{
	// code
	key_press_again(keycode, mlx);
	return (0);
}

static	int		key_press_too(int keycode, t_mlx *mlx)
{
	// code
	key_press_too_too(keycode, mlx);
	return (0);
}
*/
int				key_press(int keycode, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		mlx->x_mv -= 0.01;
	if (keycode == 2)
		mlx->x_mv += 0.01;
	if (keycode == 13)
		mlx->y_mv += 0.01;
	if (keycode == 1)
		mlx->y_mv -= 0.01;
	if (keycode == 83)
		if (mlx->r != 0)
			mlx->r -= 0x010000;
	if (keycode == 84)
		mlx->r += 0x010000;
	if (keycode == 85)
		mlx->r = 0x000000;
	if (keycode == 86)
		if (mlx->g != 0)
			mlx->g -= 0x000100;
	if (keycode == 87)
		mlx->g += 0x000100;
	if (keycode == 88)
		mlx->g = 0x000000;
	if (keycode == 89)
		if (mlx->b != 0)
			mlx->b -= 0x000001;
	if (keycode == 91)
		mlx->b += 0x000001;
	if (keycode == 92)
		mlx->b = 0x000000;
	draw_fractal(mlx);
	return (0);
}
