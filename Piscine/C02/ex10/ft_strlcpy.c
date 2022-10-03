/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:24:59 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/15 18:04:13 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
