/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:35:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 16:23:55 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
