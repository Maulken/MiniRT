/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:30:22 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/11 16:24:08 by vharatyk         ###   ########.fr       */
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

static int  get_str_len(char const *str)
{
    int count = 0;
    int len_vir = 0;
    int i = 0;
    
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            count++;
            while (str[i] != ' ' && str[i] != '\t' && str[i])
            {
                if (str[i] == ',')
                {
                    len_vir = 0;
                    while (len_vir != 3 && str[i])
                    {
                        if (str[i] == ',')
                        {
                            len_vir++;  
                            i++;
                        }
                        else
                        {
                            i++;
                        }
                    }
                    printf("\n");
                }
                i++;
                
            }
            i++;
            printf("]");
        }
    }
    return (count);
}




char **ft_split_line(char *tab)
{
	char **tab_split;
	int i = 0 ;
	int len = 0;
	
	printf("tab %s\n", tab);
	len = get_str_len(tab);
	printf("len %d\n", len);
	tab_split = malloc(sizeof(char) * (len + 1));
	i++;


	return (NULL);
}