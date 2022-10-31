/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:28:52 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/31 15:38:35 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t  ft_strlen(const char *s);

long unsigned int	occur(char const *s1, char const *set)
{
	int	i;
	int	j;
	long unsigned int	occur;

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
	return(occur);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	long unsigned int	j;
	int	k;
	char	*trim;

	i = 0;
	j = 0;
	k = 0;
	trim = malloc((ft_strlen(s1) - (occur(s1, set)) + 1) * sizeof(char));
	if (!trim)
		return (trim);
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
