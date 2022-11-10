/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:51:18 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 18:54:23 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_tot(const char *s1, const char *s2)
{
	size_t	lentot;
	size_t	i;

	lentot = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		lentot++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		lentot++;
		i++;
	}
	return (lentot);
}

char	*joinning(char const *s1, char const *s2, char *s3, size_t j)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((len_tot(s1, s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	s3 = joinning(s1, s2, s3, j);
	return (s3);
}
