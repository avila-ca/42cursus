/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:04:24 by avila-ca          #+#    #+#             */
/*   Updated: 2022/07/21 17:32:24 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	check_char(va_list args)
{
	int	c;
	int	count;

	count = 0;
	c = va_arg(args, int);
	count = ft_put_char(c);
	return (count);
}

int	check_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	check_nbr(va_list args)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(args, int);
	count = put_nbr(n);
	return (count);
}

int	put_nbr(int n)
{
	int	count;
	int	nbr;

	count = 0;
	if (n == -2147483648)
	{
		return (write (1, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += ft_put_char('-');
		n = n * -1;
	}
	if (n < 10)
	{
		count += ft_put_char(n + 48);
	}
	else if ((10 <= n) && (n <= 2147483647))
	{
		count += put_nbr(n / 10);
		count += put_nbr(n % 10);
	}
	return (count);
}

int	put_u_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count += ft_put_char(n + 48);
	}
	else if ((10 <= n) && (n <= 4294967295))
	{
		count += put_u_nbr(n / 10);
		count += put_nbr(n % 10);
	}
	return (count);
}
