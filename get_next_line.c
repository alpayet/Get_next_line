/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:59:45 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/16 22:30:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_first_line(char buffer[BUFFER_SIZE + 1], char *buffer_stor)
{
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	while (buffer_stor[i] != '\n')
		i++;
	line = ft_substr(buffer_stor, 0, i + 1);
	free(buffer_stor);
	buffer_stor = NULL;
	if (!line)
		return (NULL);
	ft_memcpy(buffer, ft_strchr(buffer, '\n') + 1,
		ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
	return (line);
}

char *check_bytes_read(ssize_t bytes_read, char	*buffer_stor)
{
	if (bytes_read == 0)
	{
		if (buffer_stor[0] == '\0')
		{
			free(buffer_stor);
			return (NULL);
		}
		return (buffer_stor);
	}
	free(buffer_stor);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*buffer_stor;
	ssize_t		bytes_read;

	buffer_stor = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (1)
	{
		buffer_stor = ft_strjoin_alt(buffer_stor, buffer);
		if (buffer_stor == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			return (ft_first_line(buffer, buffer_stor));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			buffer[0] = '\0';
		else
			buffer[bytes_read] = '\0';
		if (bytes_read <= 0)
			return (check_bytes_read(bytes_read, buffer_stor));
	}
}

/* int	main(void)
{
	int		fd;
	char	*str;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erreur d'ouverture\n", 19);
		return (1);
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("line: %s\n", str);
		free(str);
		str = get_next_line(fd);
		if (!str)
			printf("EOF\n");
	}
	close(fd);
	return (0);
} */
