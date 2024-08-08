/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:39:18 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 13:31:24 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate the first occurrence of the string 'str_sm' in 'str_lg'
// where not more than 'n' characters are searched
// return a pointer to the located string or NULL if not found
char	*ft_strnstr(const char *str_lg, const char *str_sm, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str_sm[0] == '\0')
		return ((char *)str_lg);
	while (i < n && str_lg[i])
	{
		while ((str_lg[i] == str_sm[j]) && str_lg[i] && i < n)
		{
			i++;
			j++;
			if (str_sm[j] == '\0')
				return ((char *)str_lg + i - j);
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char lg[] = "hellolor world";
	char sm[] = "lo";

	char *res = ft_strnstr(lg, sm, 30);
	printf("lg: %s | sm: %s | result: %s\n", lg, sm, res);

	char sm2[] = "orl";
	char *res2 = ft_strnstr(lg, sm2, 30);
	printf("lg: %s | sm: %s | result: %s\n", lg, sm2, res2);

	char *res3 = ft_strnstr(lg, sm, 4);
	printf("lg: %s | sm: %s | result: %s\n", lg, sm, res3);

	char *res4 = ft_strnstr(lg, "", 10);
	printf("lg: %s | sm: %s | result: %s\n", lg, "", res4);

	char *res5 = ft_strnstr("", sm, 10);
	printf("lg: %s | sm: %s | result: %s\n", "", sm, res5);
	return (0);
}
*/
