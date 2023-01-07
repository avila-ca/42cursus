/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:06:20 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/15 17:00:47 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"
int ft_count_words(char const *s, char c);
int main(void)
{
	char const *s;
	int words;

	s = NULL;
	printf("%s",ft_split(s,'k')[0]);
	return 0;
}
