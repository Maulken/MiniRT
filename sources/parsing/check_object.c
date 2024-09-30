/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/30 08:55:45 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static char	**check_correct_value_type(const char *content, int j, char **tmp)
{
	if (content[j] == 'i')
	{
		if (check_correct_intxyz(tmp, j))
			return (check_error_type("invalid RGB", tmp));
	}
	else if (content[j] == 'f' )
	{
		if (check_correct_floatxyz(tmp, j))
			return (check_error_type("invalid XYZ", tmp));
	}
	if (content[j] == 'c')
	{
		if (check_correct_char(tmp, j))
			return (check_error_type("invalid char", tmp));
	}
	else if (content[j] == 'k')
	{
		if (check_correct_int(tmp, j))
			return (check_error_type("invalid int", tmp));
	}
	else if (content[j] == 't')
		if (check_correct_float(tmp, j) == 1)
			return (check_error_type("invalid float", tmp));
	return (tmp);
}

/*because I have no space is une essential */
int	init_sphere(t_geometry *current, char **tmp)
{
	t_sphere *const	sphere = &current->data.sphere;

	current->type = GT_SPHERE;
	if (ft_strlen(tmp[1]) > LIMIT_VEC || ft_strlen(tmp[2]) > LIMIT
		|| ft_strlen(tmp[3]) > LIMIT)
		return (1);
	sphere->diameter = ft_atof(tmp[2]);
	if (sphere->diameter < 0)
		return (ft_msg_error("Size must not be below 0", 1));
	add_vector_float(&sphere->center, tmp[1]);
	if (add_color_int(&current->color, tmp[3]) == NULL)
		return (1);
	return (0);
}

char	**check_error_type(char *str, char **tmp)
{
	printf("\033[31mERROR: %s\033[0m\n", str);
	free_tab(tmp);
	return (NULL);
}

/*
    explication du tableau content
    c = char
    f = cordonner flote mais sous trois axe x,y,z
	g = cordonner flote normalized mais sous trois axe x,y,z
    i = cordonner int sous trois axe z,y,z
    k = une FOV , en int 1 valeur attendu
    t = une taille de volume floate (utile pour L , cy)
	n = normalalized vector [0.0,1.0]
    v = void
*/
char	**check_correct_type(const char *content, char *tab, char *type,
		int len)
{
	int		j;
	char	*line;
	char	**tmp;

	line = remouve_space_cord(tab);
	tmp = ft_split_espace(line);
	if (check_num(line, type, len) == 1)
	{
		free(line);
		free_tab(tmp);
		return (NULL);
	}
	free(line);
	if (tmp == NULL)
		return (free_tab(tmp), NULL);
	j = 0;
	while (tmp[j])
	{
		if (check_correct_value_type(content, j, tmp) == NULL)
			return (NULL);
		j++;
	}
	return (tmp);
}

void	remouve_space_start_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i > 0)
	{
		j = 0;
		while (str[i])
			str[j++] = str[i++];
		str[j] = '\0';
	}
}
