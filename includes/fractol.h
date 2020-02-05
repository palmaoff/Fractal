#ifndef FRACT__OL_H
# define FRACT__OL_H
# define WIDTH 720
# define HEIGHT 720
# define PEACES 50

# include <stdio.h> // KILL ME
# include "mlx.h"
# include <unistd.h>
# include <pthread.h>
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
	t_cmplx			k;
	double			delta;
	double			x_mv;
	double			y_mv;
	size_t			depth;
	int				bool;
	int				(*f)(struct s_mlx *mlx, int x, int y);
}					t_mlx;

typedef struct		s_peace
{
	t_mlx			*mlx;
	pthread_t		p;
	int				i;
}					t_peace;

void			img_new(t_mlx *mlx);
void			fractol(t_mlx *mlx);
void			die(char *str);
int				key_press(int keycode, t_mlx *mlx);
void			draw_fractal(t_mlx *mlx, int s, int e);
int				mandelbrot(t_mlx *mlx, int x, int y);
t_cmplx 		init_cmplx(double re, double im);
int				zoom(int button, int x, int y, t_mlx *mlx);
void			peaces(t_mlx *mlx);
int				julia(t_mlx *mlx, int x, int y);
int				julia_motion(int x, int y, t_mlx *mlx);
int				meduza(t_mlx *mlx, int x, int y);
int				sierpinski(t_mlx *mlx, int x, int y);
void    		input(char *s, t_mlx *mlx);

#endif