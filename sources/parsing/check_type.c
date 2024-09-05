/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:30 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/05 09:35:08 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_correct_intxyz(char **tmp, int j)
{
	int		i;
	char	**tab;

	if(tmp[j][0] == '-' || tmp[j][0] == '+')
	{
		i = 1;
	}
	i = 0;
	while (tmp[j][i] != '\0')
	{
		printf
		if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
			tmp[j][i] != ',')
			return (1);
		if (tmp[j][i] == '-' || tmp[j][i] == '+')
            return 1;
		i++;
	}
	tab = ft_split(tmp[j], ',');
	if (size_tab(tab) != 3)
	{
		free_tab(tab);
		return (1);
	}
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
	if (size_tab(tab) != 3 || check_float_point(tab))
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
	j++;
	return (0);
}
