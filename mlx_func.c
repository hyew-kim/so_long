#include <mlx/mlx.h>
#include "so_long.h"

void mlx_main(t_map *ptr)
{
    int w = IMG_SIZE;
    int h = IMG_SIZE;
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, ptr->mapWidth * IMG_SIZE, ptr->mapHeight * IMG_SIZE, "so_long");
    ptr->exitImg = mlx_xpm_file_to_image(ptr->mlx, "images/azazel01.xpm", &w, &h);
    ptr->collectImg = mlx_xpm_file_to_image(ptr->mlx, "images/key01.xpm", &w, &h);
    ptr->playerImg = mlx_xpm_file_to_image(ptr->mlx, "images/hero01.xpm", &w, &h);
    ptr->wallImg = mlx_xpm_file_to_image(ptr->mlx, "images/box01.xpm", &w, &h);
    ptr->bgImg = mlx_xpm_file_to_image(ptr->mlx, "images/background.xpm", &w, &h);
    putImage(ptr);
    mlx_loop(ptr->mlx);
}
void putImage(t_map *ptr)
{
    int i;
    int j;

    i = 0;
    while (i < ptr->mapHeight)
    {
        j = 0;
        while (j < ptr->mapWidth)
        {
            printf("%c", ptr->map[i][j]);
            if(ptr->map[i][j])
                putObject(ptr, i, j);
            ++j;
        }
        ++i;
    }
}
void putObject(t_map *ptr, int i, int j)
{
    if (ptr->map[i][j] == '1')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->wallImg, j * IMG_SIZE, i * IMG_SIZE);
    else if (ptr->map[i][j] == 'P')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->playerImg, j * IMG_SIZE, i * IMG_SIZE);
    else if (ptr->map[i][j] == 'C')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->collectImg, j * IMG_SIZE, i * IMG_SIZE);
    else if (ptr->map[i][j] == 'E')
        mlx_put_image_to_window(ptr->mlx, ptr->win, \
        ptr->exitImg, j * IMG_SIZE, i * IMG_SIZE);
}