/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:47:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/05 14:33:06 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int error_allocation(void)
{
	printf("Memory allocation failed \n");
	exit(1);
}

int	error_msg(int	nb)
{
	printf("%d\n", nb);
	exit(1);
}

// int	init_struct(t_data *data)
// {
// 	data->view = malloc(sizeof(t_view));
// 	if (!data->view)
// 		return (error_msg(1));
// 	data->view->viewplane_x = malloc(sizeof(t_vector));
// 	if (!data->view->viewplane_x)
// 		return (error_msg(2));
// 	data->view->viewplane_x = NULL;
// 	data->view->viewplane_y = malloc(sizeof(t_vector));
// 	if (!data->view->viewplane_y)
// 		return (error_msg(3));
// 	data->view->viewplane_y = NULL;
// 	// data->scene = NULL;
// 	data->hit = malloc(sizeof(t_hit));
// 	if (!data->hit)
// 		return (error_msg(4));
// 	data->hit->sphere = malloc(sizeof(t_sphere));
// 	if (!data->hit->sphere)
// 		return (error_msg(5));
// 	data->hit->plane = malloc(sizeof(t_plane));
// 	if (!data->hit->plane)
// 		return (error_msg(6));
// 	data->hit->cylinder = malloc(sizeof(t_cylinder));
// 	if (!data->hit->cylinder)
// 		return (error_msg(77));
// 	data->white_light = malloc(sizeof(t_vector));
// 	if (!data->white_light)
// 		return (error_msg(8));
// 	return(0);
// }

int	init_struct_view(t_data *data)
{
	data->view = ft_calloc(1,sizeof(t_view));
	if (!data->view)
		return (error_allocation());
	data->view->viewplane_x = ft_calloc(1, sizeof(t_vector));
	if (!data->view->viewplane_x)
		return (error_allocation());
	data->view->viewplane_y = ft_calloc(1, sizeof(t_vector));
	if (!data->view->viewplane_y)
		return (error_allocation());
	return (0);
}

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
	cylinder->ray_light = ft_calloc(1, sizeof(t_vector));
	if (cylinder->ray_light == NULL)
		return (error_allocation());
	cylinder->next = NULL;
	return (0);
}

int	init_struct_hit(t_data *data)
{
	// data->hit->sphere = ft_calloc(1, sizeof(t_sphere));
	// if (!data->hit->sphere)
	// 	return (error_allocation());
	// init_struct_sphere(data->hit->sphere);
	// data->hit->plane = ft_calloc(1, sizeof(t_plane));
	// if (!data->hit->plane)
	// 	return (error_allocation());
	// init_struct_plane(data->hit->plane);
	// data->hit->cylinder = ft_calloc(1, sizeof(t_cylinder));
	// if (!data->hit->cylinder)
	// 	return (error_allocation());
	// init_struct_cy(data->hit->cylinder);
	data->hit->sphere = NULL;
	data->hit->plane = NULL;
	data->hit->cylinder = NULL;
	return (0);
}

int	init_struct(t_data *data)
{
	init_struct_view(data);
	data->hit = ft_calloc(1, sizeof(t_hit));
	if (!data->hit)
		return (error_allocation());
	// init_struct_hit(data);
	data->white_light = ft_calloc(1, sizeof(t_vector));
	if (!data->white_light)
		return (error_allocation());
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
	// data->view->viewplane_x = NULL;
	// data->view->viewplane_y = NULL;
	data->view->distance = 0;
	data->hit->distance = INFINITY;
	// data->hit->cylinder = NULL;
	// data->hit->sphere = NULL;
	// data->hit->plane = NULL;
	return(0);
}

int	init_light(t_light *light)
{
	light->origine = ft_calloc(1, sizeof(t_vector));
	if (light->origine == NULL)
		return (error_allocation());
	return (0);
}

int	init_camera(t_camera *camera)
{
	camera->origine = ft_calloc(1, sizeof(t_vector));
	if (camera->origine == NULL)
		return (error_allocation());
	camera->direction = ft_calloc(1, sizeof(t_vector));
	if (camera->direction == NULL)
		return (error_allocation());
	return (0);
}

int	init_ambient(t_ambient *ambient)
{
	ambient->colors = ft_calloc(1, sizeof(t_vector));
	if (ambient->colors == NULL)
		return (error_allocation());
	ambient->ambient_light = ft_calloc(1, sizeof(t_vector));
	if (ambient->ambient_light == NULL)
		return (error_allocation());
	ambient->ratio = -1;
	return (0);
}

void init_scene(t_data *data)
{
	data->scene = ft_calloc(1, sizeof(t_scene));
	if (data->scene == NULL)
	{
		error_allocation();
		return ;
	}
	data->scene->light = ft_calloc(1, sizeof(t_light));
	if (data->scene->light == NULL)
	{
		error_allocation();
		return ;
	}
	init_light(data->scene->light);
	data->scene->camera = ft_calloc(1, sizeof(t_camera));
	if (data->scene->camera == NULL)
	{
		error_allocation();
		return ;
	}
	init_camera(data->scene->camera);
	if(data->scene->camera == NULL)
	{
		free_scene(data->scene);
		// error_allocation();
	}
	data->scene->ambient = ft_calloc(1, sizeof(t_ambient));
	if(data->scene->ambient == NULL)
	{
		error_allocation();
		return ;
	}
	init_ambient(data->scene->ambient);
	// data->scene->spheres = ft_calloc(1, sizeof(t_sphere));
	// if(data->scene->spheres == NULL)
	// 	free_scene(data);
	// init_struct_sphere(data->scene->spheres);
	// data->scene->plane = ft_calloc(1, sizeof(t_plane));
	// if(data->scene->plane == NULL)
	// 	free_scene(data);
	// init_struct_plane(data->scene->plane);
	// data->scene->cylinder = ft_calloc(1, sizeof(t_cylinder));
	// if(data->scene->cylinder == NULL)
	// 	free_scene(data);
	// init_struct_cy(data->scene->cylinder);
	data->scene->spheres = NULL;
	data->scene->cylinder = NULL;
	data->scene->plane = NULL;
}
