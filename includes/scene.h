/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:30:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/23 15:02:06 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

typedef enum e_geometry_type
{
	GT_SPHERE,
	GT_PLANE,
	GT_CYLINDER
}	t_geometry_type;

typedef struct s_camera
{
	t_vector	origine;
	t_vector	direction;
	float		fov;
}				t_camera;

typedef struct s_sphere
{
	t_vector		center;
	float			diameter;
}				t_sphere;

typedef struct s_plane
{
	t_vector		origine;
	t_vector		direction;
}				t_plane;

typedef struct s_cylinder
{
	t_vector			center;
	t_vector			direction;
	float				diameter;
	float				height;
}				t_cylinder;

typedef struct s_geometry
{
	struct s_geometry	*next;
	t_vector			color;
	t_vector			impact_point;
	int					in_out;
	int					id;
	float				dist_cam;
	t_geometry_type		type;
	struct s_ray
	{
		t_vector			origin;
		t_vector			dir;
		t_vector			light;
	}	ray;
	union u_geometries
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
	}	data;
}	t_geometry;

typedef struct s_light
{
	t_vector	origine;
	float		ratio;
}				t_light;

typedef struct s_ambient
{
	float		ratio;
	t_vector	colors;
	t_vector	ambient_light;
}				t_ambient;

typedef struct s_scene
{
	t_light		*light;
	t_camera	*camera;
	t_ambient	*ambient;
	t_geometry	*objects;
}				t_scene;

#endif
