/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/03 15:20:45 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
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
//# include "mlx_linux/mlx.h"
//# include "mlx_linux/mlx_int.h"

# define OK 0
# define ERROR -1

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
} t_point;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
} t_colors;

typedef struct s_axis
{
	float	x_axis;
	float	y_axis;
	float	z_axis;
} t_axis;

typedef struct s_plane
{
	t_point		pl_point;
	t_axis		pl_axis;
	t_colors	pl_colors;
} t_plane;

typedef struct s_cylinder
{
	t_point		cy_point;
	t_axis		cy_axis;
	float		cy_diam;
	float		cy_height;
	t_colors	cy_colors;
} t_cylinder;

typedef struct s_sphere
{
	t_point		sp_point;
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
	t_point	cam_point;
	t_axis	cam_axis;
	int		cam_fov;
} t_camera;

typedef struct s_light
{
	t_point		light_point;
	int			light_ratio;
	t_colors	light_colors;
} t_light;

typedef struct s_scenes // max objets par scene
{
	t_cylinder	cy_list;
	t_plane		pl_list;
	t_sphere	sp_list;
	t_light		light_list;
	t_ambient	ambient;
	t_camera	cam;
	int			res_height;
	int			res_width;
} t_scenes;
#endif
