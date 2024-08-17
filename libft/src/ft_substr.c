/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:33:50 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/08 15:51:56 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return substring from 'str' starting at index 'start' and of length 'len'
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	if (*str == '\0')
		len = 0;
	if (start > ft_strlen(str))
		len = 0;
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (str[i] && len--)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "hello world";
	char *substr = ft_substr(str, 4, 3);
	printf("str: %s\nsubstr: %s\n", str, substr);
	free(substr);
	return (0);
}
*/
