/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:42:35 by avila-ca          #+#    #+#             */
/*   Updated: 2022/03/05 17:42:59 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checking(const char *s, va_list args, int i)
{
	int	count;

	count = 0;
	if (s[i] == 'c')
		count = check_char(args);
	else if (s[i] == 's')
		count = check_str(args);
	else if (s[i] == 'd' || s[i] == 'i')
		count = check_nbr(args);
	else if (s[i] == 'x')
		count = ft_put_hexlow(va_arg(args, unsigned int));
	else if (s[i] == 'X')
		count = ft_put_hexup(va_arg(args, unsigned int));
	else if (s[i] == 'p')
	{
		count = write(1, "0x", 2);
		count += ft_put_ptr(va_arg(args, unsigned long long));
	}
	else if (s[i] == 'u')
		count = put_u_nbr(va_arg(args, unsigned int));
	else if (s[i] == '%')
		count = ft_put_char(s[i]);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		write(1, "(null)", 6);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += checking(s, args, i);
			i++;
		}
		else
		{
		count += ft_put_char(s[i]);
		i++;
		}
	}
	va_end(args);
	return (count);
}
