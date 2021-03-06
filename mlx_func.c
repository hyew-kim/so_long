#include <mlx/mlx.h>
#include "so_long.h"

void	mlx_main(t_map *ptr)
{
	int w;
	int h;

    w = IMG_SIZE;
    h = IMG_SIZE;
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, ptr->mapWidth * IMG_SIZE, ptr->mapHeight * IMG_SIZE, "so_long");
    ptr->exitImg = mlx_xpm_file_to_image(ptr->mlx, "images/azazel01.xpm", &w, &h);
    ptr->collectImg = mlx_xpm_file_to_image(ptr->mlx, "images/key01.xpm", &w, &h);
    ptr->playerImg = mlx_xpm_file_to_image(ptr->mlx, "images/hero01.xpm", &w, &h);
    ptr->wallImg = mlx_xpm_file_to_image(ptr->mlx, "images/box01.xpm", &w, &h);
    ptr->bgImg = mlx_xpm_file_to_image(ptr->mlx, "images/background.xpm", &w, &h);
    mlx_loop_hook(ptr->mlx, putImage, ptr);
    mlx_hook(ptr->win, ON_KEYDOWN , 0, &handleKeyPress, ptr);
    mlx_hook(ptr->win, ON_DESTORY, 0, &handleClick, NULL);
    mlx_loop(ptr->mlx);
}

int	handleKeyPress(int keycode, t_map *ptr)
{
    if (keycode == KEY_ESC)
        exit(EXIT_SUCCESS);
    else if (keycode == KEY_S)
        move(ptr, ptr->x + 1, ptr->y);
    else if (keycode == KEY_D)
        move(ptr, ptr->x, ptr->y + 1);
    else if (keycode == KEY_W)
        move(ptr, ptr->x - 1, ptr->y);
    else if (keycode == KEY_A)
        move(ptr, ptr->x, ptr->y - 1);
    return (0);
}

int	handleClick(void)
{
    exit(EXIT_SUCCESS);
}

int	putImage(t_map *ptr)
{
    int i;
    int j;

    mlx_clear_window(ptr->mlx, ptr->win);
    i = -1;
    while (++i < ptr->mapHeight)
    {
        j = -1;
        while (++j < ptr->mapWidth)
        {
            if(ptr->map[i][j])
                putObject(ptr, i, j);
            if (i == ptr->x && j == ptr->y)
            mlx_put_image_to_window(ptr->mlx, ptr->win, \
            ptr->playerImg, j * IMG_SIZE, i * IMG_SIZE);
        }
    }
    return (0);
}

void    putObject(t_map *ptr, int i, int j)
{
    if (ptr->map[i][j] == '1')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->wallImg, j * IMG_SIZE, i * IMG_SIZE);
    else if (ptr->map[i][j] == 'C')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->collectImg, j * IMG_SIZE, i * IMG_SIZE);
    else if (ptr->map[i][j] == 'E')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->exitImg, j * IMG_SIZE, i * IMG_SIZE);
}