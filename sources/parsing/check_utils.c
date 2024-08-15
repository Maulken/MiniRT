/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:32:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/14 14:27:00 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


static int ft_is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static int ft_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}



static int count_words(const char *phrase)
{
    int count = 0;
    int in_word = 0;

    while (*phrase != '\0')
    {
        if (ft_is_space(*phrase))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        phrase++;
    }

    return count;
}


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
        if(len == 0)
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
                len = 1;
            }
            while (tab[i] != ' ' && tab[i] != '\t' && tab[i] != '\0')
            {
                if ((tab[i] < '0' || tab[i] > '9') && tab[i] != '.' && tab[i] != ',' && tab[i] != '-' && tab[i] != '\n')
                {
                    printf("why to carathre plese IS NUMBER : {%c} ", tab[i]);
                    return 1;
                }
               i++;
            } 
            while (tab[i] == ' ' || tab[i] == '\t') {
                i++;}
    }
    if(count_words(tab) != size_setting)
    {
        printf("ERROR pas assez ou trop de parametre dans un object \n");
        return 1;
    }
    return 0;
}


double ft_atof_custom(const char *str)
{
    double result = 0.0;
    int sign = 1;
    int decimal_point = 0;
    double fraction = 1.0;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    while (ft_is_digit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
    { 
        if(decimal_point == 1 )
            return(1);
        str++;
        decimal_point = 1;
    }
    while (ft_is_digit(*str))
    {
        result = result * 10 + (*str - '0');
        fraction *= 10;
        str++;
    }
    if (decimal_point)
    {
        result /= fraction;
    }

    return sign * result;
}
