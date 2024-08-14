/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:13:50 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/14 17:32:24 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
#include "scene.h"

# define M_PI 3.14159265358979323846

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct	s_camera
{
	t_vector *origine;
	t_vector *direction;
	float 		fov;
}				t_camera;

typedef struct	s_view
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_view;

t_vector 	*new_vector(float x, float y, float z);
t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2);
void		vec_normalize(t_vector *vec);
float		vec_lenght(t_vector *vec);
float		vec_dot_product(t_vector *vec1, t_vector *vec2);
t_camera	*new_camera(t_vector *origine, t_vector *direction, float fov);
t_view		*get_view_plane(float width, float height, float fov);
void		ray_tracing(void *mlx, void *window, t_scene *scene);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere);
#endif
