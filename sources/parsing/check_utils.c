/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:32:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 15:07:28 by viktor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	count_words(const char *phrase)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
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
	return (count);
}

static int	check_num_str(char *tab, char *str, int i, int len)
{
	int	j;

	j = 0;
	if (len == 0)
	{
		while (tab[i] == ' ')
			i++;
		while (str[j] != '\0' && tab [i] != '\0')
		{
			if (str[j] != tab[i])
				return (-1);
			i++;
			j++;
		}
	}
	return (i);
}

int	check_num(char *tab, char *str, int size_setting)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab[i] != '\0')
	{
		i = check_num_str(tab, str, i, len);
		len = 1;
		if (i == -1)
			return (0);
		while (tab[i] != ' ' && tab[i] != '\t' && tab[i] != '\0')
		{
			if (ft_is_good_char(tab[i]))
				return (ft_msg_error(" caracter in the line is not valid.", 1));
			i++;
		}
		while (tab[i] == ' ' || tab[i] == '\t')
			i++;
	}
	if (count_words(tab) != size_setting)
		return (ft_msg_error("There are either not enough or too many "
				"elements on the line.", 1));
	return (0);
}

int	check_signe(char *str)
{
	int	start_num;
	int	nb_signe;
	int	i;

	start_num = 0;
	nb_signe = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			start_num = 1;
		if (str[i] == '+' || str[i] == '-' )
		{
			nb_signe++;
			if (nb_signe == 2 || start_num == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_signe_tab(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
	{
		if (check_signe(tab[index]) == 1)
			return (1);
		index++;
	}
	return (0);
}
