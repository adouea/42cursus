/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:59 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 18:47:43 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	comp(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*trim;

	i = 0;
	if (set == NULL || s1 == NULL )
		return (0);
	while (comp(s1[i], set) == 0)
		i++;
	len = ft_strlen(s1);
	while (comp(s1[len - 1], set) == 0)
		len--;
	if (i == ft_strlen(s1))
	{
		trim = ft_strdup("");
		return (trim);
	}
	trim = ft_substr(s1, i, len - i);
	return (trim);
}
