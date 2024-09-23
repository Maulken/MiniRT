/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/23 17:01:23 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "scene.h"
# include "vector.h"

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define OK 0
# define ERROR -1

/* ************************************************************************** */
/* Structures                                                                 */
/* ************************************************************************** */

typedef struct s_hit
{
	t_geometry	*geometry;
	float		distance;
}				t_hit;

typedef struct s_view
{
	float		width;
	float		height;
	float		distance;
	t_vector	viewplane_x;
	t_vector	viewplane_y;
}				t_view;

typedef struct s_data
{
	t_scene		*scene;
	t_view		view;
	t_hit		hit;
	t_vector	white_light;
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
	int			id;
	int			count_object;
}			t_data;

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
char		*remouve_space_cord(char *tab);
	//check.c
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
int			size_tab(char **tab);
void		free_tab(char **tab);
int			check_float_point(char **tab);
	//utils2.c
int			ft_msg_error(char *str, int value);
int			ft_msg_error_tab(char *str, int value, char **tab);
int			ft_is_space(char c);
int			ft_is_digit(char c);
int			ft_is_good_char(char c);

	//conversion.c
t_vector	*add_vector_float(t_vector *vec, char *str);
t_vector	*add_color_int(t_vector *rgb, char *str);

	//check_object.c
int			init_sphere(t_geometry *current, char **tmp);
char		**check_error_type(char *str, char **tmp);
char		**check_correct_type(const char *content, char *tab,
				char *type, int len);
void		remouve_space_start_line(char *str);

	//check_objet_essential.c
int			is_normalized(float x, float y, float z);
int			check_vector_normalised(t_vector *vector);
int			check_ambiance(char *tab, t_data *data);
int			check_camera(char *tab, t_data *data);
int			check_light(char *tab, t_data *data);

	//chech_object_liste.c
int			check_sphere(char *tab, t_data *data);
int			init_plane(t_geometry *current, char **tmp);
int			check_plane(char *tab, t_data *data);
int			init_cylinder(t_geometry *current, char **tmp);
int			check_cylinder(char *tab, t_data *data);

	//check_utils.c
int			check_num(char *tab, char *str, int size_setting);
int			check_signe(char *str);
int			check_signe_tab(char **tab);

	//check_type.c
int			check_correct_intxyz(char **tmp, int j);
int			check_correct_floatxyz(char **tmp, int j);
int			check_correct_char(char **tmp, int j);
int			check_correct_int(char **tmp, int j);
int			check_correct_float(char **tmp, int j);

	//split_space.c
char		**ft_split_espace(char const *str);

/* ************************************************************************** */
/* Initialisation - Clear                                                     */
/* ************************************************************************** */
	//initialisation
int			error_allocation(void);
int			init_data(t_data *data);
int			init_scene(t_data *data);

	//clear
int			ft_close(t_data *data);
int			clean_data(t_data *data, int code_error);
int			free_scene(t_scene *scene);
void		free_geometry_list(t_geometry *geometry);

/* ************************************************************************** */
/*                                                                            */
/* Raytracing                                                                 */
/*                                                                            */
/* ************************************************************************** */

	//ray_tracing
void		get_view_plane(t_data *data);
void		get_hit(t_data *data, t_scene tmp, t_vector *rx, t_vector *ry);
int			get_color(t_data *data, t_vector *x_ray, t_vector *y_ray);
void		ray_tracing(t_data *data);

	//sphere
float		sphere_intersect(t_geometry *sph);
int			get_color_sphere(t_data *data, t_hit *hit);
void		get_diffuse_light(t_data *data, t_hit *hit, t_vector *color);
void		obtain_ray(t_data *data, t_vector *rx, t_vector *ry, t_vector *ray);
void		is_sphere(t_data *data, t_scene tmp);

	//plane
float		plane_intersect(t_data *data, t_geometry *pl);
int			get_color_plane(t_data *data);
void		get_diffuse_light_pl(t_data *data, t_vector *color);

	//cylinder
float		cylinder_intersect(t_geometry *cy);
float		on_cy(t_geometry *cy);
int			get_color_cylinder(t_data *data, t_hit *hit);
void		get_diffuse_light_cy(t_data *data, t_vector *color);

	//cylinder2
int			get_pl_intersect(t_data *data, t_geometry *cy);
int			add_plane(t_data *data, t_geometry *cy);
int			get_mix_color(t_data *data);
int			cy_quadratic(t_geometry *cy, float math_value[3]);

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
