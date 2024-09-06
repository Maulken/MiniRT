/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 13:54:09 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	free_light(t_light *light)
{
	if (light == NULL)
		return ;
	if (light->origine != NULL)
		free(light->origine);
	free(light);
}

static void	free_camera(t_camera *camera)
{
	if (camera->origine != NULL)
		free(camera->origine);
	if (camera->direction != NULL)
		free(camera->direction);
	free(camera);
}

static void	free_ambient(t_ambient *ambient)
{
	if (ambient->colors != NULL)
		free(ambient->colors);
	if (ambient->ambient_light != NULL)
		free(ambient->ambient_light);
	free(ambient);
}

int	free_scene(t_scene *scene)
{
	if (scene->plane != NULL)
		free_plane_list(scene->plane);
	if (scene->cylinder != NULL)
		free_cylinder_list(scene->cylinder);
	if (scene->spheres != NULL)
		free_sphere_list(scene->spheres);
	if (scene->light != NULL)
		free_light(scene->light);
	if (scene->camera != NULL)
		free_camera(scene->camera);
	if (scene->ambient != NULL)
		free_ambient(scene->ambient);
	return (0);
}
