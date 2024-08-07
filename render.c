/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:45:11 by mpelluet          #+#    #+#             */
/*   Updated: 2024/08/07 17:45:11 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init()
{
	t_vect	*origin;

	origin->x = 0;
	origin->y = 0;
	origin->z = 0;
}

t_vect	*canvas_to_viewport(x, y)
{
	t_vect	D;

	D.x = x*Vw/Cw;
	D.y = y*Vh/Ch;
	D.z = 1;
	return (D);
}

void	intersect_ray_sphere(t_vect *origine, t_vect *D, sphere)
{
	t_vect	CO;
	double	a;
	double	b;
	double	c;

	CO.x = origine->x - sphere->center->x;
	CO.y = origine->y - sphere->center->y;
	CO.z = origine->z - sphere->center->z;
	a = 
}

void	trace_ray(t_vect *origine, t_vect *D, double t_min, double t_max)
{
	double	closest_t = t_max;
	closest_sphere = NULL;
	double	t[2];

	while (sphere)
	{
		intersect_ray_sphere(origine, D, sphere);
		if ((t[0] >= t_min && t[0] < t_max) && t[0] < closest_t)
		{
			closest_t = t[0];
			closest_sphere = sphere;
		}
		if ((t[1] >= t_min && t[1] < t_max) && t[1] < closest_t)
		{
			closest_t = t[1];
			closest_sphere = sphere;
		}
	}
	if (closest_sphere == NULL)
		return (BACKGROUND_COLOR);
	return (closest_sphere.color);
}

void	draw()
{
	t_vect	*D;

	while (x) //pour x allant de -Cw/2 à Cw/2
	{
		while (y) //pour y allant de -Ch/2 à Ch/2
		{
			D = canvas_to_viewport(x, y);
			trace_ray(origin, D, t_min, t_max);
		}
		
	}
	
}
