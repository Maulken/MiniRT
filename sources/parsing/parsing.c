/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:30:22 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/25 16:03:29 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parsing(int argc, char **argv, t_data *data)
{
	char	**tab;

	data->fd = check_argument(argc, argv);
	if (data->fd == -1)
		return (ERROR);
	tab = checkget_file_content(data->fd);
	if (check_tab(tab, data))
		return (ERROR);
	free_tab(tab);
	printf("OK Parsing\n\n");
	return (OK);
}

char	*remouve_space_cord(char *tab)
{
	char	*tab_split;
	int		j;
	int		k;

	j = 0;
	tab_split = ft_calloc(ft_strlen(tab) + 1, sizeof(char));
	k = 0;
	while (tab[j] != '\0')
	{
		if (tab[j] == ',')
		{
			while (k > 0 && (tab_split[k - 1] == ' '
					|| tab_split[k - 1] == '\t'))
				k--;
			tab_split[k++] = tab[j];
			while (tab[j + 1] == ' ' || tab[j + 1] == '\t')
				j++;
		}
		else
			tab_split[k++] = tab[j];
		j++;
	}
	tab_split[k] = '\0';
	return (tab_split);
}
