/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 01:04:28 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	**check_error_type(char *str, char **tmp)
{
	printf("ERROR : %s\n", str);
	free_tab(tmp);
	return (NULL);
}

char	**check_correct_type(const char *content, char *tab)
{
	int		j;
	char	**tmp;

	tmp = ft_split(tab, ' ');
	j = 0;
	while (tmp[j])
	{
		if (content[j] == 'i')
		{
			if (check_correct_intxyz(tmp, j))
				return (check_error_type("invalid RGB", tmp));
			j++;
		}
		else if (content[j] == 'f' )
		{
			if (check_correct_floatxyz(tmp, j))
				return (check_error_type("invalid XYZ", tmp));
			j++;
		}
		else if (content[j] == 'c')
		{
			if (check_correct_char(tmp, j))
				return (check_error_type("invalid char", tmp));
			j++;
		}
		else if (content[j] == 'k')
		{
			if (check_correct_int(tmp, j))
				return (check_error_type("invalid int", tmp));
			j++;
		}
		else if (content[j] == 't')
		{
			if (check_correct_float(tmp, j) == 1)
				return (check_error_type("invalid float", tmp));
			j++;
		}
		else
			j++;
	}
	return (tmp);
}
/*
    explication du tableau content
    c = char 
    f = cordonner flote mais sous trois axe x,y,z
    i = cordonner int sous trois axe z,y,z
    k = une FOV , en int 1 valeur attendu
    t = une taille de volume floate (utile pour L , cy)
    v = void
*/

int	check_ambiance(char *tab, t_data *data)
{
	char			**tmp;
	static const char	content[6] = {'c', 't', 'i', 'v', 'v', 'v'};

	if (check_num(tab, "A", 3))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	free_tab(tmp);
	return (0);
}
