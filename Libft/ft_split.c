/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:26:12 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/24 11:55:51 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

long unsigned int	c_count(char const *s, char c)
{
	long unsigned int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*snew;
	unsigned int	i;

	i = 0;
	snew = malloc((len + 1) * sizeof(char));
	if (!snew || len <= 0)
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

long unsigned int	lines_count(char const *s, char c)
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

char	**ft_split(char *s, char c)
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
	if (tab)
	{
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
		while (i < lines_count(s, c))
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	return (tab);
}

int main()
{
	ft_split("Hello World This is a beautifullynessly", ' ');
	return (0);
}       
