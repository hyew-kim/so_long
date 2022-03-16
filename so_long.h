/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:30:00 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/17 02:02:28 by hyewonkim        ###   ########.fr       */
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
	int blank;
	int mapWidth;
	int mapHeight;
	int exit;
	char **map;
} t_map;

/*prototype*/
void printError(const char *errorMessage);
void closeWithError (int fd, const char *errorMessage);
void checkInput(int argc, char *argv[]);
int checkLine(char *line, t_map *map);
int checkMap(t_map *map);
void init(t_map *map);

#endif
