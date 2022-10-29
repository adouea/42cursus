/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:41 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/24 16:25:58 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

long unsigned int     ft_strlen(char const *str)
{
        long unsigned int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

//static// 
char	char_to_char(unsigned int ascii, char c)
{
	c = c;
	return (ascii);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*stock;

	i = 0;
	stock = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (stock)
	{
		while (s[i] != '\0')
		{
			stock[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (stock);
}

int main()
{
	char (*f)(unsigned int, char);
	f = &char_to_char;

	printf("%s\n", ft_strmapi("Hello World", f));
	return (0);
}
