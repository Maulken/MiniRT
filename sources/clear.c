/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 16:40:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	clean_data(data, 0);
	return (0);
}

void	free_light(t_light *light)
{
	if (light == NULL)
		return ;
	if (light->origine != NULL)
		free(light->origine);
	free(light);
}

void	free_camera(t_camera *camera)
{
	if(camera->origine != NULL)
		free(camera->origine);
	if (camera->direction != NULL)
		free(camera->direction);
	free(camera);
}

void	free_ambient(t_ambient *ambient)
{
	free(ambient->colors);
	free(ambient->ambient_light);
	free(ambient);
}

void	free_inside_hit(t_hit *hit)
{
	if (hit->sphere != NULL)
		free_sphere(hit->sphere);
	if (hit->plane != NULL)
		free_plane(hit->plane);
	if (hit->cylinder != NULL)
		free_cylinder(hit->cylinder);
}

void	free_hit(t_hit *hit)
{
	if (hit->sphere != NULL)
		free(hit->sphere);
	if (hit->plane != NULL)
		free(hit->plane);
	if(hit->cylinder != NULL)
		free(hit->cylinder);
	free(hit);
}

int	clean_data(t_data *data, int code_error)
{
	if (data->view != NULL)
	{
        free(data->view);
		data->view = NULL;
	}
    if (data->hit != NULL)
	{
		free(data->hit);
		data->hit = NULL;
	}
    if (data->white_light != NULL)
	{
        free(data->white_light);
		data->white_light = NULL;
	}
	if (data->scene != NULL)
	{
		clear_scene(data);
		free(data->scene);	
	}
	data->scene = NULL;
	return (code_error);
}