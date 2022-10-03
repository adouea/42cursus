/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:24:59 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/16 16:17:13 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	countsrc;
	unsigned int	countdest;

	countsrc = 0;
	countdest = 0;
	while (src[countsrc])
		countsrc++;
	while (dest[countdest])
		countdest++;
	i = 0;
	if (size > countsrc || size > countdest)
		return (countsrc);
	if (size == 0)
		return (countsrc);
	while (src[i] != '\0' || i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (countsrc);
}

int main()
{
	char dest[20]="Hella World";
	char src[15]="Hello Plamck";
	char dest2[20] = "Hella World";
	char src2[15] = "Hello Plamck";

	printf("%lu", strlcpy(dest2, src2, 0));
	printf("%c", '\n');
	printf("%u",ft_strlcpy(dest, src, 0));
	return (0);
}
