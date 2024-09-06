/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:35:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 13:53:07 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	free_sphere(t_sphere *sphere)
{
	if (sphere == NULL)
		return ;
	if (sphere->center != NULL)
		free(sphere->center);
	if (sphere->color != NULL)
		free(sphere->color);
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

static void	free_plane(t_plane *plane)
{
	if (plane == NULL)
		return ;
	if (plane->origine != NULL)
		free(plane->origine);
	if (plane->direction != NULL)
		free(plane->direction);
	if (plane->color != NULL)
		free(plane->color);
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
