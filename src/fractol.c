#include "../includes/fract_ol.h"

t_cmplx init_cmplx(double re, double im)
{
    t_cmplx cmplx;
    
    cmplx.re = re;
    cmplx.im = im;
    return (cmplx);
}

void	color(t_mlx *mlx, int i, int x, int y)
{
	double t;
	int red;
	int green;
	int blue;
	int max_i = 50;

	t = (double)i / (double)max_i;

	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	mlx->img.data[y * WIDTH + x] = (red << 16) | (green << 8) | blue;
}

void	fractol(t_mlx *mlx)
{
	t_cmplx min;
	t_cmplx max;
	t_cmplx scrn;
	t_cmplx c;
	t_cmplx z;
	size_t	max_i = 50;
	size_t i;
	int x;
	int y;

	min.re = -2.0;
	max.re = 2.0;
	min.im = -2.0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;

	scrn.re = (max.re - min.re) / (WIDTH - 1);
	scrn.im = (max.im - min.im) / (HEIGHT - 1);

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		c.im = max.im - y * scrn.im;
		while (x < WIDTH)
		{
			c.re = min.re + x * scrn.re;
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
			color(mlx, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
