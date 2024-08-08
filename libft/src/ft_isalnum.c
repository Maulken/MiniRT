/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:35:26 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/05 11:37:19 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the character is a digit or a letter
// return 1 if true, 0 if false
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int c1 = '5';
	int c2 = 't';
	int c3 = 'E';
	int c4 = '!';
	int res1 = ft_isalnum(c1);
	int res2 = ft_isalnum(c2);
	int res3 = ft_isalnum(c3);
	int res4 = ft_isalnum(c4);
	printf("%c | %d\n", c1, res1);
	printf("%c | %d\n", c2, res2);
	printf("%c | %d\n", c3, res3);
	printf("%c | %d\n", c4, res4);
	return (0);
}
*/