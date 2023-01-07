/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:39:27 by avila-ca          #+#    #+#             */
/*   Updated: 2022/04/24 10:21:05 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*joiner(char *store, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!store)
	{
		store = (char *)malloc(sizeof(char) * 1);
		store[0] = '\0';
	}
	if (!store || !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(store) + ft_strlen(buf) + 2));
	if (!str)
		return (NULL);
	while (store[++i])
		str[i] = store[i];
	while (buf[++j])
		str[i + j] = buf[j];
	str[i + j] = '\0';
	free (store);
	return (str);
}

char	*reader(int fd, char *buf, char *store)
{
	int	read_byte;

	read_byte = 1;
	while (read_byte > 0 && !check_n(store))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(store);
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		if (read_byte == 0)
			buf[read_byte] = '\0';
		else
			store = joiner(store, buf);
	}
	free(buf);
	return (store);
}

char	*get_line(char *store)
{
	int		i;
	char	*s;

	i = 0;
	if (!store)
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	s = malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (store[i] != '\n')
	{
		s[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		s[i] = store[i];
	i++;
	s[i] = '\0';
	return (s);
}

char	*get_store(char *store)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i + 1])
	{
		free(store);
		free(s);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(store) - i);
	if (!s)
		return (NULL);
	s = storing(s, store, i);
	free(store);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*store[255];
	char		*buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	store[fd] = reader(fd, buf, store[fd]);
	if (check_n(store[fd]))-
	{
		line = get_line(store[fd]);
		store[fd] = get_store(store[fd]);
	}
	else
	{
		line = store[fd];
		store[fd] = NULL;
	}
	return (line);
}
