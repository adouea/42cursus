/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:36:37 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/17 12:40:01 by aadoue           ###   ########.fr       */
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

long unsigned int       ft_strlcpy(char *dest, char *src, unsigned int size)
{
        unsigned int    i;

        i = 0;
        if (size > ft_strlen(src))
                return (ft_strlen(src));
        if (size == 0)
                return (ft_strlen(src));
        while (src[i] != '\0' && i < size)
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (ft_strlen(src));
}

//DONT FORGET THE "-lbsd" AT THE END OF COMPIL COMMAND : "gcc -W* *.c -lbsd"

int     main()
{
        char src[12] = "Hello World";
        char dest[12] = "Hella World";

        printf("%s\n", src);
        printf("%s\n", dest);

        printf("%lu\n", ft_strlcpy(dest, src, 6));
        printf("%s\n\n", dest);

        char src2[12] = "Hello World";
        char dest2[12] = "Hella World";

        printf("%s\n", src2);
        printf("%s\n", dest2);

        printf("%lu\n", strlcpy(dest2, src2, 6));
        printf("%s\n", dest2);

        return (0);
}                              
