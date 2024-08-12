/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:59 by viktor            #+#    #+#             */
/*   Updated: 2024/08/12 14:59:19 by vharatyk         ###   ########.fr       */
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


void printf_row(char **row)
{
    int i;
    int j;

    j = 0;
    
    while(row[j])
    {
        i=0;
        while(row[j][i])
            printf("%c",row[j][i++]);
        j++;
        printf("\n\n");
    }
    printf("\n");

}

void print_objet_liste(t_scenes *scenes)
{

}

int size_tab(char **tab)
{
    int j; 

    j = 0;

    if (tab == NULL || *tab == NULL)
        return(0);
    while(tab[j])
    {
        j++;
    }
    return(j);

}