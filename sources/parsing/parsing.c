/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:30:22 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/21 15:20:07 by vharatyk         ###   ########.fr       */
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
	printf("OK\n\n");
	return (OK);
}
