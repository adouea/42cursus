/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftatoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:44:32 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/19 12:54:25 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(char *str)
{
        int i;
        int entier;
        int minus;

        i = 0;
        entier = 0;
        minus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
        while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
        {
                entier = (entier * 10) + (str[i] - 48);
                i++;
        }
        return (entier * minus);
}

int main ()
{
	char str[] = "--1234a";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}
