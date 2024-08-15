
#ifndef SCENE_H
#define	SCENE_H

#include "minirt.h"

typedef struct	s_vector t_vector;
typedef struct	s_camera t_camera;
typedef struct	s_view t_view;

typedef struct	s_sphere
{
	t_vector	*center;
	float		diameter;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	*origine;
	t_vector	*direction;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	*center;
	t_vector	*direction;
	float		diameter;
	float		height;
}				t_cylinder;

typedef struct	s_scene
{
	t_camera	*camera;
	t_sphere	*sphere;
	// t_plane		*plane;
	// t_cylinder	*cylinder;
	float		width;
	float		height;
}				t_scene;

//t_sphere 	*new_sphere(t_vector *center, float radius);
//t_scene	    *new_scene(t_camera *cam, t_sphere *sphere);
// t_plane		*new_plane(t_vector *origine, t_vector *direction, float fov);
// t_cylinder	*new_cylinder(t_vector *center, t_vector *direction, float diameter, float height);

#endif