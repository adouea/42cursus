/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:59:50 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 18:42:33 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	if ((!dst || !src) && size == 0)
		return (0);
	if (size == 0 || ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	dest_size = ft_strlen(dst);
	while (src[i] && ((i + dest_size) < size - 1))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (ft_strlen(src) + dest_size);
}
