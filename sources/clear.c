/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 14:23:15 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

static void	free_view(t_view *view)
{
	if (view->viewplane_x != NULL)
		free(view->viewplane_x);
	if (view->viewplane_y != NULL)
		free(view->viewplane_y);
}

int	clean_data(t_data *data, int code_error)
{
	if (data->white_light != NULL)
		free(data->white_light);
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
		free(data->hit);
	return (code_error);
}
