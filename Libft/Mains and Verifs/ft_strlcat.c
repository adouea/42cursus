/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:59:50 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/17 14:33:06 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>

long unsigned int     ft_strlen(char *str)
{
        long unsigned int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

long unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_size;

	i = 0;
	dest_size = ft_strlen(dest);
	if (nb < dest_size)
		return (ft_strlen(src) + nb);
	while (src[i] && (i < (nb - dest_size - 1)))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (ft_strlen(src) + dest_size);
}

int	main()
{
	char src[24] = "Hello";
	char dest[24] = "Hella World";

	char src2[24] = "Hello";
        char dest2[24] = "Hella World";
// FT
	printf("%s\n", src);
	printf("%s\n", dest);

	printf("%lu\n", ft_strlcat(dest, src, 17));
	printf("%s\n\n", dest);
// ORIGINAL
        printf("%s\n", src2);
        printf("%s\n", dest2);

        printf("%lu\n", strlcat(dest2, src2, 17));
        printf("%s\n\n", dest2);

	return (0);
}
