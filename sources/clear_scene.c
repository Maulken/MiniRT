/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 14:43:22 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int clear_scene(t_data *data)
{
	if (data->scene->plane != NULL)
		free_plane_list(data->scene->plane);
	if (data->scene->cylinder != NULL)
		free_cylinder_list(data->scene->cylinder);
	if (data->scene->spheres != NULL)
		free_sphere_list(data->scene->spheres);
	if (data->scene->light != NULL)
		free_light(data->scene->light);
	if (data->scene->camera != NULL)
		free_camera(data->scene->camera);
	if (data->scene->ambient != NULL)
		free_ambient(data->scene->ambient);
	return(0);
}