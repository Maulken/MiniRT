/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:01 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/10 09:34:15 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	init_struct_sphere(t_sphere *sphere)
{
	sphere->center = ft_calloc(1, sizeof(t_vector));
	if (sphere->center == NULL)
		return (error_allocation());
	sphere->color = ft_calloc(1, sizeof(t_vector));
	if (sphere->color == NULL)
		return (error_allocation());
	sphere->impact_point = ft_calloc(1, sizeof(t_vector));
	if (sphere->impact_point == NULL)
		return (error_allocation());
	sphere->ray = ft_calloc(1, sizeof(t_vector));
	if (sphere->ray == NULL)
		return (error_allocation());
	sphere->ray_dir = ft_calloc(1, sizeof(t_vector));
	if (sphere->ray_dir == NULL)
		return (error_allocation());
	sphere->ray_light = ft_calloc(1, sizeof(t_vector));
	if (sphere->ray_light == NULL)
		return (error_allocation());
	sphere->next = NULL;
	sphere->diameter = 0.0;
	sphere->dist_light_sphere = -1;
	sphere->dist_cam_sphere = -1;
	return (0);
}

int	init_struct_plane(t_plane *plane)
{
	plane->origine = ft_calloc(1, sizeof(t_vector));
	if (plane->origine == NULL)
		return (error_allocation());
	plane->direction = ft_calloc(1, sizeof(t_vector));
	if (plane->direction == NULL)
		return (error_allocation());
	plane->color = ft_calloc(1, sizeof(t_vector));
	if (plane->color == NULL)
		return (error_allocation());
	plane->impact_point = ft_calloc(1, sizeof(t_vector));
	if (plane->impact_point == NULL)
		return (error_allocation());
	plane->ray = ft_calloc(1, sizeof(t_vector));
	if (plane->ray == NULL)
		return (error_allocation());
	plane->ray_dir = ft_calloc(1, sizeof(t_vector));
	if (plane->ray_dir == NULL)
		return (error_allocation());
	plane->ray_light = ft_calloc(1, sizeof(t_vector));
	if (plane->ray_light == NULL)
		return (error_allocation());
	plane->next = NULL;
	return (0);
}

int	init_struct_cy(t_cylinder *cylinder)
{
	cylinder->center = ft_calloc(1, sizeof(t_vector));
	if (cylinder->center == NULL)
		return (error_allocation());
	cylinder->direction = ft_calloc(1, sizeof(t_vector));
	if (cylinder->direction == NULL)
		return (error_allocation());
	cylinder->color = ft_calloc(1, sizeof(t_vector));
	if (cylinder->color == NULL)
		return (error_allocation());
	cylinder->impact_point = ft_calloc(1, sizeof(t_vector));
	if (cylinder->impact_point == NULL)
		return (error_allocation());
	cylinder->ray = ft_calloc(1, sizeof(t_vector));
	if (cylinder->ray == NULL)
		return (error_allocation());
	cylinder->ray_dir = ft_calloc(1, sizeof(t_vector));
	if (cylinder->ray_dir == NULL)
		return (error_allocation());
	cylinder->ray_light = ft_calloc(1, sizeof(t_vector));
	if (cylinder->ray_light == NULL)
		return (error_allocation());
	cylinder->next = NULL;
	return (0);
}
