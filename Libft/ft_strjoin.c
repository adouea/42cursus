/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:51:18 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/03 16:32:57 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long unsigned int	len_tot(const char *s1, const char *s2)
{
	long unsigned int	lentot;
	int					i;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = malloc((len_tot(s1, s2)) * sizeof(char));
	if (!s3)
		return (s3);
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
