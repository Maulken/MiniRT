/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 14:55:28 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
	data->scene->camera->direction = add_vector_float(tmp[2]);
	data->scene->camera->fov = add_float(tmp[3]);
	if (data->scene->camera->fov > 180 || data->scene->camera->fov < 0)
	{
		printf("ERROR fov superieur a 180 ou inferieur a 0");
		free(data->scene->camera);
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

int	check_sphere(char *tab, t_data *data)
{
	t_sphere			*current;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 't', 'i', 'v', 'v'};

	current = malloc(sizeof(t_sphere));
	if(current== NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "sp", 4))
		return (1);
	
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	current->center = add_vector_float(tmp[1]);
	current->diameter = add_float(tmp[2]);
	current->color = add_color_int(tmp[3]);
	
	if(data->scene->spheres->next == NULL)
		data->scene->spheres->next = current;
	else 
	{
		t_sphere *last = data->scene->spheres;
		while (last->next != NULL)
			last = last->next;
		last->next = current;
	}
	free_tab(tmp);
	return (0);
}
/*check plane experimental no leack fonction*/
int	check_plane(char *tab, t_data *data)
{
	t_plane				*current;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 'i', 'v', 'v'};

	current = malloc(sizeof(t_plane));
	if (current == NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "pl", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	current->origine = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	current->color = add_color_int(tmp[3]);
	if (data->scene->plane == NULL)
		data->scene->plane->next = current;
	else 
	{
		t_plane *last = data->scene->plane;
		while (last->next != NULL)
			last = last->next;
		last->next = current;
	}
	free_tab(tmp);
	return (0);
}

int	check_cylinder(char *tab, t_data *data)
{
	t_cylinder			*current;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 't', 'i'};

	current = malloc(sizeof(t_cylinder));
	if (current == NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "cy", 6))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	current->center = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	current->diameter = add_float(tmp[3]);
	current->height = add_float(tmp[4]);
	current->color = add_color_int(tmp[5]);
	if(data->scene->cylinder->next == NULL)
		data->scene->cylinder->next = current;
	else 
	{
		t_cylinder *last = data->scene->cylinder;
		while (last->next != NULL)
			last = last->next;
		last->next = current;
	}
	free_tab(tmp);
	return (0);
}
