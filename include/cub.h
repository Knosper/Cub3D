/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/07 21:21:11 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "macros.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//debugtools/print_all.c
void	print_map_param(t_data *data);
int		cub_error(int err);

//parser/checks.c
int		check_text(char **map, int *tx);
int		find_path_type(char *s);
int		check_arg(char *s);

//parser/init_data.c (FULL)
t_data	*init_data(char **argv);

//parser/init_data_helper.c
char	**get_map(char *path);

//parser/bools.c
bool	validate_mapchars(char **map);
bool	check_map(char *s);
bool	is_mapchar(char c);
bool	is_player(char c);

//parser/colours_texture.c (FULL)
void	check_colours(t_data *data, char *s);
void	init_texture(t_data *data, char *s, int mod);

//src/start_cub.c
void	start_cub(t_data *data);
void	skyline(t_cub *m);
void	clean_mlx(t_cub *m);

//src/hooks.c
void	hooks(t_cub *m);
void	screensize(t_cub *m);

//src/keys.c
void	cub_keys(mlx_key_data_t key, void *param);
void	resize_screen(int32_t x, int32_t y, void *param);

#endif