/*
**	created by eflorean
*/

#include "../includes/fractol.h"

static	void	*peace_too(void *peace)
{
	t_peace *p;

	p = (t_peace *)peace;
	draw_fractal(p->mlx, p->i * (HEIGHT / PEACES), p->i * (HEIGHT / PEACES) + (HEIGHT / PEACES));
	return (0);
}

void	peaces(t_mlx *mlx)
{
	int i;
	t_peace peace[PEACES];

	i = 0;
	while (i < PEACES)
	{
		peace[i].i = i;
		peace[i].mlx = mlx;
		pthread_create(&(peace[i].p), NULL, peace_too, &(peace[i]));
		i++;
	}
	i = 0;
	while (i < PEACES)
	{
		pthread_join(peace[i].p, NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
