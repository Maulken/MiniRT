/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:47:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/09 18:07:19 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_hit_sphere(t_hit *hit)
{
	// hit->sphere->ray = ft_calloc(1, sizeof(t_vector));
	// if (hit->sphere->ray == NULL)
	// 	error_allocation();
	hit->sphere->ray_light = ft_calloc(1, sizeof(t_vector));
	if (hit->sphere->ray_light == NULL)
		error_allocation();
	hit->sphere->impact_point = ft_calloc(1, sizeof(t_vector));
	if (hit->sphere->impact_point == NULL)
		error_allocation();
	hit->sphere->dist_cam_sphere = 0;
	hit->sphere->dist_light_sphere = 0;
}

void	init_hit_plane(t_hit *hit)
{
	// hit->plane->ray = ft_calloc(1, sizeof(t_vector));
	// if (hit->plane->ray == NULL)
	// 	error_allocation();
	hit->plane->ray_light = ft_calloc(1, sizeof(t_vector));
	if (hit->plane->ray_light == NULL)
		error_allocation();
	hit->plane->impact_point = ft_calloc(1, sizeof(t_vector));
	if (hit->plane->impact_point == NULL)
		error_allocation();
	hit->plane->dist_cam_plane = 0;
	hit->plane->dist_light_plane = 0;
}

void	init_hit_cylinder(t_hit *hit)
{
	hit->cylinder->ray = ft_calloc(1, sizeof(t_vector));
	if (hit->cylinder->ray == NULL)
		error_allocation();
	hit->cylinder->ray_light = ft_calloc(1, sizeof(t_vector));
	if (hit->cylinder->ray_light == NULL)
		error_allocation();
	hit->cylinder->impact_point = ft_calloc(1, sizeof(t_vector));
	if (hit->cylinder->impact_point == NULL)
		error_allocation();
	hit->cylinder->dist_cam_cylinder = 0;
	hit->cylinder->dist_light_cylinder = 0;
}
