/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:56:17 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/08 16:04:00 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void ft_putnbr_fd(int n, int fd);

int main (void)
{
ft_putnbr_fd(5555, 1);
	return(0);
}
