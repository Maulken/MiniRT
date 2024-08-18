/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 15:45:00 by mpelluet         ###   ########.fr       */
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
	// data->scene->spheres->impact_point = new_vector(x_ray, y_ray,
	// 		data->scene->camera->direction->z);
	// data->scene->spheres->ray = vec_subtract(data->scene->spheres->impact_point,
	// 		data->scene->camera->origine);
	for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
	data->scene->spheres->ray = vec_subtract(for_ray,
			data->scene->camera->origine);
	data->scene->spheres->ray_light = vec_subtract(data->scene->spheres->ray,
			data->scene->light->origine);
	vec_normalize(data->scene->spheres->ray);
	vec_normalize(data->scene->spheres->ray_light);
}

float	sphere_intersect(t_data *data, int situation)
{
	float	b;
	float	c;
	float	discr;
	float	dist1;
	float	dist2;
	t_vector	*origine_sphere;

	dist1 = 0;
	dist2 = 0;
	if (situation == 1)
	{
		origine_sphere = vec_subtract(data->scene->camera->origine,
				data->scene->spheres->center);
		b = 2 * (vec_dot_product(origine_sphere, data->scene->spheres->ray));
	}
	else
	{
		origine_sphere = vec_subtract(data->scene->light->origine,
				data->scene->spheres->center);
		b = 2 * (vec_dot_product(origine_sphere, data->scene->spheres->ray_light));
	}
	c = vec_dot_product(origine_sphere, origine_sphere)
		- ((data->scene->spheres->diameter / 2)
			* (data->scene->spheres->diameter / 2));
	discr = (b * b) - (4 * c);
	free(origine_sphere);
	if (discr < 0)
		return (0);
	dist1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist1 > 0)
		return (dist1);
	return (0);
}

bool	is_light_intersect(t_data *data)
{
	t_vector	*light_point;
	
	data->scene->spheres->dist_light_sphere = sphere_intersect(data, 2);
	printf("dist ligth sp %f\n", data->scene->spheres->dist_light_sphere);
	if (data->scene->spheres->dist_light_sphere > 0)
	{
		printf("la\n");
		light_point = vec_add(data->scene->light->origine,
				vec_multiplying(data->scene->spheres->ray_light,
					data->scene->spheres->dist_light_sphere));
		printf("changement de printf\n");
		// printf("light %f %f %f\nimpact %f %f %f\n", light_point->x, light_point->y, light_point->z, data->scene->spheres->impact_point->x, data->scene->spheres->impact_point->y, data->scene->spheres->impact_point->z);
		data->scene->spheres->impact_point = vec_add(data->scene->camera->origine,
				vec_multiplying(data->scene->spheres->ray,
					data->scene->spheres->dist_cam_sphere));
		if (vec_compare(light_point, data->scene->spheres->impact_point))
		{
			printf("comapre\n");
			return (true);
		}
	}
	return (false);
}

float	get_light_coef(t_data *data) // pour la diffration de la lumiere
{
	float	light_coef;
	t_scene	*scene;
	t_vector	*sphere_normale;

	scene = data->scene;
	light_coef = vec_dot_product(scene->spheres->ray_light, sphere_normale)
			/ (data->scene->spheres->dist_light_sphere * (scene->spheres->diameter / 2));
	return (light_coef);
}

int	get_color(t_data *data)
{
	float	light_coef;
	// int		color;
	t_color	*color_with_light;

	light_coef = 0;
	data->scene->spheres->dist_cam_sphere = sphere_intersect(data, 1);
	if (data->scene->spheres->dist_cam_sphere > 0)
	{
		if (is_light_intersect(data))
		{
			light_coef = get_light_coef(data);
			printf("light coef %f\n", light_coef);
			color_with_light = addition_color(data->scene->spheres->color,
				multiplying_coef_color(light_coef, data->white_light));
			return (create_rgb(color_with_light));
		}
		else
			return (create_rgb(data->scene->spheres->color));
	}
	return (0);
}

void	ray_tracing(void *mlx, void *window, t_data *data)
{
	float		x_scale;
	float		y_scale;
	// int			trgb;
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
			obtain_ray(data, x_ray, y_ray);
			// trgb = get_color(data);
			// if(sphere_intersect(data) > 0)
			// {
			// 	if (is_light_intersect(data))
			// 	{
			// 		// get_color_coef(data, ); //a continuer
			// 	}
			// 	else
			// 	{}
			// 	// trgb = create_trgb(250, data->scene->spheres->color);
			// 	trgb = create_rgb(data->scene->spheres->color);
			// 	// printf("trgb %d\n", trgb);
			// }
			// else
			// 	trgb = 0;
			my_mlx_pixel_put(data, get_color(data));
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
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