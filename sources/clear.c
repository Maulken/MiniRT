/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 10:53:11 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	// clean(data, 0);
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
	// if (sphere->impact_point != NULL)
	// 	free(sphere->impact_point);
	// if (sphere->ray != NULL)
	// 	free(sphere->ray);
	// if (sphere->ray_light != NULL)
	// 	free(sphere->ray_light);
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
	// if (sphere->impact_point != NULL)
	// 	free(sphere->impact_point);
	// if (sphere->ray != NULL)
	// 	free(sphere->ray);
	// if (sphere->ray_light != NULL)
	// 	free(sphere->ray_light);
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
	// if (plane->impact_point != NULL)
	// 	free(plane->impact_point);
	// if (plane->ray != NULL)
	// 	free(plane->ray);
	// if (plane->ray_light != NULL)
	// 	free(plane->ray_light);
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
	// if (cylinder->impact_point != NULL)
	// 	free(cylinder->impact_point);
	// if (cylinder->ray != NULL)
	// 	free(cylinder->ray);
	// if (cylinder->ray_light != NULL)
	// 	free(cylinder->ray_light);
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
	if (ambient->colors != NULL)
		free(ambient->colors);
	if (ambient->ambient_light != NULL)
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

void	free_view(t_view *view)
{
	free(view->viewplane_x);
	free(view->viewplane_y);
}

void	free_scene(t_scene *scene)
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
}

int	clean(t_data *data, int code_error)
{
	if (data->white_light)
	{
		free(data->white_light);
		data->white_light = NULL;
	}
	if (data->scene != NULL)
	{
		free_scene(data->scene);
		free(data->scene);
	}
	if (data->view != NULL)
	{
		free_view(data->view);
		free(data->view);
	}
	if (data->hit != NULL)
	{
		// free_inside_hit(data->hit);
		free(data->hit);
	}
	return (code_error);
}
