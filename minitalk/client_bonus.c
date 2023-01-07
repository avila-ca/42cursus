/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:37:19 by avila-ca          #+#    #+#             */
/*   Updated: 2022/08/23 10:05:35 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>

int counter = 0;
int	ft_counter(int n)
{
	long long int	nbr;
	int				i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr = (long long int)n * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			mag;
	long int	nbr;

	nbr = n;
	mag = ft_counter(n);
	if (mag == 0)
		mag = 1;
	dest = (char *)malloc(mag + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	dest[mag--] = '\0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	while (mag >= 0)
	{
		dest[mag--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

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
			kill_err = kill(pid, SIGUSR2);
			if (kill_err == -1)
				write(1, "error 1", 7);
		}
		c = c << 1;
		i++;
		usleep(350);
	}
}

void	feedback(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, " signal recived: 0\n", 19);
		counter++;
	}
	else if (sig == SIGUSR2)
	{
		write(1, " signal recived: 1\n", 19);
		counter++;
	}
}	

int	main(int num, char *argv[])
{
	int		pid;
	int		i;
	
	char *count;
	i = 0;
	if (num != 3)
	{
		write(1, "error arg", 9);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		write(1, "error pid", 9);
		exit (0);
	}
	//if (i == 0)
		signal(SIGUSR1, &feedback);
		signal(SIGUSR2, &feedback);
	while (argv[2][i])
		send_bits(pid, argv[2][i++]);
	if (!argv[2][i])
	{
		send_bits(pid, argv[2][i]);
		write(1, "signals received: ", 18);
		count = ft_itoa(counter);
	}
	return (0);
}
