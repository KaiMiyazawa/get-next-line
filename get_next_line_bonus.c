/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:37:53 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:21:31 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_save(int fd, char *save)
{
	char	*buffer;
	int		read_size;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_size = 1;
	while (!ft_strchr(save, '\n') && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*make_line(char *save)
{
	int		count;
	char	*result;

	count = 0;
	if (!save[count])
		return (NULL);
	while (save[count] != '\n' && save[count])
		count++;
	result = ft_calloc(count + 2, sizeof(char));
	if (!result)
	{
		free(save);
		return (NULL);
	}
	count = 0;
	while (save[count] != '\n' && save[count])
	{
		result[count] = save[count];
		count++;
	}
	if (save[count] == '\n')
		result[count] = '\n';
	return (result);
}

char	*trim_save(char *save)
{
	int		count;
	int		count2;
	char	*next_save;

	count = 0;
	while (save[count] != '\n' && save[count])
		count++;
	if (!save[count])
	{
		free(save);
		return (NULL);
	}
	next_save = ft_calloc(ft_strlen(save) - count + 1, sizeof(char));
	if (!next_save)
	{
		free(save);
		return (NULL);
	}
	count2 = 0;
	count++;
	while (save[count])
		next_save[count2++] = save[count++];
	free(save);
	return (next_save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	save[fd] = make_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = make_line(save[fd]);
	save[fd] = trim_save(save[fd]);
	return (line);
}
