/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:59:54 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/21 15:28:10 by vharatyk         ###   ########.fr       */
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
	printf("%s %s\n",str,tab[0]);
	free_tab(tab);
	return (value);
}

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
