/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:17:53 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:38:15 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	set_ray(int x, t_ray *ray, t_cub *cub)
{
	ray->camera = (double)((2 * x) / (double)cub->s_width - 1);
	ray->ray_dir.x = ray->dir.x + (ray->plane.x * ray->camera);
	ray->ray_dir.y = ray->dir.y + (ray->plane.y * ray->camera);
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->map.x = ray->pos.x;
	ray->map.y = ray->pos.y;
}

void	calculate_ray_distance(t_ray *ray)
{
	ray->hit = 0;
	ray->step.x = 1;
	ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	ray->step.y = 1;
	ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
}

/*
 * TODO 25lines FIX
 * wall_distance = perpWallDist;
 */
void	dda(t_cub *cub, t_ray *ray)
{
	int	is_x_side;
	int	is_negative;

	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			is_x_side = 1;
			is_negative = ray->ray_dir.x < 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			is_x_side = 0;
			is_negative = ray->ray_dir.y < 0;
		}
		if (cub->d->map[ray->map.x][ray->map.y] > '0')
			ray->hit = 1;
	}
	if (is_x_side)
	{
		if (is_negative)
			ray->side = NO;
		else
			ray->side = SO;
	}
	else
	{
		if (is_negative)
			ray->side = EA;
		else
			ray->side = WE;
	}
	if (is_x_side)
		ray->wall_distance = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->wall_distance = (ray->side_dist.y - ray->delta_dist.y);
}

void	render_ray(void	*param)
{
	t_cub	*cub;
	int		i;

	i = 0;
	cub = (t_cub *)param;
	while (i < cub->s_width)
	{
		set_ray(i, cub->ray, cub);
		calculate_ray_distance(cub->ray);
		dda(cub, cub->ray);
		draw_ray(i, cub, cub->ray);
		i++;
	}	
}
