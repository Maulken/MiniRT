/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:49:52 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/05 14:11:44 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// fill 'n' bytes of memory area 'str' with byte 'c'
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[10] = "test";
	char res[10] = "test";

	printf("before: %s\n", str);
	ft_memset(str + 2, '.', 5);
	memset(res + 2, '.', 5);
	printf("after: %s (expected: %s)\n", str, res);
	return (0);
}
*/