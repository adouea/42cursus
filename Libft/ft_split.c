/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:26:12 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/20 18:29:45 by aadoue           ###   ########.fr       */
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
	unsigned int	i;
	unsigned int	j;
	unsigned int	end;
	char	**tab;
	
	i = 0;
	j = 0;
	end = 0;
	tab = malloc(1000000 * lines_count(s, c) * sizeof(char));
	if (tab)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
			{
				end = i;
				while (s[end] != c)
					end++;
				i = end;
				tab[j] = ft_substr(s, i, (end - i));
				j++;
			}
			i++;
		}
		printf("%s\n", tab[0]);
		//printf("%s\n", tab[1]);
		//printf("%s\n", tab[2]);
		//printf("%s\n", tab[3]);
		//printf("%s\n", tab[4]);
		tab[j] = '\0';
	}
	return (tab);
}

int main()
{
	ft_split("Hello World This is a beautiful", ' ');
	return (0);
}       
