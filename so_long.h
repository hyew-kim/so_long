/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:30:00 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/11 22:18:45 by hyewonkim        ###   ########.fr       */
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
	int wall_low;
	int wall_coulmn;
	int exit;
} t_map;

/*
 * typedef struct s_object
 * {
 *      int cnt;
 *      int[2] position;
 *      int? status
 * }t_object
 * main -> t_object player / t_object collect ...
 * 이런
 */

/*prototype*/
void check_input(int argc, char *argv[]);
int set_backup(char **backup_fd, char *buf);
void count_object(char *line, t_map *map);
void check_object_count(t_map *map);
void init(t_map *map);

#endif
