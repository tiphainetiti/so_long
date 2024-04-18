/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:37:16 by tlay              #+#    #+#             */
/*   Updated: 2024/03/20 13:19:07 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer(int fd, char *buffer, char *remaining_buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remaining_buffer)
			remaining_buffer = ft_strdup("");
		tmp = remaining_buffer;
		remaining_buffer = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), remaining_buffer);
}

char	*get_line(char *actual_buffer)
{
	char	*line;
	int		i;
	int		eol;

	line = NULL;
	i = 0;
	eol = 0;
	while (actual_buffer[eol] != '\n' && actual_buffer[eol] != '\0')
		eol++;
	if (actual_buffer[eol] == '\n')
		eol++;
	line = ft_substr(actual_buffer, i, eol);
	return (line);
}

static char	*substract_of_buffer(char *actual_buffer, char *line)
{
	char	*remaining_buffer;
	int		eob;
	int		eol;

	eob = ft_strlen(actual_buffer);
	eol = ft_strlen(line);
	remaining_buffer = ft_substr(actual_buffer, eol, eob);
	if (!remaining_buffer)
		return (free(actual_buffer), NULL);
	if (remaining_buffer[0] == '\0')
	{
		free(remaining_buffer);
		return (free(actual_buffer), NULL);
	}
	return (free(actual_buffer), remaining_buffer);
}

char	*get_next_line(int fd)
{
	static char	*remaining_buffer[MAX_FD];
	char		*buffer;
	char		*line;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(buffer);
		free(remaining_buffer[fd]);
		buffer = NULL;
		remaining_buffer[fd] = NULL;
		return (NULL);
	}
	buffer = update_buffer(fd, buffer, remaining_buffer[fd]);
	if (!buffer)
		return (free(buffer), NULL);
	line = get_line(buffer);
	if (!line)
		return (NULL);
	remaining_buffer[fd] = substract_of_buffer(buffer, line);
	return (line);
}

//#include <stdio.h>

// int	main(void)
//{
//	int		fd;
//	char	*line;

//	fd = open("test1", O_RDONLY);
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (!line)
//			break ;
//		printf("%s", line);
//		free(line);
//	}
//	return (0);
//}
