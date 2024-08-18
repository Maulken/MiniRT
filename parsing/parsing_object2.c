/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:04:36 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 22:08:00 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_sp(char *line, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return (0);
	ft_point_parse(tab[1], data->scene->spheres->center);
	data->scene->spheres->diameter = ft_atof(tab[2]);
	ft_point_parse(tab[1], data->scene->spheres->color);
	return (0);
}

int	ft_parse_cy(char *line, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!tab[6] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR || ft_strdigit(tab[4]) == ERROR
		|| ft_strdigit(tab[4]) == ERROR)
		return (0);
	ft_point_parse(tab[1], data->scene->cylinder->center);
	ft_point_parse(tab[2], data->scene->cylinder->direction);
	data->scene->cylinder->diameter = ft_atof(tab[3]);
	data->scene->cylinder->height = ft_atof(tab[4]);
	ft_point_parse(tab[3], data->scene->cylinder->color);
	return (0);
}

int	ft_parse_pl(char *line, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!tab[4] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR
		|| ft_strdigit(tab[3]) == ERROR)
		return (0);
	ft_point_parse(tab[1], data->scene->plane->origine);
	ft_point_parse(tab[2], data->scene->plane->direction);
	ft_point_parse(tab[3], data->scene->plane->color);
	return (0);
}

int	ft_colors_parse(char *arg, t_vector *colors)
{
	char	**rbg;

	rbg = ft_split(arg, ',');
	if (!rbg)
		return (0);
	colors->x = (float)ft_atoi(rbg[0]);
	colors->y = (float)ft_atoi(rbg[1]);
	colors->z = (float)ft_atoi(rbg[2]);
	free(rbg);
	return (0);
}

int	ft_point_parse(char *arg, t_vector *point)
{
	char	**start;

	start = ft_split(arg, ',');
	if (!start)
		return (0);
	point->x = ft_atof(start[0]);
	point->y = ft_atof(start[1]);
	point->z = ft_atof(start[2]);
	free(start);
	return (0);
}
