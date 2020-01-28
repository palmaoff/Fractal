/*
**	created by eflorean
*/

#include "../includes/fract_ol.h"

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
		zoom = 1.0 / 1.20;
	else if (button == 5)
		zoom = 1.0 / 0.80;
	else
		return (0);	
	mlx->max.re = change_it(crnt.re, mlx->max.re, zoom);
	mlx->min.re = change_it(crnt.re, mlx->min.re, zoom);
	mlx->max.im = change_it(crnt.im, mlx->max.im, zoom);
	mlx->min.im = change_it(crnt.im, mlx->min.im, zoom);
	peaces(mlx);
	return (0);
}