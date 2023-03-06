/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:23:30 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 16:06:36 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*snew;
	size_t	i;
	size_t	sstart;

	i = 0;
	sstart = start;
	if (!s) 
		return (NULL);
	if (sstart >= ft_strlen((char *)s))
		{
			snew = ft_calloc(1, 1);
			if (!snew)
				return (NULL);
			return (snew);
		}
	snew = ft_calloc(sizeof(char), len + 1);
	if (!snew || len <= 0 || len > SIZE_MAX)
		return (NULL);
	while (i < len)
		snew[i++] = s[start++];
	return (snew);
}
