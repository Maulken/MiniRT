/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:24:32 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:35:35 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare the first 'n' characters of 'str1' and 'str2'
// return 0 if they are identical
// if 'str1' < 'str2' return negative number
// if 'str1' > 'str2' return positive number
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "hello";
    char str2[] = "hello world";
    char str3[] = "world";

    int res1o = strncmp("", str2, 5);
    int res1 = ft_strncmp("", str2, 5);
    printf("%d | original\n", res1o);
    printf("%d\n", res1);

    int res2o = strncmp(str1, str2, 10);
    int res2 = ft_strncmp(str1, str2, 10);
    printf("%d | original\n", res2o);
    printf("%d\n", res2);

    int res3o = strncmp(str1, str3, 5);
    int res3 = ft_strncmp(str1, str3, 5);
    printf("%d | original\n", res3o);
    printf("%d\n", res3);

    int res4o = strncmp(str3, str1, 5);
    int res4 = ft_strncmp(str3, str1, 5);
    printf("%d | original\n", res4o);
    printf("%d\n", res4);

    int res5o = strncmp("\200", "\0", 1);
    int res5 = ft_strncmp("\200", "\0", 1);
    printf("%d | original\n", res5o);
    printf("%d\n", res5);
    return (0);
}
*/
