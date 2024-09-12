/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/12 17:11:11 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	free_light(t_light *light)
{
	if (light == NULL)
		return ;
	free(light);
}

static void	free_camera(t_camera *camera)
{
	free(camera);
}

static void	free_ambient(t_ambient *ambient)
{
	free(ambient);
}

int	free_scene(t_scene *scene)
{
	if (scene->objects)
		free_geometry_list(scene->objects);
	if (scene->light != NULL)
		free_light(scene->light);
	if (scene->camera != NULL)
		free_camera(scene->camera);
	if (scene->ambient != NULL)
		free_ambient(scene->ambient);
	return (0);
}
