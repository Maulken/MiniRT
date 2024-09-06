/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:47:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 13:19:11 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	error_allocation(void)
{
	printf("Memory allocation failed \n");
	exit(1);
}

static int	init_struct_view(t_data *data)
{
	data->view = ft_calloc(1, sizeof(t_view));
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

int	init_struct(t_data *data)
{
	init_struct_view(data);
	data->hit = ft_calloc(1, sizeof(t_hit));
	if (!data->hit)
		return (error_allocation());
	data->hit->sphere = NULL;
	data->hit->plane = NULL;
	data->hit->cylinder = NULL;
	data->white_light = ft_calloc(1, sizeof(t_vector));
	if (!data->white_light)
		return (error_allocation());
	return (0);
}

int	init_data(t_data *data)
{
	data->white_light->x = 255;
	data->white_light->y = 255;
	data->white_light->z = 255;
	data->view->height = 600;
	data->view->width = 800;
	data->view->distance = 0;
	data->hit->distance = INFINITY;
	return (0);
}
