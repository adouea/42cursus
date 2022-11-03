/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:23:30 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/03 16:24:55 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*snew;
	size_t	i;

	i = 0;
	snew = malloc((len + 1) * sizeof(char));
	if (!snew || len <= 0 || len > SIZE_MAX)
		return (0);
	while (i < len)
	{
		snew[i] = s[start];
		i++;
		start++;
	}
	snew[i] = '\0';
	return (snew);
}
