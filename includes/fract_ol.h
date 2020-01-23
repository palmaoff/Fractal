#ifndef FRACT__OL_H
# define FRACT__OL_H
# define WIDTH 2048
# define HEIGHT 1080
# define MENU_WIDHT 300
# define DEPTH 1000

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
}					t_mlx;

void	img_new(t_mlx *mlx);

#endif