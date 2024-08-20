/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:47:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 11:21:58 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


int	init_struct(t_data *data)
{
	t_scene *scene;

	data->view = ft_calloc(1, sizeof(t_view));
	if (!data->view)
		return (0);
	data->scene = NULL;
	data->white_light = ft_calloc(1, sizeof(t_vector));
	if (!data->white_light)
		return (0);
	data->white_light->x = 255;
	data->white_light->y = 255;
	data->white_light->z = 255;
	data->view->height = 600;
	data->view->x_pixel = 0;
	data->view->y_pixel = 0;
	data->view->width = 800;
	data->x_ray = 0;
	data->y_ray = 0;
	return(0);
}

void init_data(t_data *data)
{

      data->scene = (t_scene *)malloc(sizeof(t_scene));
    if (data->scene == NULL) 
    {
        printf("Memory allocation failed \n");
        exit(1);
    }
	data->scene->light = NULL;
	 data->scene->light = malloc(sizeof(t_light));
    if(data->scene->light == NULL)
    {
        printf("Memory allocation failed \n");
        exit(1);
    }
    data->scene->camera = malloc(sizeof(t_camera));
    if(data->scene->camera == NULL)
    {
        free(data->scene->light);
        free(data->scene);
        printf("Memory allocation failed \n");
        exit(1);
    }
    data->scene->spheres = ft_calloc(1, sizeof(t_sphere));
    if(data->scene->spheres == NULL)
    {   
        free(data->scene->camera);
        free(data->scene->light);
        free(data->scene);
        printf("Memory allocation failed\n");
        exit(1);
    }
    data->scene->spheres->next = NULL;
  
      data->scene->cylinder = ft_calloc(1, sizeof(t_cylinder));
    if(data->scene->cylinder == NULL)
    {
        free(data->scene->spheres);
        free(data->scene->camera);
        free(data->scene->light);
        free(data->scene);
        printf("Memory allocation failed \n");
        exit(1);
    }
     data->scene->cylinder->next = NULL;

      data->scene->plane = ft_calloc(1, sizeof(t_plane));
    if(data->scene->plane == NULL)
    {
        free(data->scene->cylinder);
        free(data->scene->spheres);
        free(data->scene->camera);
        free(data->scene->light);
        free(data->scene);
        printf("Memory allocation failed \n");
        exit(1);
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
		printf("Memory allocation failed \n");
		exit(1);
	}

	data->scene->ambient->colors = new_vector(255, 255, 255);
	data->scene->ambient->ratio = 0.2;
}
