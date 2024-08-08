/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:23 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/08 16:17:17 by mpelluet         ###   ########.fr       */
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

# define OK 0
# define ERROR -1


typedef struct s_point
{
	double	x;
	double	y;
	double	z;
} t_point;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
} t_colors;

typedef struct s_sphere
{
	t_point		*sp_point;
	float		sp_diam;
	t_colors	*sp_colors;
} t_sphere;

typedef struct s_data // data principal . pour la mlx
{
    int width;
    int height;

    double  Cw;
    double  Ch;
    int x;
    int y;
    double  t_min;
    double  t_max;
    double	t[2];
    
    void *mlx;
    void *win;
    void *img;
    void *addr;
    int		bits_per_pixel;
    int		line_length;
	int		endin;
    t_point *camera;
    t_point *D;
    t_sphere    *sphere;
} t_data ;




int	ft_close(t_data *data);
int	init_struct(t_data *data);

#endif