/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:12 by jjesberg          #+#    #+#             */
/*   Updated: 2022/11/29 00:22:14 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

int	init_map(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (ARG_ERROR);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MALLOC_ERROR);
	data->argc = argc;
	data->argv = argv;
	data->map = NULL; // 
	if (data->map == NULL)
		return (INVALID_MAP);
	return (0);
}
