/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:26:39 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/23 16:58:05 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	check_last_char(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i == 0)
		return ('\0');
	if (str[i - 1] != '\n')
		return ('\0');
	return ('\n');
}

void	delete_comment(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			str[i] = '\n';
			str[i + 1] = '\0';
			break ;
		}
	}
}

char	*get_string(int fd)
{
	char	*tmp;
	char	*str;

	tmp = malloc(1);
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	while (1)
	{
		str = get_next_line(fd);
		if (!str && *tmp)
			return (tmp);
		if (!str && !*tmp)
			return (free(tmp), NULL);
		delete_comment(str);
		str = ft_strjoin_free(tmp, str);
		if (!str)
			return (NULL);
		if (check_last_char(str) == '\0')
			return (str);
		tmp = str;
	}
}

char	**checkget_file_content(int fd)
{
	char	*str;
	char	**rows;

	str = get_string(fd);
	if (!str)
	{
		printf("ERROR1 : Malloc returned empty rows or"
			" no space left in memory.\n");
		close(fd);
		return (NULL);
	}
	close(fd);
	rows = ft_split(str, '\n');
	if (!rows)
	{
		printf("ERROR2 : Malloc returned empty rows or"
			" no space left in memory.\n");
		free(str);
		exit(1);
	}
	free(str);
	return (rows);
}
