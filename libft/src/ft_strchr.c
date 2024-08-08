/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:16:28 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:17:43 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if string 'str' contains char 'c'
// return pointer to first occurrence of 'c' in 'str', or NULL if not found
char	*ft_strchr(const char *str, int c)
{
	unsigned char	c_c;

	c_c = (unsigned char)c;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (c_c == *str)
			return ((char *)str);
		str++;
	}
	if (c_c == '\0')
		return ((char *)str);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char str[] = "hello world";
    char *res1 = ft_strchr(str, 'l');
    char *res2 = ft_strchr(str, 'x');
    char *res3 = ft_strchr(str, '\0');
	char *res4 = ft_strchr(str, 'h' - 256);
    printf("str: %s\n", str);
    printf("first l: %s\n", res1);
    printf("first x: %s\n", res2);
    printf("\\0: %s\n", res3);
	printf("h - 256: %s\n", res4);
    return (0);
}
*/
