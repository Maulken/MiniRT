/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:31:38 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/03 16:31:48 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int c = 'j';
	int c2 = '5';
	int res = ft_isalpha(c);
	int res2 = ft_isalpha(c2);
	printf("%c | %d\n", c, res);
	printf("%c | %d\n", c2, res2);
	return (0);
}
*/
