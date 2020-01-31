/*
**	created by eflorean
*/

#include "../includes/fractol.h"

static double	change_it(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int				zoom(int button, int x, int y, t_mlx *mlx)
{
	t_cmplx crnt;
	double zoom;

	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	crnt = init_cmplx(
		(double)x / (WIDTH / (mlx->max.re - mlx->min.re))
				+ mlx->min.re,
		(double)y / (HEIGHT / (mlx->max.im - mlx->min.im))
				* -1 + mlx->max.im);
	if (button == 4)
		zoom = 0.95;
	else if (button == 5)
		zoom = 1.3;
	else if (button == 1)
	{
		mlx->bool = 1;
		return (0);
	}
	else
		return (0);
	mlx->max.re = change_it(crnt.re, mlx->max.re, zoom);
	mlx->min.re = change_it(crnt.re, mlx->min.re, zoom);
	mlx->max.im = change_it(crnt.im, mlx->max.im, zoom);
	mlx->min.im = change_it(crnt.im, mlx->min.im, zoom);
	mlx->delta = (mlx->max.re - mlx->min.re) / 300;
	peaces(mlx);
	return (0);
}

int julia_motion(int x, int y, t_mlx *mlx)
{
    mlx->k = init_cmplx(
        4 * ((double)x / WIDTH * 0.6 - 0.3),
        4 * ((double)(HEIGHT - y) / HEIGHT * 0.6 - 0.3));
    peaces(mlx);
    return (0);
}