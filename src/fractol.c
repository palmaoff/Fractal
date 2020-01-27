#include "../includes/fract_ol.h"

t_cmplx init_cmplx(double re, double im)
{
    t_cmplx cmplx;
    
    cmplx.re = re;
    cmplx.im = im;
    return (cmplx);
}

void	draw_fractal(t_mlx *mlx)
{
	int x;
	int	y;
	int i;
	int color;

	y = 0;
	while (y < HEIGHT)
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
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
/*
void	fractol(t_mlx *mlx)
{
	t_cmplx scrn;
	t_cmplx c;
	t_cmplx z;
	size_t	max_i = 50;
	size_t i;
	int x;
	int y;

	scrn.re = (mlx->max.re - mlx->min.re) / (WIDTH - 1);
	scrn.im = (mlx->max.im - mlx->min.im) / (HEIGHT - 1);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c.im = mlx->max.im - y * scrn.im;
		while (x < WIDTH)
		{
			c.re = mlx->min.re + x * scrn.re;
			z = init_cmplx(c.re, c.im);
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 
				&& i < max_i)
			{
				z = init_cmplx(
					pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
					2.0 * z.re * z.im + c.im);
				i++;
			}
//			color(mlx, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
*/
int		mandelbrot(t_mlx *mlx, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	size_t	max_i;
	size_t	i;

	i = 0;
	max_i = 50;
	c.im = mlx->max.im - y * mlx->scrn.im + mlx->y_mv;
	c.re = mlx->min.re + x * mlx->scrn.re + mlx->x_mv;
	z = init_cmplx(c.re, c.im);
	while (z.re * z.re + z.im * z.im <= 4 && i < max_i)
	{
		z = init_cmplx(
		pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
		2.0 * z.re * z.im + c.im);
		i++;
	}
	return (i);
}