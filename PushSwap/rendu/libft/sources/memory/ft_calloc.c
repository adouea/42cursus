/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:16 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/07 16:17:30 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size >= 65536 || nmemb >= 65536)
		return (0);
	mem = malloc((nmemb) * size);
	if (!mem)
		return (0);
	while (i < (nmemb * size))
	{
		mem[i] = '\0';
		i++;
	}
	return ((void *)mem);
}
