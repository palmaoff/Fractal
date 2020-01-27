#ifndef FRACT__OL_H
# define FRACT__OL_H
# define WIDTH 1080
# define HEIGHT 1080

# include <stdio.h> // KILL ME
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_cmplx
{
	double	re;
	double	im;
}					t_cmplx;

typedef	struct		s_mlx
{
	char			*file;
	void			*mlx;
	void			*win;
	t_img			img;
	t_cmplx			min;
	t_cmplx			max;
	t_cmplx 		scrn;
	int				r;
	int				g;
	int				b;
	double			zoom;
	double			x_mv;
	double			y_mv;
}					t_mlx;

void			img_new(t_mlx *mlx);
void			fractol(t_mlx *mlx);
void			die(char *str); // maybe
int				key_press(int keycode, t_mlx *mlx);
void			draw_fractal(t_mlx *mlx);
int				mandelbrot(t_mlx *mlx, int x, int y);

#endif