/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:39:57 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/30 08:48:46 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	endwith(char *argv, char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv == NULL)
		return (1);
	while (argv[i] != '\0')
		i++;
	i -= ft_strlen(value);
	while (argv[i])
	{
		if (argv[i] == value[j])
		{
			j++;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_argument(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_msg_error("Please run './miniRT scene.rt'", -1));
	if (!argv[1] || !*argv[1])
		return (ft_msg_error("empty file", -1));
	if (endwith(argv[1], ".rt") == 1)
		return (ft_msg_error("file must finished by .rt", -1));
	fd = open(argv[1], O_RDWR);
	if (fd <= -1)
		return (ft_msg_error("no accessed the file.rt", -1));
	return (fd);
}

int	check_tab(char **rows, t_data *data)
{
	int	i;

	i = 0;
	if (rows == NULL)
		return (ft_msg_error("empty file", 1));
	if (check_min_scene(rows) == ERROR)
	{
		free_tab(rows);
		return (ft_msg_error("there must be (1)A,(1)C,(1)L", 1));
	}
	while (rows[i])
	{
		if (check_type(rows[i], data) != 0)
		{
			free_tab(rows);
			printf("\033[31mERROR Parse ligne :%d\033[0m\n", i);
			return (1);
		}
		i++;
	}
	return (OK);
}

int	check_min_scene(char **tab)
{
	int	i;
	int	len_a;
	int	len_c;
	int	len_l;

	i = 0;
	len_a = 0;
	len_c = 0;
	len_l = 0;
	while (tab[i])
	{
		remouve_space_start_line(tab[i]);
		if (!ft_strncmp(tab[i], "A ", 1))
			len_a++;
		if (!ft_strncmp(tab[i], "C ", 1))
			len_c++;
		if (!ft_strncmp(tab[i], "L ", 1))
			len_l++;
		i++;
	}
	if (len_a != 1 || len_c != 1 || len_l != 1)
		return (ERROR);
	return (OK);
}

int	check_type(char *src, t_data *data)
{
	char	**tab;

	tab = ft_split_espace(src);
	if (!tab)
		ft_msg_error(" alloc ", 1);
	if (tab[0])
	{
		if (ft_strncmp(tab[0], "A", 2) == 0)
			return (free_tab(tab), check_ambiance(src, data));
		else if (!ft_strncmp(tab[0], "C", 2))
			return (free_tab(tab), check_camera(src, data));
		else if (!ft_strncmp(tab[0], "L", 2))
			return (free_tab(tab), check_light(src, data));
		else if (!ft_strncmp(tab[0], "sp", 3))
			return (free_tab(tab), check_sphere(src, data));
		else if (!ft_strncmp(tab[0], "pl", 3))
			return (free_tab(tab), check_plane(src, data));
		else if (!ft_strncmp(tab[0], "cy", 3))
			return (free_tab(tab), check_cylinder(src, data));
		else
			return (ft_msg_error_tab("Please check: this is not an object -> "
					, 1, tab));
	}
	free_tab(tab);
	return (0);
}
