/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:57:59 by vmassoli          #+#    #+#             */
/*   Updated: 2024/07/17 12:16:39 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// concatenate 's1' and 's2' into a new string and return a pointer to it
static char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	free(s1);
	return (str);
}

// read from 'fd' into 'line' until a newline is reached
// return 0 if successful, -1 if an error occurred
static int	read_line(int fd, char **line, char buffer[BUFFER_SIZE + 1])
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buffer[bytes_read] = '\0';
		*line = gnl_strjoin(*line, buffer);
	}
	if (ft_strlen(*line) == 0)
		return (-1);
	return (0);
}

// cpy the 'next_line' into 'buffer' and correctly null-terminate 'line'
static void	set_next_line(char *line, char buffer[BUFFER_SIZE + 1])
{
	char	*next_line;
	int		line_end;

	next_line = ft_strchr(line, '\n');
	if (next_line)
	{
		line_end = next_line - line + 1;
		ft_strlcpy(buffer, next_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		line_end = ft_strlen(line);
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1);
	}
	line[line_end] = '\0';
}

// read from 'fd' and return a line from the file
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = ft_strdup(buffer);
	if (read_line(fd, &line, buffer) == -1)
		return (free(line), NULL);
	set_next_line(line, buffer);
	return (line);
}
