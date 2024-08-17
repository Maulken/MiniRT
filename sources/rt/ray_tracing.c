/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/17 21:17:23 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ray_tracing(void *mlx, void *window, t_data *data)
{
	int			mlx_x;
	int			mlx_y;
	float		x_scale;
	float		y_scale;
	int			trgb;
	float		x_ray;
	float		y_ray;
	// t_vector	*impact_point;
	// t_vector	*ray;
	// t_vector	*ray_light;

	get_view_plane(data);
	mlx_y = 0;
	y_scale = (data->view->height / 2);
	while(y_scale >= (data->view->height / 2) * (-1))
	{
		y_ray = y_scale * data->view->y_pixel;
		x_scale = (data->view->width / 2) * (-1);
		mlx_x = 0;
		while(x_scale <= data->view->width / 2)
		{
			x_ray = x_scale * data->view->x_pixel;
			// ray = new_vector(x_ray, y_ray, -1);
			data->scene->spheres->impact_point = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
			data->scene->spheres->ray = vec_subtract(data->scene->spheres->impact_point, data->scene->camera->origine);
			data->scene->spheres->ray_light = vec_subtract(data->scene->spheres->ray, data->scene->light->origine);
			vec_normalize(data->scene->spheres->ray);
			vec_normalize(data->scene->spheres->ray_light);
			if(sphere_intersect(data) > 0)
			{
				if (is_light_intersect(data))
				{
					// get_color_coef(data, ); //a continuer
				}
				else
				{}
				// trgb = create_trgb(250, data->scene->spheres->color);
				trgb = create_rgb(data->scene->spheres->color);
				// printf("trgb %d\n", trgb);
			}
			else
				trgb = 0;
			my_mlx_pixel_put(data, mlx_x, mlx_y, trgb);
			// free(impact_point);
			// free(ray);
			// free(ray_light);
			x_scale++;
			mlx_x++;
		}
		y_scale--;
		mlx_y++;
	}
}

bool	is_light_intersect(t_data *data)
{
	t_vector	*light_point;
	float		dist_light_sphere;
	
	dist_light_sphere = sphere_intersect(data);
	if (dist_light_sphere > 0);
	{
		light_point = vec_add(data->scene->light->origine, vec_multiplying(data->scene->spheres->ray_light, dist_light_sphere));
		if (vec_compare(light_point,data->scene->spheres->impact_point))
			return (true);
	}
	return (false);
}

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

float	sphere_intersect(t_data *data)
{
	float	b;
	float	c;
	float	discr;
	float	dist1;
	float	dist2;
	t_vector	*origine_sphere;

	dist1 = 0;
	dist2 = 0;
	origine_sphere = vec_subtract(data->scene->camera->origine, data->scene->spheres->center);
	b = 2 * (vec_dot_product(origine_sphere, data->scene->spheres->ray));
	c = vec_dot_product(origine_sphere, origine_sphere) -
		((data->scene->spheres->diameter / 2) * (data->scene->spheres->diameter / 2));
	discr = (b * b) - (4 * c);
	free(origine_sphere);
	if (discr < 0)
		return (0);
	dist1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist2 = ((b * (-1)) + sqrt(discr)) / 2;
	// if (dist1 > 0)
	// 	return (1);
	if (dist1 > 0)
		return (dist1);
	return (0);
}

float	get_color_coef(t_data *data, float dist_light_sphere) // pour la diffration de la lumiere
{
	float	color_coef;
	float	dist_cam_sphere;
	t_scene	*scene;
	
	scene = data->scene;
	dist_cam_sphere = vec_lenght(scene->spheres->impact_point, scene->camera->origine);
	color_coef = vec_dot_product(scene->spheres->ray_light, scene->spheres->ray) / (dist_light_sphere * dist_cam_sphere);
	return (color_coef);
}
	// lenght_normal = data->scene->spheres->diameter / 2;
	// lenght_light = sphere_intersect(data->scene->light->origine, ray, data->scene->spheres);
//!\ sphere intersect = a readapter

	// valeur vect temp
	// angle en absolu
	// norme point d insection
	// arcos(nor * dot prod)

// }

// trouver theta:

// 	scalaire de light normale
// 	longueur Light
// 	longueur norm
// 	diviser scalaire par l light *l Norm
// 	arc cos
// acos()

// probleme avec la fonction cree couleur trgb