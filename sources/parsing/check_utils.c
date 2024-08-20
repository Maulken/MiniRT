/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:32:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 10:13:57 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_good_char(char c)
{
	return ((c < '0' || c > '9')
		&& c != '.' && c != ',' && c != '-' && c != '\n');
}

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
	int	in_word;

	i = 0;
	len = 0;
	in_word = 0;
	while (tab[i] != '\0')
	{
		i = check_num_str(tab, str, i, len);
		len = 1;
		if (i == -1)
			return (0);
		while (tab[i] != ' ' && tab[i] != '\t' && tab[i] != '\0')
		{
			if (ft_is_good_char(tab[i]))
				ft_msg_error("why to carathre plese IS NUMBER", 1);
			i++;
		}
		while (tab[i] == ' ' || tab[i] == '\t')
			i++;
	}
	if (count_words(tab) != size_setting)
		ft_msg_error("ERROR pas assez ou trop de parametre dans un object", 1);
	return (0);
}
