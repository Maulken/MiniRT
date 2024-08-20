/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:59:54 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 14:18:09 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_msg_error(char *str, int value)
{
	printf("ERROR : %s", str);
	return (value);
}

int	ft_msg_error_tab(char *str, int value, char **tab )
{
	printf("plese ckeck : is not object\n");
	free_tab(tab);
	return (value);
}
