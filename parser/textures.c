/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:03 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/19 10:52:04 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * find texture code
 */
int	find_path_type(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, "NO ", 3))
			return (NO);
		else if (!ft_strncmp(s + i, "SO ", 3))
			return (SO);
		else if (!ft_strncmp(s + i, "EA ", 3))
			return (EA);
		else if (!ft_strncmp(s + i, "WE ", 3))
			return (WE);
		i++;
	}
	return (NONE);
}

/*
 * read line from i=3 since the first 3 characters have been validated
 * 
 */
mlx_texture_t	*save_texture(char *s)
{
	mlx_texture_t	*texture;
	int				i;

	i = 3;
	texture = NULL;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != 9)
		{
			if (!ft_ispath(s + i))
				exit(cub_error(TEX_PATH_ERROR));
			else
			{
				texture = mlx_load_png(s + i);
				if (!texture)
					exit(cub_error(TEX_MLX_LOAD_PNG_ERROR));
				break ;
			}
		}
		i++;
	}
	return (texture);
}
