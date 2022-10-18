/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:23:30 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/18 18:26:12 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

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

int main()
{
	printf("%s\n", ft_substr("Hello World this is a beautiful new day", 20, 3));
	return (0);
}
