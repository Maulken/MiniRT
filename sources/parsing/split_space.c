/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:14:57 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/21 17:13:13 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	count_substrs(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\t' && str[i])
				i++;
		}
		else if (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (count);
}

// count number of characters in substring starting at index 'i'
static int	get_substr_len(char const *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

static int	fill_arr(char **arr, char const *str)
{
	int	i;
	int	str_index;
	int	substr_len;

	i = 0;
	str_index = 0;
	substr_len = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		substr_len = get_substr_len(str, i);
		if (substr_len > 0)
		{
			arr[str_index] = malloc(sizeof(char) * (substr_len + 1));
			if (arr[str_index] == NULL)
				return (ft_free_str_arr(arr), -1);
			ft_strlcpy(arr[str_index], &str[i], substr_len + 1);
			str_index++;
		}
		i += substr_len;
	}
	return (0);
}

// split string 'str' into substrings using char 'c' as delimiter
// return array of substrings with NULL ending if successful, NULL if fails
char	**ft_split_espace(char const *str)
{
	int		substrs;
	char	**arr;

	if (str == NULL)
		return (NULL);
	substrs = count_substrs(str);
	arr = (char **)malloc((substrs + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[substrs] = NULL;
	if (substrs == 0)
		return (arr);
	if (fill_arr(arr, str) == -1)
		return (NULL);
	return (arr);
}
