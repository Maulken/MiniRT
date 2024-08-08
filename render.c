/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:21:12 by mpelluet          #+#    #+#             */
/*   Updated: 2024/08/08 16:20:15 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	canvas_to_viewport(t_data *data)
{
	data->D->x = (data->x * data->width) / data->Cw;
	data->D->y = (data->y * data->height) / data->Ch;
	data->D->z = 1;
}

void	intersect_ray_sphere(t_data *data)
{
	t_point	*CO;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	CO->x = data->camera->x - data->sphere->sp_point->x;
	CO->y = data->camera->y - data->sphere->sp_point->y;
	CO->z = data->camera->z - data->sphere->sp_point->z;
	a = data->D->x * data->D->x + data->D->y * data->D->y + data->D->z * data->D->z;
	b = 2 * (CO->x * data->D->x + CO->y * data->D->y + CO->z * data->D->z);
	c = CO->x * CO->x + CO->y * CO->y + CO->z * CO->z - (data->sphere->sp_diam * data->sphere->sp_diam);

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		data->t[0] = data->t_max;
		data->t[1] = data->t_max;
		return ;
	}
	data->t[0] = (-b + sqrt(discriminant)) / (2 * a);
	data->t[1] = (-b - sqrt(discriminant)) / (2 * a);	
	return ;
}

t_colors	*trace_ray(t_data *data)
{
	t_colors	*background;
	double	closest_t = data->t_max;
	// t_sphere	closest_sphere = NULL;
	// double	t[2];

	// while (sphere)
	// {
		intersect_ray_sphere(data);
		if ((data->t[0] >= data->t_min && data->t[0] < data->t_max) && data->t[0] < closest_t)
		{
			closest_t = data->t[0];
			// closest_sphere = sphere;
		}
		if ((data->t[1] >= data->t_min && data->t[1] < data->t_max) && data->t[1] < closest_t)
		{
			closest_t = data->t[1];
			// closest_sphere = sphere;
		}
	// }
	// if (closest_sphere == NULL)
	// 	return (BACKGROUND_COLOR);
	if (closest_t == data->t_max)
	{
		background->r = 255;
		background->g = 255;
		background->b = 255;
		return (background);
	}
	// return (closest_sphere.color);
	return (data->sphere->sp_colors);
}

void	draw(t_data *data)
{
	t_colors	*pixel_color;

	data->x = (- 1 * data->Cw) / 2;
	while (data->x < (data->Cw / 2)) //pour x allant de -Cw/2 à Cw/2
	{
		data->y = (- 1 * data->Ch) / 2;
		while (data->y < (data->Ch / 2)) //pour y allant de -Ch/2 à Ch/2
		{
			canvas_to_viewport(data);
			pixel_color = trace_ray(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(void)
{
	t_data	data;

	data.camera->x = 0;
	data.camera->y = 0;
	data.camera->z = 0;
	data.D->x = 0;
	data.D->y = 0;
	data.D->z = 0;
	data.sphere->sp_colors->r = 255;
	data.sphere->sp_colors->b = 0;
	data.sphere->sp_colors->g = 0;
	data.sphere->sp_point->x = 0;
	data.sphere->sp_point->y = -1;
	data.sphere->sp_point->z = 3;
	data.sphere->sp_diam = 1;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width, data.height, "minirt");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endin);
	draw(&data);
}
