/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/11 16:53:10 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_num(char *tab, char *str, int size_setting)
{
    int i;
    int len;
    int j;

    j = 0;
    i = 0;
    len = 0;


    while(tab[i] != '\0')
    {
        while(tab[i] == ' ' || tab[i] == '\t')
            i++;
        while(tab[i] <= '0' && tab[i] >= '9')
        {
            if(len == 0)
            {
                while(str[j] != '\0' && tab[i] != '\0')
                {
                    if(str[j] != tab[i])
                        return 1; 
                    i++;
                    j++;
                }
               
            }
            if ((tab[i] < '0' || tab[i] > '9') && tab[i] != '.' && tab[i] != ',' && tab[i] != ' ' && tab[i] != '-')
            {
                printf("why : %c ", tab[i]);
                return 1; 
            }
            i++;
        }
        len++;
        i++;
    }
    if(len != size_setting)
    {
        printf("error trop de parametre ou char dans le int : %d \n", len);
        return 1;
    }
    return 0;
}


int check_correct_type(char *content, char *tab)
{
    char **tmp = ft_split(tab, ' ');
    int i;
    int j;

    j = 0;
    while (tmp[j])
    {
        i = 0;
        // Vérification des entiers
        if (content[j] == 'i')
        {
            while (tmp[j][i] != '\0') {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') && tmp[j][i] != '-' && tmp[j][i] != '+')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0') {
                j++;
                continue;
            }
        }
        // Vérification des flottants
        if (content[j] == 'f')
        {
            i = 0;
            while (tmp[j][i] != '\0') {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') && tmp[j][i] != '.' && tmp[j][i] != '-' && tmp[j][i] != '+')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0') {
                j++;
                continue;
            }
        }
        // Vérification des caractères
        if (content[j] == 'c')
        {
            i = 0;
            while (tmp[j][i] != '\0') {
                if ((tmp[j][i] < 'A' || tmp[j][i] > 'Z') && (tmp[j][i] < 'a' || tmp[j][i] > 'z'))
                    break;
                i++;
            }
            if (tmp[j][i] == '\0') {
                j++;
                continue;
            }
        }
        free(tmp);
        printf("plese??");
        return 1;
    }
    free(tmp);
    return 0;
 }


int check_a(char *tab)
{
    char **tmp;
    char content[6] = {'c','f','i','v','v','v'};

    if (check_num(tab, "A", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
    return(0);
}


int check_c(char *tab)
{
    char **tmp;
    char content[6] = {'c','f','f','i','v','v'};

    if (check_num(tab, "C", 4))
    {
        printf("error num is not");
        return (1);
    }
    if(check_correct_type(content, tab))
    {
        printf("error va chier");
    }
        return(1);
  return(0);
}

int check_l(char *tab)
{
char **tmp;
    char content[6] = {'c','f','f','i','v','v'};

    if (check_num(tab, "L", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
  return(0);
}
    
int check_sp(char *tab)
{
    char **tmp;
    char content[6] = {'c','f','f','i','v','v'};


    if (check_num(tab, "sp", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
  return(0);
}
int check_pl(char *tab)
{
    char **tmp;
    char content[6] = {'c','f','f','i','v','v'};

    if (check_num(tab, "pl", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
  return(0);
}

int check_cy(char *tab)
{
    char **tmp;
    char content[6] = {'c','f','f','f','f','i'};

    if (check_num(tab, "cy", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
    return(0);
}