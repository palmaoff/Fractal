/*
**	created by eflorean
*/

#include "../includes/fract_ol.h"

static	void	*peace(void *mlx)
{
	t_mlx *m;
	int i;

	m = (t_mlx *)mlx;
	i = 0;
	while (i < 20)
	{
		if (pthread_equal(pthread_self(), m->p[i]))
			draw_fractal(m, i * (HEIGHT / 20), i * (HEIGHT / 20) + (HEIGHT / 20));
		i++;
	}
	return (0);
}

void	peaces(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < 20)
	{
		pthread_create(&mlx->p[i], NULL, peace, mlx);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		pthread_join(mlx->p[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
