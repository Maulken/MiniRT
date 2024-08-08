/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:48:51 by bszabo            #+#    #+#             */
/*   Updated: 2024/05/06 14:19:57 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicate array of strings 'arr' in memory, last element is NULL
// return pointer to new array, NULL if malloc fails
char	**ft_strdup_arr(char *arr[])
{
	int		i;
	char	**dup;

	i = 0;
	while (arr[i])
		i++;
	dup = (char **)malloc((i + 1) * sizeof(char *));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_strdup(arr[i]);
		if (dup[i] == NULL)
			return (NULL);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
