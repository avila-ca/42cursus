/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:33:57 by avila-ca          #+#    #+#             */
/*   Updated: 2022/06/14 17:33:16 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>

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

void	get_sig(int sig)
{
	static char	c = 0;
	static int	i = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 0;
	else
		c = c | 1;
	i++;
	if (i >= 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*strpid;

	pid = getpid();
	strpid = ft_itoa(pid);
	write(1, strpid, 5);
	free(strpid);
	signal(SIGUSR1, &get_sig);
	signal(SIGUSR2, &get_sig);
	write(1, "\n", 1);
	while (1)
	{
		pause ();
	}
	return (0);
}
