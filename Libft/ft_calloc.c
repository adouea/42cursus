/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:16 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/03 15:03:39 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	void	*ptr;

	mem = malloc((nmemb + 1) * size);
	if (!mem)
		return (0);
	ft_memset(mem, 0, nmemb);
	ptr = &mem;
	return (ptr);
}
