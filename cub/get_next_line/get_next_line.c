/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa <jsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:05:57 by jsousa            #+#    #+#             */
/*   Updated: 2021/04/22 20:51:09 by jsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	unsigned int	size;
	char			*dest;
	size_t			i;

	if (!str)
		return (0);
	size = ft_strlen(str);
	if (start >= size)
	{
		dest = malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	if (size < len)
		return (ft_strdup(str + start));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (start < size && i < len)
		dest[i++] = str[start++];
	dest[i] = '\0';
	return (dest);
}

int	ft_readfile(int fd, char *buffer, char **data_saved)
{
	int		rf;
	char	*temp;

	rf = read(fd, buffer, BUFFER_SIZE);
	if (rf < 0)
		return (-1);
	if (rf == 0)
		return (0);
	buffer[rf] = '\0';
	if (data_saved[fd] == 0)
		data_saved[fd] = ft_strdup("");
	temp = ft_strjoin(data_saved[fd], buffer);
	free(data_saved[fd]);
	data_saved[fd] = temp;
	if (data_saved[fd] == 0)
		return (-1);
	return (1);
}

int	ft_update(int fd, char **data_saved, char **line)
{
	char	*i;
	char	*temp;

	i = ft_strchr(data_saved[fd], '\n');
	if (i)
	{
		*line = ft_substr(data_saved[fd], 0, i - data_saved[fd]);
		temp = ft_substr(i, 1, ft_strlen(data_saved[fd])
				- (i - data_saved[fd] + 1));
		free(data_saved[fd]);
		data_saved[fd] = temp;
		return (1);
	}
	else
	{
		if (data_saved[fd])
		{
			*line = ft_strdup(data_saved[fd]);
			free(data_saved[fd]);
			data_saved[fd] = 0;
		}
		else
			*line = ft_strdup("\0");
	}
	return (0);
}

/*
** ssize_t read(int fd, void *buf, size_t count);
** On success, the number of bytes read is returned (zero indicates
** end of file), and the file position is advanced by this number.
** It is not an error if this number is smaller than the number of
** bytes requested.
** On error, -1 is returned.
*/

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			status;
	static char	*data_saved[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (-1);
	status = 1;
	while (!ft_strchr(data_saved[fd], '\n') && status > 0)
		status = ft_readfile(fd, buffer, data_saved);
	if (status == -1)
		return (-1);
	else
		status = ft_update(fd, data_saved, line);
	return (status);
}
