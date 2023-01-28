/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/28 19:55:39 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * update sreen sixe in cub struct
 */
void	handle_screen_resize(int32_t x, int32_t y, void *param)
{
	t_cub	*cub;
	static	int i;

	cub = (t_cub *)param;
	if (VERBOSE > 0)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
		printf("DEBUG: Resizing screen... %i \n", i);
	}
	cub->s_width = x;
	cub->s_height = y;
}

/*
 * TODO: prepare image for display in new position
 * may need several images to reach the new postion in smal steps
 */
void	move_fwd(void)
{
	if (VERBOSE > 0)
		printf("TODO: move forward");
}

/*
 * TODO implement movement [W|A|S|D] and look to side [arrows]
 * key codes:
 * ESC 256
 * W 87 - move forward
 * A 65 - move left
 * S 83 - move back
 * D 68 - move right
 * Left-arrow 263 - look left
 * Right-arrow 262
 */
void	handle_keypress(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	(void)key;
	cub = (t_cub *)param;
	if (key.key == 256)
	{
		mlx_close_window(cub->mlx);
		mlx_delete_image(cub->mlx, cub->image);
		return ;
	}
	else if (key.key == 87) 
	{
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'E') * 0.04;
			cub->ray->dir.x += (cub->direction == 'S') * 0.04;
		}
		cub->ray->dir.x -= (cub->direction == 'N') * 0.04;
		cub->ray->dir.y -= (cub->direction == 'W') * 0.04;
		//printf("dir x = %f\nray dir y = %f\n", cub->ray->dir.x, cub->ray->dir.y);
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 83) 
	{
		cub->ray->dir.y -= (cub->direction == 'E') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'S') * 0.04;
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.x += (cub->direction == 'N') * 0.04;
			cub->ray->dir.y += (cub->direction == 'W') * 0.04;	
		}
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 68)
	{
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'N') * 0.04;
			cub->ray->dir.x += (cub->direction == 'E') * 0.04;
		}
		cub->ray->dir.y -= (cub->direction == 'S') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'W') * 0.04;
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 65)
	{
		
		cub->ray->dir.y -= (cub->direction == 'N') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'E') * 0.04;
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'S') * 0.04;
			cub->ray->dir.x += (cub->direction == 'W') * 0.04;
		}
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	printf("key = %i\n", key.key);
	//printf("Player pos x: %i y: %i\n", cub->player_pos.x, cub->player_pos.y);
	printf("Player pos x: %f y: %f\n", cub->ray->dir.x, cub->ray->dir.y);
}
