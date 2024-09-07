/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/06 16:26:08 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
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
# include "scene.h"

# define M_PI 3.14159265358979323846
# define OK 0
# define ERROR -1

/* ************************************************************************** */
/* Structures                                                                 */
/* ************************************************************************** */

typedef struct s_hit
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	float		distance;
}				t_hit;

typedef struct s_view
{
	float		width;
	float		height;
	float		distance;
	t_vector	*viewplane_x;
	t_vector	*viewplane_y;
}				t_view;

typedef struct s_data
{
	t_scene		*scene;
	t_view		*view;
	t_hit		*hit;
	t_vector	*white_light;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endin;
	int			mlx_x;
	int			mlx_y;
	int			fd;
	int			count_object;
}			t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct s_camera
{
	t_vector	*origine;
	t_vector	*direction;
	float		fov;
}				t_camera;

/* ************************************************************************** */
/* Enum                                                                       */
/* ************************************************************************** */
typedef enum e_object
{
	NONE,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_object;

typedef enum e_ray
{
	FOR_HIT,
	FOR_COLOR
}			t_ray;

//##########fonction#########//

/* ************************************************************************** */
/*                                                                            */
/* Parsing                                                                    */
/*                                                                            */
/* ************************************************************************** */
	//parsing.c
int			parsing(int argc, char **argv, t_data *data);
	//check.c
int			ft_msg_error(char *str, int value);
int			ft_msg_error_tab(char *str, int value, char **tab );
int			endwith(char *argv, char *value);
int			check_argument(int argc, char **argv);
int			check_tab(char **rows, t_data *data);
int			check_min_scene(char **tab);
int			check_type(char *src, t_data *data);
	//get_file
char		check_last_char(char *str);
void		delete_comment(char *str);
char		*get_string(int fd);
char		**checkget_file_content(int fd);
	//utils.c
char		*ft_strjoin_free(char *s1, char *s2);
void		printf_row(char **row);
int			size_tab(char **tab);
void		free_tab(char **tab);
int			check_float_point(char **tab);
	//conversion.c
t_vector	*add_vector_float(char *str);
t_vector	*add_color_int(char *str);
int			add_int(char *str);

	//check_object.c
char		**check_error_type(char *str, char **tmp);
char		**check_correct_type(const char *content, char *tab);

	//check_objet_essential.c
int			check_vector_normalised(t_vector *vector);
int			check_ambiance(char *tab, t_data *data);
int			check_camera(char *tab, t_data *data);
int			check_light(char *tab, t_data *data);
int			init_sphere(t_sphere *current, char **tmp);

	//chech_object_liste.c
int			check_sphere(char *tab, t_data *data);
int			check_plane(char *tab, t_data *data);
int			check_cylinder(char *tab, t_data *data);
	//check_utils.c
int			ft_is_space(char c);
int			ft_is_digit(char c);
int			ft_is_good_char(char c);
int			check_num(char *tab, char *str, int size_setting);

	//check_type.c
int			check_correct_intxyz(char **tmp, int j);
int			check_correct_floatxyz(char **tmp, int j);
int			check_correct_char(char **tmp, int j);
int			check_correct_int(char **tmp, int j);
int			check_correct_float(char **tmp, int j);
	//ft_atof.c
double		ft_atof(char *s);

char		**ft_split_espace(char const *str);

/* ************************************************************************** */
/* Initialisation - Clear                                                     */
/* ************************************************************************** */
	//initialisation
int			error_allocation(void);
int			init_struct(t_data *data);
int			init_data(t_data *data);
int			init_scene(t_data *data);
int			init_struct_sphere(t_sphere *sphere);
int			init_struct_plane(t_plane *plane);
int			init_struct_cy(t_cylinder *cylinder);

	//clear
int			ft_close(t_data *data);
int			clean_data(t_data *data, int code_error);
int			free_scene(t_scene *scene);
void		free_sphere_list(t_sphere *head);
void		free_plane_list(t_plane *head);
void		free_cylinder_list(t_cylinder *head);

/* ************************************************************************** */
/*                                                                            */
/* Raytracing                                                                 */
/*                                                                            */
/* ************************************************************************** */
	//vector.c
t_vector	new_vector(float x, float y, float z);
t_vector	vec_subtract(t_vector *vec1, t_vector *vec2);
void		vec_normalize(t_vector *vec);
float		vec_lenght(t_vector *vec1, t_vector *vec2);
float		vec_dot_product(t_vector *vec1, t_vector *vec2);

	//vector2.c
t_vector	vec_add(t_vector *vec1, t_vector *vec2);
t_vector	vec_multiplying(t_vector *vec1, float nbr);
bool		vec_compare(t_vector *vec1, t_vector *vec2);
t_vector	vec_vec_multi(t_vector *vec1, t_vector *vec2);
t_vector	vec_cross(t_vector *vec1, t_vector *vec2);

	//ray_tracing
void		get_view_plane(t_data *data);
int			get_hit(t_data *data, t_scene tmp, t_vector x_ray, t_vector y_ray);
// int			get_hit(t_data *data, t_scene tmp, float x_ray, float y_ray);
int			get_color(t_data *data, t_vector x_ray, t_vector y_ray);
// int			get_color(t_data *data, float x_ray, float y_ray);
void		ray_tracing(t_data *data);
void		init_tmp_ray(t_scene *tmp, t_object object);

	//sphere
float		sphere_intersect(t_vector *origin, t_vector *direction,
				t_sphere *sph);
int			get_color_sphere(t_data *data, t_hit *hit);
t_vector	get_diffuse_light(t_data *data, t_hit *hit);
t_vector	obtain_ray_sphere(t_data *data, t_vector x_ray, t_vector y_ray);
int			is_sphere(t_data *data, t_scene tmp);

	//plane
float		plane_intersect(t_data *data, t_plane *pl);
int			get_color_plane(t_data *data);
t_vector	*get_diffuse_light_pl(t_data *data);
void		obtain_ray_pl(t_data *data, t_ray type_ray, t_scene tmp,
				float x_ray, float y_ray);

	//cylinder
float		cylinder_intersect(t_data *data, t_cylinder *cy);
float		on_cy(t_cylinder *cy);
int			get_color_cylinder(t_data *data, t_cylinder *cy);
t_vector	get_diffuse_light_cy(t_data *data);
void		obtain_ray_cy(t_data *data, t_ray type_ray, t_scene tmp,
				float x_ray, float y_ray);

	//cylinder2
int			get_pl_intersect(t_data *data, t_cylinder *cy);
int			add_plane(t_data *data, t_cylinder *cy);
int			get_mix_color(t_data *data);
int			cy_quadratic(t_data *data, t_cylinder *cy, float dist[2]);

	//maths_util
int			quadratic_equation(float t[2], float a, float b, float c);
float		ft_square(float a);
float		checking_limit(float a, float min, float max);

	//colors
int			create_rgb(t_vector *colors);
void		my_mlx_pixel_put(t_data *data, int color);
void		limit_color(t_vector *color);

int			event(t_data *data);

#endif
