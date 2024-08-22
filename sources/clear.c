/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 10:40:49 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	clean(data, 0);
	return (0);
}

void	free_sphere(t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	if (sphere->center != NULL)
		free(sphere->center);
	if (sphere->color != NULL)
		free(sphere->color);
	if (sphere->impact_point != NULL)
		free(sphere->impact_point);
	if (sphere->ray != NULL)
		free(sphere->ray);
	if (sphere->ray_light != NULL)
		free(sphere->ray_light);
	free(sphere);
}

void	free_inside_sphere(t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	if (sphere->center != NULL)
		free(sphere->center);
	if (sphere->color != NULL)
		free(sphere->color);
	if (sphere->impact_point != NULL)
		free(sphere->impact_point);
	if (sphere->ray != NULL)
		free(sphere->ray);
	if (sphere->ray_light != NULL)
		free(sphere->ray_light);
}

void	free_sphere_list(t_sphere *head)
{
	t_sphere	*current;
	t_sphere	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_sphere(current);
		current = next;
	}
}

void	free_plane(t_plane *plane)
{
	if (plane == NULL)
		return ;
	if (plane->origine != NULL)
		free(plane->origine);
	if (plane->direction != NULL)
		free(plane->direction);
	if (plane->color != NULL)
		free(plane->color);
	if (plane->impact_point != NULL)
		free(plane->impact_point);
	if (plane->ray != NULL)
		free(plane->ray);
	if (plane->ray_light != NULL)
		free(plane->ray_light);
	free(plane);
}

void	free_plane_list(t_plane *head)
{
	t_plane	*current;
	t_plane	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_plane(current);
		current = next;
	}
}

void	free_cylinder(t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return ;
	if (cylinder->center != NULL)
		free(cylinder->center);
	if (cylinder->color != NULL)
		free(cylinder->color);
	if (cylinder->direction != NULL)
		free(cylinder->direction);
	if (cylinder->impact_point != NULL)
		free(cylinder->impact_point);
	if (cylinder->ray != NULL)
		free(cylinder->ray);
	if (cylinder->ray_light != NULL)
		free(cylinder->ray_light);
	free(cylinder);
}

void	free_cylinder_list(t_cylinder *head)
{
	t_cylinder	*current;
	t_cylinder	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_cylinder(current);
		current = next;
	}
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
	// free(hit);
}

int	clean(t_data *data, int code_error)
{
	if (data->view)
	{
        free(data->view);
		data->view = NULL;
	}
    if (data->hit)
	{
        free(data->hit);
		data->hit = NULL;
	}
    if (data->white_light)
	{
        free(data->white_light);
		data->white_light = NULL;
	}
	if (data->scene != NULL)
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
	}
	if (data->view != NULL)
	{
		free(data->view);
		data->view = NULL;
	}
	if (data->hit != NULL)
	{
		free_inside_hit(data->hit);
		free(data->hit);
	}
	free(data->scene);
	data->scene = NULL;
	return (code_error);
}
