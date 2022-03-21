/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:30:00 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/21 17:41:48 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

/*macro*/
# define ERROR -1
# define SUCCUESS 1
# define E_O_F 0
# define OPEN_MAX 255
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define IMG_SIZE 80
# define ON_DESTORY 17
# define ON_KEYDOWN 2
/*include library*/
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

/*object*/
typedef struct s_map
{
	int player;
	int collect;
	int mapWidth;
	int mapHeight;
	int exit;
	char **map;
	int x;
	int y;
	int move;
	void *mlx;
	void *win;
	void *playerImg;
	void *collectImg;
	void *exitImg;
	void *bgImg;
	void *wallImg;
} t_map;

/*prototype*/
int readMap(t_map *ptr, int fd);
void printError(char *errorMessage);
void closeWithError (int fd, char *errorMessage);
void checkInput(int argc, char *argv[]);
int checkLine(char *line, t_map *map);
int checkMap(t_map *map);
void init(t_map *map);
void mlx_main(t_map *ptr);
void move(t_map *ptr, int x,int y);
int handleKeyPress(int keycode, t_map *ptr);
int handleClick(void);
int putImage(t_map *ptr);
void putObject(t_map *ptr, int i, int j);

#endif
