/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/04 22:50:01 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "error.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//debugtools/print_all.c
void	print_map_param(t_data *data);

//init/init_data.c (3)
t_data	*init_data(int argc, char *argv[]);

//init/save_map_data.c (3)
int		find_map(char *map);
int		save_colours(char *s, t_data *data);

//init/bools_map.c (5) full
int		is_cardinal_direction(char c, char *s);
bool	is_surrounded_num(int i, int j, t_data *data);
bool	is_surrounded(int i, int j, t_data *data);
bool	is_player(char c);
bool 	check_surrounded_player(t_data *data);

//init/save_map.c (5) full
void 	save_cardinal_direction(t_data *data, int i, int j, int ret);
int		save_param(t_data *data);

//init/valid_map.c (5) full
int		check_params(t_data *data);

//valid_map_helper.c (3)
int	check_map(t_data *data);

//tools/utils.c (2)
int		sp_dg_skipper(char *s, int *i);
void	free_data(t_data *data);

//tools/error.c
int		error(int err);

//src/start_cub.c
int	start_cub(t_data *data);

#endif