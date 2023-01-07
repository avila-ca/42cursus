/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:58:09 by avila-ca          #+#    #+#             */
/*   Updated: 2022/06/28 19:08:24 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joiner(char *store, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!store)
	{
		store = malloc(sizeof(char) * 1);
		store[0] = '\0';
	}
	if (!store || !buf)
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen(store) + ft_strlen(buf) + 2));
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
	s = (char *)malloc(sizeof(char) * i + 2);
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
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = NULL;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i + 1] || !store)
	{
		free(store);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(store) - i + 1);
	if (!s)
		return (NULL);
	while (store[++i])
		s[j++] = store[i];
	s[j] = '\0';
	free(store);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	store = reader(fd, buf, store);
	if (check_n(store))
	{
		line = get_line(store);
		store = get_store(store);
	}
	else
	{
		line = store;
		store = NULL;
	}
	return (line);
}
