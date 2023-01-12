/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:23:03 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 16:18:32 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_text(char **map, int *tx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_strncmp(map[i] + j, "NO ", 3))
				tx[0] += 1;
			else if (!ft_strncmp(map[i] + j, "SO ", 3))
				tx[1] += 1;
			else if (!ft_strncmp(map[i] + j, "EA ", 3))
				tx[2] += 1;
			else if (!ft_strncmp(map[i] + j, "WE ", 3))
				tx[3] += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (tx[0] != 1 || tx[1] != 1 || tx[2] != 1 || tx[3] != 1)
		return (1);
	return (0);
}

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
	return (0);
}

int	check_arg(char *s)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	if (len < 4)
		return (1);
	while (s[i])
	{
		i++;
		if (s[i] == '.' && s[i + 1])
		{
			i++;
			if (!ft_strncmp(s + i, "cub", 5))
				return (0);
		}
	}
	return (1);
}

static int	player_top_surrounded(char *map, int j)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (map[k])
	{
		if (k == j - 1)
		{
			if (map[k] != '0' || map[k] != '1')
				return (0);
			count++;
		}
		if (k == j + 1)
		{
			if (map[k] != '0' || map[k] != '1')
				return (0);
			count++;
		}
		if (k == j)
		{
			if (map[k] != '0' || map[k] != '1')
				return (0);
			count++;
		}
		k++;
	}
	if (count != 3)
		return (0);
	return (1);
}

static int	player_surrounded(char **map, int i, int j)
{
	player_top_surrounded(map[i - 1], j);
	return (1);
}

void	player_checks(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				if (i == 0 || j == 0 || !player_surrounded(data->map, i, j))
					exit(cub_error(PLAYER_ERROR));
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		exit(cub_error(PLAYER_ERROR));
}