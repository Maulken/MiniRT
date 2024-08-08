/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:44:03 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/10 10:51:50 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if s1 and s2 are valid
// return 0 if valid, otherwise return -1
static int	check_strs(char *s1, char *s2)
{
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (-1);
	return (0);
}

// join s1 and s2 into a new string with malloc and return it
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s_final;

	i = -1;
	j = 0;
	if (check_strs(s1, s2) == -1)
		return (NULL);
	s_final = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (s_final == NULL)
		return (NULL);
	while (s1[++i])
		s_final[i] = s1[i];
	while (s2[j])
		s_final[i++] = s2[j++];
	s_final[i] = '\0';
	return (s_final);
}

/*
#include <stdio.h>
int main(void)
{
	char *s1 = "hello";
	char *s2 = "World";
	char *res = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, res);
	printf("    s1 memory: %p\nresult memory: %p\n", (void *)&s1, (void *)&s2);
	free(res);
	return (0);
}
*/
