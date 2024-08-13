/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:32:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/13 22:41:13 by viktor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_num(char *tab, char *str, int size_setting)
{
    int i;
    int len;
    int j;
    int in_word;

    j = 0;
    i = 0;
    len = 0;
    in_word = 0 ;


    while(tab[i] != '\0')
    {
        if(tab[i] == ' ' || tab[i] == '\t')
        {
            i++;
            in_word = 0 ;
        }
        else if(!in_word)
        {
            in_word = 1;
            len++;

        }
        else if(len == 0)
            {
                while(tab[i] == ' ')
                    i++;
                while(str[j] != '\0' && tab [i] != '\0')
                {
                    if(str[j] != tab[i])
                            return 1;
                    i++;
                    j++;  
                } 
                len++;          
            }
        while(tab[i] <= 33 && tab[i] >= '~')
        {
            if ((tab[i] < '0' || tab[i] > '9') && tab[i] != '.' && tab[i] != ',' && tab[i] != ' ' && tab[i] != '-')
            {
                printf("why to carathre plese IS NUMBER : %c ", tab[i]);
                return 1; 
            }
            i++;
            in_word = 0;
        }
        i++;
    }
    if(len != size_setting)
    {
        printf("error trop ou pas asser de parametre ou char dans le int : %d \n", len);
        return 1;
    }
    return 0;
}
