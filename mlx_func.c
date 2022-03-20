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
    mlx_loop_hook(ptr->mlx, putImage, ptr);
    mlx_key_hook(ptr->win, &handleKeyPress, ptr);
    mlx_hook(ptr->win, X_EVENT_X_BUTTON, 0, &handleClick, NULL);
    mlx_loop(ptr->mlx);
}
void move(t_map *ptr, int x,int y)
{
    if (ptr->map[x][y] == '1')
        return ;
    (ptr->move)++;
    ft_putnbr_fd(ptr->move, 1);
    ft_putchar_fd('\n', 1);
    if (ptr->map[x][y] == 'C')
    {
        (ptr->collect)--;
        ptr->map[x][y] = '0';
    }
    if (ptr->map[x][y] == 'E' && !ptr->collect)
    {
        ft_putstr_fd("Game Clear", 1);
        exit(EXIT_SUCCESS);
    }
    ptr-> x = x;
    ptr-> y = y;
}
int handleKeyPress(int keycode, t_map *ptr)
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

int handleClick(void)
{
    exit(EXIT_SUCCESS);
}
int putImage(t_map *ptr)
{
    int i;
    int j;

    mlx_clear_window(ptr->mlx, ptr->win);
    i = 0;
    while (i < ptr->mapHeight)
    {
        j = 0;
        while (j < ptr->mapWidth)
        {
            if(ptr->map[i][j])
                putObject(ptr, i, j);
            if (i == ptr->x && j == ptr->y)
            mlx_put_image_to_window(ptr->mlx, ptr->win, \
            ptr->playerImg, j * IMG_SIZE, i * IMG_SIZE);
            ++j;
        }
        ++i;
    }
    return (0);
}
void putObject(t_map *ptr, int i, int j)
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