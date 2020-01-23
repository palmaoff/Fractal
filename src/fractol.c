#include "../includes/fract_ol.h"

void	fractol(t_mlx *mlx)
{
	t_cmplx min;
	t_cmplx max;
	t_cmplx scrn;

	min.re = -2.0;
	max.re = 2.0;
	min.im = -2.0;
	max.im = 2.0; // change it
	scrn.re = (max.re - min.re) / (WIDTH - 1);
}
