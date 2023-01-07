/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:10:27 by avila-ca          #+#    #+#             */
/*   Updated: 2022/03/05 17:45:38 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_hexlow(unsigned int n)
{
	int		count;
	char	*hex;
	char	h;

	count = 0;
	hex = "0123456789abcdef";
	if (n <= 15)
	{
		h = hex[n];
		count += write(1, &h, 1);
	}
	else if ((16 <= n) && (n <= 4294967295))
	{
		count += ft_put_hexlow(n / 16);
		count += ft_put_hexlow(n % 16);
	}
	return (count);
}

int	ft_put_hexup(unsigned int n)
{
	int		count;
	char	*hex;
	char	h;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n <= 15)
	{
		h = hex[n];
		count += write(1, &h, 1);
	}
	else if ((16 <= n) && (n <= 4294967295))
	{
		count += ft_put_hexup(n / 16);
		count += ft_put_hexup(n % 16);
	}
	return (count);
}

int	ft_put_ptr(unsigned long long n)
{
	int		count;
	char	*hex;
	char	h;

	hex = "0123456789abcdef";
	count = 0;
	if (n <= 15)
	{
		h = hex[n];
		count += write(1, &h, 1);
	}
	else if (16 <= n)
	{
		count += ft_put_ptr(n / 16);
		count += ft_put_ptr(n % 16);
	}
	return (count);
}
