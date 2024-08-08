/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:21:55 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/05 15:32:55 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// erase the data in the n bytes of the memory by writing zeroes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char s[10] = "testing";
	printf("before: %s\n", s);
	ft_bzero(s, 5);
	printf("after: %s\n", s);
	printf("%c", s[5]);
	return (0);
}
*/
