/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 17:10:18 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

	tmp = ft_split_espace(tab);
	j = 0;
	while (tmp[j])
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
		j++;
	}
	return (tmp);
}
