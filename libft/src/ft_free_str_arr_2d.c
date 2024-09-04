/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:40 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/03 16:30:42 by vmassoli         ###   ########.fr       */
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
