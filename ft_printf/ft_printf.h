/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:55:18 by avila-ca          #+#    #+#             */
/*   Updated: 2022/07/21 18:01:18 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		checking(const char *s, va_list args, int i);
int		check_nbr(va_list args);
int		check_str(va_list args);
int		check_char(va_list args);
int		ft_put_hexup(unsigned int n);
int		ft_put_hexlow(unsigned int n);
int		ft_put_ptr(unsigned long long n);
int		ft_put_char(int c);
int		put_nbr(int n);
int		put_u_nbr(unsigned int n);

#endif
