/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:53:31 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 20:13:11 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int ft_strdigit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) == 0 && str[i] != ',')
			return(ERROR);
		i++;
	}
	return(OK);
}
