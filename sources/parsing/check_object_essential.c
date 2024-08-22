/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_essential.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 16:13:33 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_ambiance(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 't', 'i', 'v', 'v', 'v'};

	if (check_num(tab, "A", 3))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	data->scene->ambient->ratio = add_float(tmp[1]);
	data->scene->ambient->colors = add_color_int(tmp[2]);
	data->scene->ambient->ambient_light = vec_multiplying(
			data->scene->ambient->colors, data->scene->ambient->ratio);
	free_tab(tmp);
	return (0);
}

int	check_camera(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 'v', 'v'};

	if (check_num(tab, "C", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
		return (1);
	data->scene->camera->origine = add_vector_float(tmp[1]);
	data->scene->camera->orientation = add_vector_float(tmp[2]);
	data->scene->camera->fov = add_float(tmp[3]);
	if (data->scene->camera->fov > 180 || data->scene->camera->fov < 0)
	{
		printf("ERROR fov superieur a 180 ou inferieur a 0");
		//free(data->scene->camera);
		free_tab(tmp);
		return (1);
	}
	free_tab(tmp);
	return (0);
}

int	check_light(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 'f', 't', 'i', 'v', 'v'};

	if (check_num(tab, "L", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free(tmp);
		return (1);
	}
	data->scene->light->origine = add_vector_float(tmp[1]);
	data->scene->light->ratio = add_float(tmp[2]);
	free_tab(tmp);
	return (0);
}

/*because I have no space is une essential */
int	init_sphere(t_sphere *current, char **tmp)
{
	current->center = add_vector_float(tmp[1]);
	current->diameter = add_float(tmp[2]);
	current->color = add_color_int(tmp[3]);
	current->impact_point = NULL;
	current->ray = NULL;
	current->ray_light = NULL;
	return (0);
}