/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:28:41 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/06 12:07:54 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	init_ambient(t_ambient *ambient)
{
	ambient->ambient_light = ft_calloc(1, sizeof(t_vector));
	if (ambient->ambient_light == NULL)
		return (error_allocation());
	ambient->ratio = -1;
	return (0);
}

int	init_scene(t_data *data)
{
	data->scene = ft_calloc(1, sizeof(t_scene));
	if (data->scene == NULL)
		return (error_allocation());
	data->scene->light = ft_calloc(1, sizeof(t_light));
	if (data->scene->light == NULL)
		return (error_allocation());
	data->scene->camera = ft_calloc(1, sizeof(t_camera));
	if (data->scene->camera == NULL)
		return (error_allocation());
	data->scene->ambient = ft_calloc(1, sizeof(t_ambient));
	if (data->scene->ambient == NULL)
		return (error_allocation());
	init_ambient(data->scene->ambient);
	data->scene->spheres = NULL;
	data->scene->cylinder = NULL;
	data->scene->plane = NULL;
	return (0);
}
