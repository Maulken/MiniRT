/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:56 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/04 14:36:44 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the character is a letter
// return 1 if true, 0 if false
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