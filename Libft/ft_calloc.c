/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:16 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/17 12:01:30 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(char *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (0);
}

void	*ft_calloc(long unsigned int nmemb, unsigned int size)
{
	char	*mem;

	mem = malloc((nmemb + 1) * size);
	if(!mem)
		return (0);
	ft_memset(mem, 0, nmemb);
	return (*mem);
}
