/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:30:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 22:38:32 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct s_sphere		t_sphere;
typedef struct s_vector		t_vector;
typedef struct s_camera		t_camera;
typedef struct s_view		t_view;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_ambient	t_ambient;

typedef struct s_sphere
{
	t_sphere	*next;
	t_vector	*center;
	t_vector	*color;
	t_vector	*impact_point;
	t_vector	*ray;
	t_vector	*ray_light;
	float		diameter;
	float		dist_light_sphere;
	float		dist_cam_sphere;
}				t_sphere;

typedef struct s_plane
{
	t_plane		*next;
	t_vector	*origine;
	t_vector	*direction;
	t_vector	*color;
	t_vector	*impact_point;
	t_vector	*ray;
	t_vector	*ray_light;
}				t_plane;

typedef struct s_cylinder
{
	t_cylinder	*next;
	t_vector	*center;
	t_vector	*direction;
	t_vector	*impact_point;
	t_vector	*ray;
	t_vector	*ray_light;
	t_vector	*color;
	float		diameter;
	float		height;
}				t_cylinder;

typedef struct s_light
{
	t_vector	*origine;
	float		ratio;
}				t_light;

typedef struct s_ambient
{
	float		ratio;
	t_vector	*colors;
}				t_ambient;

typedef struct s_scene
{
	t_light		*light;
	t_camera	*camera;
	t_sphere	*spheres;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_ambient	*ambient;
	float		width;
	float		height;
}				t_scene;

#endif
