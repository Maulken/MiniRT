/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:56:07 by bszabo            #+#    #+#             */
/*   Updated: 2024/03/27 15:41:52 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// replace first found 'old_s' substring with 'new_s' substring in 'str'
// start searching from index 'start_i'
// ft_strreplace("echo $USER'", "$USER", "username") -> "echo username'"
// it will free the original string 'str' and return a new string, or NULL
char	*ft_strreplace(char *str, char *old_s, char *new_s, int start_i)
{
	int		result_len;
	char	*ptr;
	char	*result;

	result_len = ft_strlen(str) - ft_strlen(old_s) + ft_strlen(new_s) + 1;
	ptr = ft_strnstr(str + start_i, old_s, ft_strlen(str));
	if (!ptr)
		return (NULL);
	result = (char *)malloc(result_len * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, ptr - str + 1);
	ft_strlcat(result, new_s, result_len);
	ft_strlcat(result, ptr + ft_strlen(old_s), result_len);
	free(str);
	str = NULL;
	return (result);
}

/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = strdup("echo \"$USER\'\"");
	char replace[] = "username";

	printf("Original string: %s\n", str);
	printf("Substring to replace: $USER\n");

	char *result = ft_strreplace(str, "$USER", replace, 0);
	if (result == NULL) {
		printf("Failed to replace. Memory allocation error.\n");
		return 1;
	}

	printf("Modified string: %s\n", result);

	free(result); // Free the memory allocated by ft_strreplace

	return 0;
}
*/