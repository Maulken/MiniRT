/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:37 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/04 14:54:53 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the character is a digit
// return 1 if true, 0 if false
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int c = '9';
	int c2 = 'e';
	int res = ft_isdigit(c);
	int res2 = ft_isdigit(c2);
	printf("%c | %d\n", c, res);
	printf("%c | %d\n", c2, res2);
	return (0);
}
*/
