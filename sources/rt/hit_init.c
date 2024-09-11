/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:44:55 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/10 09:35:24 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_tmp_ray(t_scene *tmp, t_object object)
{
	if (tmp->spheres && object == SPHERE)
	{
		tmp->spheres->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->spheres->ray == NULL)
			error_allocation();
		tmp->spheres->ray_dir = ft_calloc(1, sizeof(t_vector));
		if (tmp->spheres->ray_dir == NULL)
			error_allocation();
		return ;
	}
	else if (tmp->plane && object == PLANE)
	{
		tmp->plane->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->plane->ray == NULL)
			error_allocation();
		tmp->plane->ray_dir = ft_calloc(1, sizeof(t_vector));
		if (tmp->plane->ray_dir == NULL)
			error_allocation();
		return ;
	}
	else if (tmp->cylinder && object == CYLINDER)
	{
		tmp->cylinder->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->cylinder->ray == NULL)
			error_allocation();
		tmp->cylinder->ray_dir = ft_calloc(1, sizeof(t_vector));
		if (tmp->cylinder->ray_dir == NULL)
			error_allocation();
		return ;
	}
}

void	free_tmp(t_scene *tmp)
{
	if (tmp->spheres->ray != NULL)
		free(tmp->spheres->ray);
	else if (tmp->plane->ray != NULL)
		free(tmp->plane->ray);
	else if (tmp->cylinder->ray != NULL)
		free(tmp->cylinder->ray);
}

void	reinit_hit(t_hit *hit)
{
	// if (hit->sphere->ray != NULL)
	// 	free(hit->sphere->ray);
	if (hit->sphere->ray_light != NULL)
		free(hit->sphere->ray_light);
	if (hit->sphere->impact_point != NULL)
		free(hit->sphere->impact_point);
}
