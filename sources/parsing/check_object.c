/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/11 14:47:36 by vharatyk         ###   ########.fr       */
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
	return (tmp); // i not like do you like . 
}

/*because I have no space is une essential */
int	init_sphere(t_sphere *current, char **tmp)
{
	current->center = add_vector_float(tmp[1]);
	current->diameter = ft_atof(tmp[2]);
	current->color = add_color_int(tmp[3]);
	current->impact_point = NULL;
	current->ray = NULL;
	current->ray_light = NULL;
	return (0);
}

char	**check_error_type(char *str, char **tmp)
{
	printf("ERROR : %s\n", str);
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
char	**check_correct_type(const char *content, char *tab)
{
	int		j;
	char	**tmp;


	// donc la imaagine nous avons cela (sp) (-2 , 0 , 4)       (2)     (241 , 155 , 21)
	
	tmp = ft_split_espace(tab);
	tmp = ft_split_line(tab);
	if(tmp == NULL)
		return (NULL);
	for(int i = 0; tmp[i]; i++)
		printf("tmp: %s\n", tmp[i]);
	printf("END \n");

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
	while (str[i] == ' ')
		i++;
	if (i > 0)
	{
		j = 0;
		while (str[i])
			str[j++] = str[i++];
		str[j] = '\0';
	}
}
