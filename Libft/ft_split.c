/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:26:12 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/05 15:46:40 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//long unsigned int	c_count(char const *s, char c)
//{
//	long unsigned int	nb;
//	int	i;
//
//	nb = 0;
//	i = 0;
//	while (s[i] != '\0')
//	{
//		if (s[i] == c)
//			nb++;
//		i++;
//	}
//	return (nb);
//}

char	*ft_substr(char const *s, unsigned int start, size_t len);

static long unsigned int	lines_count(char const *s, char c)
{
	long unsigned int	lines;
	int	i;
	
	lines = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			lines++;
		i++;
	}
	return (lines);
}

char	**ft_split(char const *s, char c)
{	
	long unsigned int	i;
	long unsigned int	j;
	long unsigned int	end;
	char	**tab;
	char	*stock;
	
	i = 0;
	j = 0;
	end = 0;
	stock = NULL;
	tab = malloc(8 * lines_count(s, c) * sizeof(char));
	if (!tab)
		return (tab);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			end = i;
			while (s[end] != c)
				end++;
			stock = ft_substr(s, i, (end - i));
			tab[j] = stock;
			i = end;
			j++;
		}
		i++;	
	}
	i = 0;
	tab[j] = '\0';
	//while (i < lines_count(s, c))
	//{
	//	printf("%s\n", tab[i]);
	//	i++;
	//}
	return (tab);
}       
