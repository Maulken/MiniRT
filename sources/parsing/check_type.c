/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:30 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/05 17:56:13 by viktor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_signe(char *str)
{
	int start_num;
	int nb_signe;
	int i;
	
	start_num = 0;
	nb_signe = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			start_num = 1;
		if (str[i] == '+' || str[i] == '-' )
		{
			nb_signe++;
			if (nb_signe == 2 || start_num == 1)
				return (1);
		}
		i++;
	}
	return(0);
}

int check_signe_tab(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
	{	
		if(check_signe(tab[index]) == 1)
			return(1);
	index++;
	}
	return (0);
}

int	check_correct_intxyz(char **tmp, int j)
{
	int		i;

	char	**tab;

	i = 0;
	while (tmp[j][i] != '\0')
	{
		if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
			tmp[j][i] != '+' && tmp[j][i] != '-' && 
			tmp[j][i] != ',')
			return (1);
		i++;
	}
	tab = ft_split(tmp[j], ',');
	if (size_tab(tab) != 3 || check_signe_tab(tab) == 1)
		return (free_tab(tab), 1);

	free_tab(tab);
	j++;
	return (0);
}

int	check_correct_floatxyz(char **tmp, int j)
{
	int		i;
	char	**tab;

	i = 0;
	while (tmp[j][i] != '\0')
	{
		if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
			tmp[j][i] != '.' && tmp[j][i] != '-' &&
			tmp[j][i] != '+' && tmp[j][i] != ',')
			return (1);
		i++;
	}
	tab = ft_split(tmp[j], ',');
	if (size_tab(tab) != 3 || check_float_point(tab) || check_signe_tab(tab))
	{
		free_tab(tab);
		return (1);
	}
	free_tab(tab);
	j++;
	return (0);
}

int	check_correct_char(char **tmp, int j)
{
	int	i;

	i = 0;
	while (tmp[j][i] != '\0')
	{
		if ((tmp[j][i] < 'A' || tmp[j][i] > 'Z') &&
			(tmp[j][i] < 'a' || tmp[j][i] > 'z'))
			break ;
		i++;
	}
	if (tmp[j][i] == '\0')
	{
		j++;
		return (0);
	}
	return (1);
}



int	check_correct_int(char **tmp, int j)
{
	int		i;

	i = 0;
	while (tmp[j][i] != '\0')
	{
		if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
				tmp[j][i] != '-' && tmp[j][i] != '+' &&
				tmp[j][i] != ',')
			return (1);
		i++;
	}
	if(check_signe(tmp[j]))
		return(1);
	j++;
	return (0);
}

int	check_correct_float(char **tmp, int j)
{
	int		i;

	i = 0;
	while (tmp[j][i] != '\0')
	{
		if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
			tmp[j][i] != '.' && tmp[j][i] != '-' &&
			tmp[j][i] != '+' && tmp[j][i] != ',')
			return (1);
		i++;
	}
	if (check_signe(tmp[j]))
		return(1);
	j++;
	return (0);
}
