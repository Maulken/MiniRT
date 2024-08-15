/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/15 19:34:08 by vharatyk         ###   ########.fr       */
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

typedef struct	s_view t_view;
//##########struct#########//

typedef struct s_data // data principal . pour la mlx
{
	t_scene *scene;
    t_view 	*view;

    void *mlx;
    void *win;
    void *img;
    void *addr;
    int		bits_per_pixel;
    int		line_length;
	int		endin;
	
	int fd;

} t_data ;

typedef struct	s_view
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_view;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
} t_vector;

typedef struct s_camera
{
	t_vector *origine;
	t_vector *direction;
	float 		fov;
} t_camera;



//##########fonction#########//

/*PARSING*/
	//parsing.c
int		parsing(int argc ,char **argv ,t_data *data);
	//check.c
int 	endwith(char *argv, char *value);
int 	check_argument(int argc , char **argv);
int		check_tab(char **rows , t_data *data);
int		check_min_scene(char **tab);
int 	check_type(char *src ,t_data *data);
	//get_file
char	check_last_char(char *str);
void	delete_comment(char *str);
char	*get_string(int fd);
char	**checkget_file_content(int fd);
	//utils.c
char	*ft_strjoin_free(char *s1, char *s2);
void	printf_row(char **row);
int		size_tab(char **tab);
void	free_tab(char **tab);
	//conversion.c
t_vector *add_vector_float(char *str);
t_color   *add_color_int(char *str);
int				add_int(char *str);
float			add_float(char *str);


	//check_object.c
char **check_correct_type(char *content, char *tab);
int check_ambiance(char *tab, t_data *data);

	//chech_object2.c
int check_camera    (char *tab , t_data *data);
int check_light(char *tab, t_data *data);
int check_sphere(char *tab , t_data *data);
int check_plane(char *tab, t_data *data);
int check_cylinder(char *tab, t_data *data);
	//check_utils.c
int		check_num(char *tab, char *str, int size_setting);
double ft_atof_custom(const char *str);

	//check_type.c
int check_correct_intxyz(char **tmp, int j);
int check_correct_floatxyz(char **tmp , int j);
int check_correct_char(char **tmp, int j);
int check_correct_int(char **tmp , int j);
int check_correct_float(char **tmp , int j);

/*RT*/
	//clear.c
int		ft_close(t_data *data);
int		clean(t_data *data ,int code_error);

	//init.c
int		init_struct(t_data *data);
void	init_data(t_data *data);

	//vector.c
t_vector 	*new_vector(float x, float y, float z);
t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2);
void		vec_normalize(t_vector *vec);
float		vec_lenght(t_vector *vec);
float		vec_dot_product(t_vector *vec1, t_vector *vec2);
	//ray_tracing
void		get_view_plane(t_data *data);
void		ray_tracing(void *mlx, void *window, t_data *data);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere);
//colors
int		create_trgb(int t, t_color *colors);
int	event(t_data *data);

#endif

