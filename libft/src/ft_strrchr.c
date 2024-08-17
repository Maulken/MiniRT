/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:19:14 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:21:50 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find the last occurrence of the character 'c' in the string 'str'
// return a pointer to the located character or NULL if not found
char	*ft_strrchr(const char *str, int c)
{
	char			*temp;
	unsigned char	c_c;

	temp = 0;
	c_c = (unsigned char)c;
	while (*str)
	{
		if (c_c == *str)
			temp = (char *)str;
		str++;
	}
	if (c_c == '\0')
		return ((char *)str);
	return (temp);
}
/*
#include <stdio.h>
int main(void)
{
    char str[] = "hello world";
    char *res1 = ft_strrchr(str, 'l');
    char *res2 = ft_strrchr(str, 'x');
    printf("last l: %s\n", res1);
    printf("last x: %s\n", res2);
    return (0);
}
*/
