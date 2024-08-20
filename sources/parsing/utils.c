/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:59 by viktor            #+#    #+#             */
/*   Updated: 2024/08/20 14:03:11 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

void	printf_row(char **row)
{
	int	i;
	int	j;

	j = 0;
	while (row[j])
	{
		i = 0;
		while (row[j][i])
			printf("%c", row[j][i++]);
		j++;
		printf("\n\n");
	}
	printf("\n");
}

int	size_tab(char **tab)
{
	int	j;

	j = 0;
	if (tab == NULL || *tab == NULL)
		return (0);
	while (tab[j])
		j++;
	return (j);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_float_point(char **tab)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	j = 0;
	value = 0;
	while (tab[j])
	{
		while (tab[j][i] != '\0')
		{
			if (tab[j][i] == '.')
			{
				if (value == 0)
					value = 1;
				else
					return (1);
			}
			i++;
		}
		i = 0;
		value = 0;
		j++;
	}
	return (0);
}
