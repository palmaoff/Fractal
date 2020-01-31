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
	size_t i;
	int color;

	y = s;
	while (y < e)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->scrn.re = (mlx->max.re - mlx->min.re) / (WIDTH - 1);
			mlx->scrn.im = (mlx->max.im - mlx->min.im) / (HEIGHT - 1);
			i = mlx->f(mlx, x, y);
			color = i * (mlx->r + mlx->g + mlx->b);
			mlx->img.data[y * WIDTH + x] = (i < mlx->depth) ? color : 0;
			x++;
		}
		y++;
	}
}
/*
int fractal()
{
	
}
*/
int		mandelbrot(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = mlx->depth;
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

int		julia(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	k;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = mlx->depth;
	c.im = mlx->max.im - y * mlx->scrn.im + mlx->y_mv;
	c.re = mlx->min.re + x * mlx->scrn.re + mlx->x_mv;
	z = init_cmplx(c.re, c.im);
//	mlx->k = init_cmplx(-0.4, 0.6);
	k = mlx->k;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4
    	&& i < max_i)
	{
    	z = init_cmplx(
        z.re * z.re - z.im * z.im + k.re,
        	2.0 * z.re * z.im + k.im);
    	i++;
	}
	return (i);
}

int		meduza(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = mlx->depth;
	c.im = mlx->max.im - y * mlx->scrn.im + mlx->y_mv;
	c.re = mlx->min.re + x * mlx->scrn.re + mlx->x_mv;
	z = init_cmplx(c.re, c.im);
	while (z.re * z.re + z.im * z.im <= 4
    	&& i < max_i)
	{
    	z = init_cmplx(
        	fabs(z.re * z.re - z.im * z.im) + c.re,
        	-2.0 * z.re * z.im + c.im);
    	i++;
	}
	return (i);
}


int		sierpinski(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = mlx->depth;
	c.im = mlx->max.im - y * mlx->scrn.im + mlx->y_mv;
	c.re = mlx->min.re + x * mlx->scrn.re + mlx->x_mv;
	z = init_cmplx(c.re, c.im);
	while (z.re * z.re + z.im * z.im <= 4
    	&& i < max_i)
	{
		if (z.re - (int)(z.re / 3) * 3 > 1.0 && z.im - (int)(z.re / 3) * 3 > 1.0 &&
			z.re - (int)(z.re / 3) * 3 < 2.0 && z.im - (int)(z.re / 3) * 3 < 2.0)
			return (0);
    	z = init_cmplx(z.re / 3, z.im / 3);
    	i++;
	}
	return (12);
}
