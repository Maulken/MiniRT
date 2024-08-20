/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 11:44:09 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	clean(data, 0);
	return (0);
}

void free_sphere(t_sphere *sphere)
{
	if (sphere == NULL)
		return;
	if (sphere->center != NULL)
		free(sphere->center);
	if (sphere->color != NULL)
		free(sphere->color);
	free(sphere);
}

void free_sphere_list(t_sphere *head)
{
	t_sphere *current = head;
	t_sphere *next;

	while (current != NULL)
	{
		next = current->next;
		free_sphere(current);
		current = next;
	}
}

void free_plane(t_plane *plane)
{
	if (plane == NULL)
		return;
	if (plane->origine != NULL)
		free(plane->origine);
	if (plane->direction != NULL)
		free(plane->direction);
	if (plane->color != NULL)
		free(plane->color);
	free(plane);
}

void free_plane_list(t_plane *head)
{
	t_plane *current = head;
	t_plane *next;

	while (current != NULL)
	{
		next = current->next;
		free_plane(current);
		current = next;
	}
}

void free_cylinder(t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return;
	if (cylinder->center != NULL)
		free(cylinder->center);
	if (cylinder->direction != NULL)
		free(cylinder->direction);
	if (cylinder->color != NULL)
		free(cylinder->color);
	free(cylinder);
}

void free_cylinder_list(t_cylinder *head)
{
	t_cylinder *current = head;
	t_cylinder *next;

	while (current != NULL)
	{
		next = current->next;
		free_cylinder(current);
		current = next;
	}
}

void free_light(t_light *light)
{
	if (light == NULL)
		return;
	if (light->origine != NULL)
		free(light->origine);
	//if (light->color != NULL)
		//free(light->color);
	free(light);
}

int clean(t_data *data ,int code_error)
{
	if(data->scene != NULL)
	{
		free_plane_list(data->scene->plane);
		free_cylinder_list(data->scene->cylinder);
		free_sphere_list(data->scene->spheres);
		free_light(data->scene->light);
	
		if (data->scene->camera != NULL)
			free(data->scene->camera);
		if(data->scene->ambient != NULL)
			free(data->scene->ambient);
		free(data->scene);
	}
	   if (data->view != NULL)
        free(data->view);
	return(0);
}