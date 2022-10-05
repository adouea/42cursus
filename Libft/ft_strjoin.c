/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:51 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/27 18:31:41 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	len_tot(char *sep, int size, char **strs)
{
	int	i;
	int	j;
	int	lentot;

	i = 0;
	j = 0;
	lentot = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		while (strs[i][j])
			j++;
		lentot = lentot + j;
		j = 0;
		i++;
	}
	while (sep[j])
		j++;
	lentot = 1 + lentot + ((size - 1) * j);
	return (lentot);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = 0;
	join = malloc((len_tot(sep, size, strs)) * sizeof(char));
	if (!join || size <= 0)
		return (join);
	while (i < size)
	{
		while (strs[i][++j])
			join[k++] = strs[i][j];
		i++;
		j = -1;
		while (sep[++j] && i < size)
			join[k++] = sep[j];
		j = -1;
	}
	join[k] = '\0';
	return (join);
}
