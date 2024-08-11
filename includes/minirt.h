/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/11 16:00:05 by vharatyk         ###   ########.fr       */
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

# define OK 0
# define ERROR -1
typedef struct s_scenes t_scenes;

//##########struct#########//

typedef struct s_data // data principal . pour la mlx
{
	t_scenes *scenes;

    int width;
    int height;

    int wx;
    int wy;

    
    void *mlx;
    void *win;
    void *img;
    void *addr;

    int		bits_per_pixel;
    int		line_length;
	int		endin;

	int fd;

} t_data ;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
} t_colors;

typedef struct s_cord // ou vec ?? 
{
	float	x;
	float	y;
	float	z;
} t_cord;


typedef struct s_plane
{
	t_cord		pl_point;
	t_cord		pl_axis;
	t_colors	pl_colors;
} t_plane;

typedef struct s_cylinder
{
	t_cord		cy_point;
	t_cord		cy_axis;
	float		cy_diam;
	float		cy_height;
	t_colors	cy_colors;
} t_cylinder;

typedef struct s_sphere
{
	t_cord		sp_point;
	float		sp_diam;
	t_colors	sp_colors;
} t_sphere;

typedef struct s_ambient
{
	float		amb_ratio;
	t_colors	amb_colors;
} t_ambient;

typedef struct s_camera
{
	t_cord	cam_cord;
	t_cord	cam_or;
	int		cam_fov;


} t_camera;

typedef struct s_light
{
	t_cord		light_point;
	int			light_ratio;
	t_colors	light_colors;
} t_light;


 typedef struct s_object
{
	int			id;
	t_cylinder	cy;
	t_plane		pl;
	t_sphere	sp;

} t_object;

typedef struct s_scenes
{
	t_camera	cam;
	t_ambient	ambient;
	t_light		light_list;
	t_object	*object;

} t_scenes;



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
	//get_scenes.c
t_scenes	*create_scenes_getinfo(char **tab ,t_data *data);

	//check_object.c
int		check_num(char *tab, char *str, int size_setting);
int		check_correct_type(char *content, char *tab);
int		check_a(char *tab);
int		check_c(char *tab);
int		check_l(char *tab);
int		check_sp(char *tab);
int		check_pl(char *tab);
int		check_cy(char *tab);


/*RT*/
	//clear.c
int		ft_close(t_data *data);
int		clean(t_data *data ,int code_error);

	//init.c
int		init_struct(t_data *data);


int	event(t_data *data);

#endif
