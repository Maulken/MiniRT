/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:59:37 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/12 10:01:28 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apply the function 'f' to each character of the string 's'
// to create a new string and return it
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
char	odd_tounderscore(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ('_');
	return (c);
}

int main(void)
{
	char *s = "guess what 12345";
	char *res = ft_strmapi(s, odd_tounderscore);
	printf("%s\n", s);
	printf("%s\n", res);
	free(res);
	return (0);
}
*/
