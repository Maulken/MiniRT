/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/20 18:38:52 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	float	aspect_ratio;
	float	width;
	float	height;

	aspect_ratio = data->view->width / data->view->height;
	width = 2 * tan(data->scene->camera->fov / 2 * (M_PI / 180));
	height = width / aspect_ratio;
	data->view->x_pixel = width / data->view->width;
	data->view->y_pixel = height / data->view->height;
}

void	obtain_ray(t_data *data, float x_ray, float y_ray)
{
	t_vector	*for_ray;
	for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
	data->scene->spheres->ray = vec_subtract(for_ray,
			data->scene->camera->origine);
	vec_normalize(data->scene->spheres->ray);
	free(for_ray);
}

int	get_color(t_data *data, t_object object)
{
	int	color;

	color = 0;
	if (object == SPHERE)
		color = get_color_sphere(data);
	return (color);
}

void	ray_tracing(void *mlx, void *window, t_data *data)
{
	float		x_scale;
	float		y_scale;
	float		x_ray;
	float		y_ray;

	get_view_plane(data);
	data->mlx_y = 0;
	y_scale = (data->view->height / 2);
	while (y_scale >= (data->view->height / 2) * (-1))
	{
		y_ray = y_scale * data->view->y_pixel;
		x_scale = (data->view->width / 2) * (-1);
		data->mlx_x = 0;
		while (x_scale <= data->view->width / 2)
		{
			x_ray = x_scale * data->view->x_pixel;
			obtain_ray(data, -x_ray, -y_ray);
			my_mlx_pixel_put(data, get_color(data, SPHERE));
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
}
