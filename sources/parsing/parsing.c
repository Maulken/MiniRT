/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:30:22 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/09 10:25:21 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	next(char *str)
{
	while (*str == 32 || *str == 9)
		(str)++;
}
double	ft_atof(char *str)
{
	int		w;
	double	d;
	int		neg;

	w = 0;
	neg = 1;
	if (*str == '-' && ((*str)++))
		neg = -1;
	while (ft_isdigit(*str))
		w = w * 10 + (((*str)++) - '0');
	if (*str == '.')
		(*str)++;
	d = 0.0;
	while (ft_isdigit(*str))
		d = d * 10 + (((*str)++) - '0');
	while (d >= 1)
		d /= 10;
	d += w;
	next(str);
	return (d * neg);
}

int ft_strdigit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) == 0 && str[i] != ',')
			return(ERROR);
		i++;
	}
	return(OK);
}
int ft_colors_parse(char *arg, t_colors colors)
{
	char **rbg;

	rbg = ft_split(arg, ',');
	if(!rbg)
		return(0);
	colors.r = ft_atoi(rbg[0]);
	colors.b = ft_atoi(rbg[1]);
	colors.g = ft_atoi(rbg[2]);
	return(0);
}
int ft_axis_parse(char *arg, t_axis axis)
{
	char **view_point;

	view_point = ft_split(arg, ',');
	if(!view_point)
		return(0);
	axis.x_axis = ft_atof(view_point[0]);
	axis.y_axis = ft_atof(view_point[1]);
	axis.z_axis = ft_atof(view_point[2]);
	return(0);
}
int ft_point_parse(char *arg, t_cord cord)
{
	char **start;

	start = ft_split(arg, ',');
	if(!start)
		return(0);
	cord.x = ft_atof(start[0]);
	cord.y = ft_atof(start[1]);
	cord.z = ft_atof(start[2]);
	return(0);
}

int	ft_parse_R(char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[3] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR)
		return(0);
	scene.res_height = ft_atoi(tab[1]);
	scene.res_width = ft_atoi(tab[2]);
	printf("reso = %d\n", scene.res_height);
	free(tab);
	return(0);
}
int	ft_parse_A(char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[3] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR)
		return(0);
	scene.ambient.amb_ratio = ft_atof(tab[1]);
	ft_colors_parse(tab[2], scene.ambient.amb_colors);
	return(0);
}
int ft_parse_C( char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return(0);
	ft_point_parse(tab[1], scene.cam.cam_point);
	ft_axis_parse(tab[2], scene.cam.cam_axis);
	scene.cam.cam_fov = ft_atoi(tab[3]);
	if(scene.cam.cam_fov > 180)
		return(0);
	return(0);
}
int ft_parse_L( char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return(0);
	ft_point_parse(tab[1], scene.light_list.light_point);
	scene.light_list.light_ratio = ft_atof(tab[2]);
	ft_colors_parse(tab[3], scene.light_list.light_colors);
	return(0);
}
int ft_parse_sp( char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return(0);
	ft_point_parse(tab[1], scene.sp_list.sp_point);
	scene.sp_list.sp_diam = ft_atof(tab[2]);
	ft_colors_parse(tab[3], scene.sp_list.sp_colors);
	return(0);
}
int ft_parse_cy( char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[6] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR || ft_strdigit(tab[4]) == ERROR
		|| ft_strdigit(tab[4]) == ERROR)
		return(0);
	ft_point_parse(tab[1], scene.cy_list.cy_point);
	ft_axis_parse(tab[2], scene.cy_list.cy_axis);
	scene.cy_list.cy_diam = ft_atof(tab[3]);
	scene.cy_list.cy_height = ft_atof(tab[4]);
	ft_colors_parse(tab[3], scene.cy_list.cy_colors);
	return(0);
}
int ft_parse_pl( char *line, t_scenes scene)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(line, ' ');
	if(!tab)
		return(0);
	if(!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return(0);
	ft_point_parse(tab[1], scene.pl_list.pl_point);
	ft_axis_parse(tab[2], scene.pl_list.pl_axis);
	ft_colors_parse(tab[3], scene.pl_list.pl_colors);
	return(0);
}
int	ft_parse_arg(char *line, t_scenes *scene)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(line[0] && strcmp(line, "R "))
			ft_parse_R(line, *scene);
		else if(line[0] && strcmp(line, "A "))
			ft_parse_A(line, *scene);
		else if(line[0] && strcmp(line, "C "))
			ft_parse_C(line, *scene);
		else if(line[0] && strcmp(line, "L "))
			ft_parse_L(line, *scene);
		else if(line[0] && strcmp(line, "sp "))
			ft_parse_sp(line, *scene);
		else if(line[0] && strcmp(line, "cy "))
			ft_parse_cy(line, *scene);
		else if(line[0] && strcmp(line, "pl "))
			ft_parse_pl(line, *scene);
		else
			return(0);
	}
	return(0);
}


int parsing(int argc , char **argv, t_data *data)
{
	char *line;
	char **tab;
	int i;

	data->fd = check_argument(argc , argv);
	line = checkget_file_content(data->fd);
	
	line = get_next_line(data->fd);
		printf("line = %s\n", line);

	tab = malloc(sizeof(char*) * 40);
	if(!tab)
		return(0);

	i = 0;
	while ((line != NULL))
	{
		if(line[0] != '\n')
		{
			tab[i] = malloc(sizeof(char) * ft_strlen(line));
			tab[i] =  line;
		
			i++;
		}
	line = get_next_line(data->fd);
	}
	i = 0;
	// while(line != NULL)
	// {
		printf("test\n");
		ft_parse_arg(line, data->scenes);
	//}
	free(line);
	close(data->fd);
	return(1);
}
