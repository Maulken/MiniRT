/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:55:42 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:01:23 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// scan 'n' bytes from beginning of 'ptr' for first occurrence of 'c'
// return pointer to the matching byte or NULL if no match
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*c_ptr;

	c_ptr = (unsigned char *)ptr;
	while (n > 0)
	{
		if (*c_ptr == (unsigned char)c)
			return ((void *)c_ptr);
		c_ptr++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "hello world";
    char *res1o = memchr(str, 'o', 11);
    char *res1 = ft_memchr(str, 'o', 11);
    char *res2o = memchr(str, 'w', 6);
    char *res2 = ft_memchr(str, 'w', 6);
    printf("%s | original\n", res1o);
    printf("%s\n", res1);
    printf("%s | original\n", res2o);
    printf("%s\n", res2);
    return (0);
}
*/
