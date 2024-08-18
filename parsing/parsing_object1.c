/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:17:55 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 22:00:43 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_r(char *line, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!tab[3] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR)
		return (0);
	data->view->width = ft_atoi(tab[1]);
	data->view->height = ft_atoi(tab[2]);
	free(tab);
	return (0);
}

int	ft_parse_a(char *line, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (!tab[3] || ft_strdigit(tab[1]) == ERROR || ft_strdigit(tab[2]) == ERROR)
		return (0);
	data->scene->ambient->ratio = ft_atof(tab[1]);
	ft_colors_parse(tab[2], data->scene->ambient->colors);
	return (0);
}

int	ft_parse_c(char *line, t_data *data)
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
	ft_point_parse(tab[1], data->scene->camera->origine);
	ft_point_parse(tab[2], data->scene->camera->direction);
	data->scene->camera->fov = ft_atoi(tab[3]);
	if (data->scene->camera->fov > 180)
		return (0);
	free(tab);
	return (0);
}

int	ft_parse_l( char *line, t_data *data)
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
	ft_point_parse(tab[1], data->scene->light->origine);
	data->scene->light->ratio = ft_atof(tab[2]);
	return (0);
}
