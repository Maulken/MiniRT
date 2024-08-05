/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:43:01 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/08 14:10:02 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicate string 's' in memory using malloc
// return pointer to new string
char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = "hello world";
	char *dup = ft_strdup(s);
	printf("s: %s | memory: %p\n", s, (void *)s);
	printf("dup: %s | memory: %p\n", dup, (void *)dup);
	free(dup);
	return (0);
}
*/
