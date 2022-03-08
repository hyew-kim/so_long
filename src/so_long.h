/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:30:00 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/08 23:13:40 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

/*macro*/
#define ERROR -1
#define SUCCUESS 1
#define E_O_F 0
#define OPEN_MAX 255

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

/*include library*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

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
 *		int cnt;
 *		int[2] position;
 *		int? status
 * }t_object
 * main -> t_object player / t_object collect ...
 * 이런
 */

/*prototype*/
void check_input(int argc, char *argv[]);
int get_next_line(int fd, char **line);
int return_line(char **backup_fd, char **line);
int return_line_in_nl(char **backup_fd, char **line, int idx_nl);
int set_backup(char **backup_fd, char *buf);
void count_object(char *line, t_map *map);
void check_object_count(t_map *map);
void init(t_map *map);

#endif
