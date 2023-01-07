/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:48:54 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:45 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	dest = (char *)ft_calloc(mag + 1, sizeof(char));
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
