/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:00:31 by avila-ca          #+#    #+#             */
/*   Updated: 2022/07/25 10:48:31 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			check_n(char *store);
int			ft_count_nl(char *s);
char		*joiner(char *store, char *buf);
char		*reader(int fd, char *buf, char *store);
char		*get_line(char *store);
char		*get_store(char *store);

#endif
