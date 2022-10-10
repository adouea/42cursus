/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:24:15 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/10 18:02:07 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int     ft_isalpha(char *str)
{
        int     i;

        i = 0;
        if (str[i] == '\0')
                return (1);
        while (str[i] != '\0' && ((str[i] > 64 && str [i] < 91)
                        || (str[i] > 96 && str[i] < 123)))
                i++;
        if (str[i] == '\0')
                return (1);
        else
                return (0);
}

int	main()
{
	char *a = "0";

	printf("%i", ft_isalpha(a));
	printf("%i", isalpha(123));
	return (0);
}
//ok donc comme je vais y aller je me laisse un petit log en bas de page.
//je viens d'essayer de comprendre pourquoi 1024 est utilise comme nombre non zero par la fonction 
//mais pour l'instant, je vais me borner a une valeur non nulle = 1 pour test
//a tout 

