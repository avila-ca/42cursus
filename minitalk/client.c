/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:24:04 by avila-ca          #+#    #+#             */
/*   Updated: 2022/08/23 10:40:07 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == 32) || ((9 <= str[i]) && (str[i] <= 13)))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == '-' && str[i++] == '-')
		sign *= -1;
	while ((48 <= str[i]) && (str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}

void	send_bits(int pid, char c)
{
	char	aux;
	int		i;
	int		kill_err;

	i = 0;
	while (i < 8)
	{
		aux = c >> 7;
		if (aux == 0x00)
		{
			kill_err = kill(pid, SIGUSR1);
			if (kill_err == -1)
				write(1, "error 0", 7);
		}
		else
		{
			kill_err = kill (pid, SIGUSR2);
			if (kill_err == -1)
				write (1, "error 1", 7);
		}
		c = c << 1;
		i++;
		usleep(300);
	}
}

int	main(int num, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (num != 3)
	{
		write (1, "error arg", 9);
		return (0);
	}
	pid = ft_atoi (argv[1]);
	if (pid < 1)
	{
		write(1, "error pid", 9);
		exit (0);
	}
	str = argv[2];
	while (str[i])
	{
		send_bits(pid, str[i]);
		i++;
	}
	return (0);
}	
