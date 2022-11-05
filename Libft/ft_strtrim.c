/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:28:52 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/05 15:41:56 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *s);

static char	*trimmer(char const *s1, char const *set, char *trim, int i)
{
	size_t	j;
	int		k;

	j = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				i++;
			j++;
			if (j == ft_strlen(set))
			{
				trim[k] = s1[i];
				k++;
			}
		}
		j = 0;
		i++;
	}
	return (trim);
}

static long unsigned int	occur(char const *s1, char const *set)
{
	int						i;
	int						j;
	long unsigned int		occur;

	i = 0;
	j = 0;
	occur = 0;
	while (set[j] != '\0')
	{
		while (s1[i] != '\0')
		{
			if (s1[i] == set[j])
				occur++;
			i++;
		}
		i = 0;
		j++;
	}
	return (occur);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;

	i = 0;
	trim = malloc((ft_strlen(s1) - (occur(s1, set)) + 1) * sizeof(char));
	if (!trim)
		return (trim);
	trimmer(s1, set, trim, i);
	return (trim);
}
