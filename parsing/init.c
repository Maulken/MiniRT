/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:53:54 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 22:36:36 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	alloc_struc(t_arena *arena, t_scene *scene)
{
	t_data	*data;

	data = arena_alloc(arena, sizeof(t_data));
	data->scene = arena_alloc(arena, sizeof(t_scene));
	data->view = arena_alloc(arena, sizeof(t_view));
	data->white_light = arena_alloc(arena, sizeof(t_vector));
	scene->light = arena_alloc(arena, sizeof(t_light));
	scene->camera = arena_alloc(arena, sizeof(t_camera));
	scene->spheres = arena_alloc(arena, sizeof(t_sphere));
	scene->plane = arena_alloc(arena, sizeof(t_plane));
	scene->cylinder = arena_alloc(arena, sizeof(t_cylinder));
	scene->ambient = arena_alloc(arena, sizeof(t_ambient));
	scene->width = 0;
	scene->height = 0;
}

int	ft_parse_arg(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[0] && strcmp(line, "R "))
			ft_parse_R(line, data);
		else if (line[0] && strcmp(line, "A "))
			ft_parse_A(line, data);
		else if (line[0] && strcmp(line, "C "))
			ft_parse_C(line, data);
		else if (line[0] && strcmp(line, "L "))
			ft_parse_L(line, data);
		else if (line[0] && strcmp(line, "sp "))
			ft_parse_sp(line, data);
		else if (line[0] && strcmp(line, "cy "))
			ft_parse_cy(line, data);
		else if (line[0] && strcmp(line, "pl "))
			ft_parse_pl(line, data);
		else
			return (0);
	}
	return (0);
}
