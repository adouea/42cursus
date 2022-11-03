/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:59:50 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/03 16:29:10 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_size;

	i = 0;
	dest_size = ft_strlen(dst);
	if (n < dest_size)
		return (ft_strlen(src) + n);
	while (src[i] && (i < (n - dest_size - 1)))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (ft_strlen(src) + dest_size);
}
