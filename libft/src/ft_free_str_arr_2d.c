/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:46:56 by bszabo            #+#    #+#             */
/*   Updated: 2024/03/24 16:48:27 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// free all allocated memory in a 2d string array
// example: char **arr = {{ls, -l}, {grep, a}}
void	ft_free_str_arr_2d(char ***arr)
{
	int	i;
	int	j;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			free(arr[i][j]);
			j++;
		}
		free(arr[i]);
		i++;
	}
	free(arr);
}
