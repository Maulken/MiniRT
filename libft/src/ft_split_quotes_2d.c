/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:34:43 by bszabo            #+#    #+#             */
/*   Updated: 2024/05/06 14:20:12 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// split an array of strings by a character
// return a 2d array of strings, or NULL if malloc fails
char	***ft_split_quotes_2d(char **arr, char c)
{
	char	***split;
	int		i;

	split = malloc(sizeof(char **) * (ft_arrlen(arr) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		split[i] = ft_split_quotes(arr[i], c);
		if (!split[i])
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
