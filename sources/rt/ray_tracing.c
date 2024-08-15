/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/15 20:12:40 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// a corriger avec mxl put image to window
void	ray_tracing(void *mlx, void *window, t_data *data)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			trgb;
	float		x_ray;
	float		y_ray;
	t_vector	*ray;
	// t_view		*view;

	// view = get_view_plane(scene->width, scene->height, scene->camera->fov);
	get_view_plane(data);
	
	mlx_y = 0;
	// y_angle = (scene->height / 2);
	y_angle = (data->view->height / 2);
	// while(y_angle >= (scene->height / 2) * (-1))
	while(y_angle >= (data->view->height / 2) * (-1))
	{
		y_ray = y_angle * data->view->y_pixel;
		// x_angle = (scene->width / 2) * (-1);
		x_angle = (data->view->width / 2) * (-1);
		mlx_x = 0;
		// while(x_angle <= scene->width / 2)
		while(x_angle <= data->view->width / 2)
		{
			x_ray = x_angle * data->view->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(ray);
			if(sphere_intersect(data->scene->camera, ray, data->scene->spheres))
				trgb = create_trgb(250, data->scene->spheres->color);
			else
				trgb = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, trgb);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

void	get_view_plane(t_data *data)
{
	float	aspect_ratio;
	float	width;
	float	height;

	// aspect_ratio = width / height;
	// view->width = 2 * tan(fov / 2 * (M_PI / 180));
	// view->height = view->width / aspect_ratio;
	// view->x_pixel = view->width / width;
	// view->y_pixel = view->height / height;
	aspect_ratio = data->view->width / data->view->height;
	// printf("fov : %f\n", data->scene->camera->fov);
	width = 2 * tan(data->scene->camera->fov / 2 * (M_PI / 180));
	height = width / aspect_ratio;
	data->view->x_pixel = width / data->view->width;
	data->view->y_pixel = height / data->view->height;
}

int	sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist1;
	float	dist2;
	t_vector	*cam_sphere;
	
	dist1 = 0;
	dist2 = 0;
	cam_sphere = vec_subtract(camera->origine, sphere->center);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	c = vec_dot_product(cam_sphere, cam_sphere) -
		((sphere->diameter / 2) * (sphere->diameter / 2));
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist1 > 0)
		return (1);
	return (0);
}

// float	get_angle(t_vector *vec1, t_vector *vec2) // pour la diffration de la lumiere
// {
// 	float	angle;

// 	// valeur vect temp
// 	// angle en absolu
// 	// norme point d insection
// 	// arcos(nor * dot prod)

// }

// trouver theta:

// 	scalaire de light normale
// 	longueur Light
// 	longueur norm
// 	diviser scalaire par l light *l Norm
// 	arc cos
// acos()
