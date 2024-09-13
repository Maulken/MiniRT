/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:34:47 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:34:49 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
