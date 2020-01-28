#include "../includes/fract_ol.h"

t_cmplx init_cmplx(double re, double im)
{
    t_cmplx cmplx;
    
    cmplx.re = re;
    cmplx.im = im;
    return (cmplx);
}

void	draw_fractal(t_mlx *mlx, int s, int e)
{
	int x;
	int	y;
	int i;
	int color;

	y = s;
	while (y < e)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = mandelbrot(mlx, x, y);
			color = i * mlx->r + i * mlx->g + i * mlx->b;
			mlx->img.data[y * WIDTH + x] = (i < 50) ? color : 0;
			x++;
		}
		y++;
	}
}

int		mandelbrot(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = 50;
	mlx->scrn.re = (mlx->max.re - mlx->min.re) / (WIDTH - 1);
	mlx->scrn.im = (mlx->max.im - mlx->min.im) / (HEIGHT - 1);
	c.im = mlx->max.im - y * mlx->scrn.im + mlx->y_mv;
	c.re = mlx->min.re + x * mlx->scrn.re + mlx->x_mv;
	z = init_cmplx(c.re, c.im);
	while (z.re * z.re + z.im * z.im <= 4 && i < max_i)
	{
		z = init_cmplx(
		z.re * z.re - z.im * z.im + c.re,
		2.0 * z.re * z.im + c.im);
		i++;
	}
	return (i);
}