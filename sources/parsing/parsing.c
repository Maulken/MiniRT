/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:30:22 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/12 14:12:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int parsing(int argc , char **argv, t_data *data)
{
	char *line;
	char **tab;
	int i;


	data->fd = check_argument(argc , argv); // check file user
	if(data->fd == -1)
		return(ERROR);

	tab = checkget_file_content(data->fd); // get file + verifacation de la taille
	if (check_tab(tab ,data))
		return(ERROR);
	
	if(create_scenes_getinfo(tab , data ))
		return(ERROR);
	
	printf_row(tab);

	
	return(OK);
}
