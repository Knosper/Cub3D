/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:59:32 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/07 01:42:25 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	print_map_param(t_data *data)
{
	printf("path =%s\n", data->map_path);
	printf("f_colour = %x\n", data->f_colour);
	printf("c_colour = %x\n", data->c_colour);
	ft_print_split(data->map_data);
	printf("\n");
}
