/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:47:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/04 13:42:59 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int error_allocation(void)
{
	printf("Memory allocation failed \n");
	exit(1);
}

int	init_struct(t_data *data)
{
	data->view = ft_calloc(1,sizeof(t_view));
	if (!data->view)
		return (0);
	data->view->viewplane_x = ft_calloc(1, sizeof(t_vector));
	data->view->viewplane_y = ft_calloc(1, sizeof(t_vector));
	data->scene = NULL;
	data->hit = ft_calloc(1, sizeof(t_hit));
	if (!data->hit)
		return (0);
	data->hit->sphere = ft_calloc(1, sizeof(t_sphere));
	data->hit->plane = ft_calloc(1, sizeof(t_plane));
	data->hit->cylinder = ft_calloc(1, sizeof(t_cylinder));
	data->white_light = ft_calloc(1, sizeof(t_vector));
	if (!data->white_light)
		return (0);
	return(0);

}
int init_data(t_data *data)
{
	data->white_light->x = 255;
	data->white_light->y = 255;
	data->white_light->z = 255;
	data->view->height = 600;
	data->view->x_pixel = 0;
	data->view->y_pixel = 0;
	data->view->width = 800;
	data->view->viewplane_x = NULL;
	data->view->viewplane_y = NULL;
	data->view->distance = 0;
	data->hit->distance = INFINITY;
	data->hit->cylinder = NULL;
	data->hit->sphere = NULL;
	data->hit->plane = NULL;
	return(0);
}

void init_scene(t_data *data)
{
	data->scene = NULL;
	data->scene = (t_scene *)ft_calloc(1,sizeof(t_scene));
	if (data->scene == NULL)
		error_allocation();

	data->scene->light = ft_calloc(1,sizeof(t_light));
	if(data->scene->light == NULL)
		error_allocation();
	data->scene->camera = ft_calloc(1,sizeof(t_camera));
	if(data->scene->camera == NULL)
	{
		free(data->scene->light);
		free(data->scene);
		error_allocation();
	}
	data->scene->ambient = ft_calloc(1,sizeof(t_ambient));
	if(data->scene->ambient == NULL)
	{
		free(data->scene->plane);
		free(data->scene->cylinder);
		free(data->scene->spheres);
		free(data->scene->camera);
		free(data->scene->light);
		free(data->scene);
		error_allocation();
	}
	data->scene->spheres = NULL;
	data->scene->cylinder = NULL;
	data->scene->plane = NULL;
}
