/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:59:28 by bszabo            #+#    #+#             */
/*   Updated: 2024/07/17 11:42:22 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count number of substrings in string 'str' separated by char 'c'
static int	count_substrs(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

// count number of characters in substring starting at index 'i'
static int	get_substr_len(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

// fill 'arr' array with substrings
// return 0 if successful, -1 if malloc fails
static int	fill_arr(char **arr, char const *str, char c)
{
	int	i;
	int	str_index;
	int	substr_len;

	i = 0;
	str_index = 0;
	substr_len = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		substr_len = get_substr_len(str, c, i);
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
char	**ft_split(char const *str, char c)
{
	int		substrs;
	char	**arr;

	if (str == NULL)
		return (NULL);
	substrs = count_substrs(str, c);
	arr = (char **)malloc((substrs + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[substrs] = NULL;
	if (substrs == 0)
		return (arr);
	if (fill_arr(arr, str, c) == -1)
		return (NULL);
	return (arr);
}
