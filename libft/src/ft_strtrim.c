/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:53:21 by bszabo            #+#    #+#             */
/*   Updated: 2024/07/18 11:31:20 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return 1 if 'c' is in 'set', 0 otherwise
static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

// calculate the start index and the length of the trimmed string
static void	calc_trim(int *start, int *cpylen, char const *s1, char const *set)
{
	int	strlen;
	int	i;

	strlen = (int)ft_strlen(s1);
	i = 0;
	while (is_in_set(s1[i], set))
		i++;
	if (i == strlen)
	{
		*start = 0;
		*cpylen = 0;
		return ;
	}
	*start = i;
	i = 0;
	while (is_in_set(s1[strlen - i - 1], set))
		i++;
	*cpylen = (strlen - i) - *start;
}

// remove 'set' characters from the beginning and the end of 's1'
// return a copy of the trimmed string using malloc
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		cpylen;
	char	*cpy;
	int		i;

	start = 0;
	cpylen = 0;
	i = 0;
	if (!s1)
		return (NULL);
	calc_trim(&start, &cpylen, s1, set);
	cpy = (char *)malloc((cpylen + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (i < cpylen)
	{
		cpy[i] = s1[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
