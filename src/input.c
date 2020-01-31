/*
**  created by eflorean
*/

#include "../includes/fract_ol.h"

void    input(char *s, t_mlx *mlx)
{
    (void)mlx;
    if (s[0] != '-' && ft_strlen(s) != 2)
        die("Invalid argument\n");
    if (s[1] == 'M')
        mlx->f = &mandelbrot;
    else if (s[1] == 'J')
        mlx->f = &julia;
    else if (s[1] == 'Z')
        mlx->f = &meduza;
    else
        die("Invalid argument\n");
}