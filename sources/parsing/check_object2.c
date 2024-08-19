/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/19 20:30:40 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int check_camera(char *tab , t_data *data)
{
	char        **tmp;

	char content[6] = {'c','f','f','t','v','v'}; // float k->t

	if (check_num(tab, "C", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if(tmp == NULL)
		return(1);

	data->scene->camera->origine = add_vector_float(tmp[1]);
	data->scene->camera->direction = add_vector_float(tmp[2]);
	data->scene->camera->fov = add_float(tmp[3]);
	if(data->scene->camera->fov > 180 || data->scene->camera->fov < 0)
	{
		printf("ERROR fov superieur a 180 ou inferieur a 0");
		free(data->scene->camera); // c'est pas bon ca !!!!
		free_tab(tmp);
		return(1);
	}
	free_tab(tmp);
	return(0);
}


int check_light(char *tab, t_data *data)
{
	char	**tmp;

	char content[6] = {'c','f','t','i','v','v'};

	if (check_num(tab, "L", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if(tmp == NULL)
		{
		free(tmp);
		return(1);
		}
	data->scene->light->origine = add_vector_float(tmp[1]);
	data->scene->light->ratio = add_float(tmp[2]);

	free_tab(tmp);
	return(0);

}

int check_sphere(char *tab , t_data *data)
{
	t_sphere *current;
	char **tmp;

	char content[6] = {'c','f','t','i','v','v'};

	current = malloc(sizeof(t_sphere));
	if (check_num(tab, "sp", 4))
		return (1);
	tmp = check_correct_type(content, tab);
		if(tmp == NULL)
		{
			free_tab(tmp);
			return(1);
		}

	current->center =  add_vector_float(tmp[1]);
	current->color = add_color_int(tmp[3]);
	current->impact_point = NULL;
	current->ray = NULL;
	current->ray_light = NULL;
	current->diameter = add_float(tmp[2]);
	current->dist_light_sphere = 0.0;
	current->dist_cam_sphere = 0.0;
	current->next = NULL;

	data->scene->spheres->next = current;
	data->scene->spheres = data->scene->spheres->next;

	free_tab(tmp);
	return(0);
}

int check_plane(char *tab, t_data *data)
{
	t_plane *current;
	char **tmp;

	current = malloc(sizeof(t_plane));
	char content[6] = {'c','f','f','i','v','v'};
	if (check_num(tab, "pl", 4))
		return (1);
	tmp = check_correct_type(content, tab);
		if(tmp == NULL)
		{
			free_tab(tmp);
			return(1);
		}
	current->origine = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	current->color = add_color_int(tmp[3]);

	 data->scene->plane->next = current;
	data->scene->plane = data->scene->plane->next;
	free_tab(tmp);
	return(0);
}

int check_cylinder(char *tab, t_data *data)
{
	t_cylinder *current;
	char **tmp;
	char content[6] = {'c','f','f','t','t','i'};

	if (check_num(tab, "cy", 6))
		return (1);
	tmp = check_correct_type(content, tab);
	if(tmp == NULL)
		{
			free_tab(tmp);
			return(1);
		}
	current->center = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	current->diameter = add_float(tmp[3]);
	current->height = add_float(tmp[4]);
	current->color = add_color_int(tmp[5]);

	data->scene->cylinder->next = current;
	data->scene->cylinder = data->scene->cylinder->next;
	free_tab(tmp);
	return(0);
}
