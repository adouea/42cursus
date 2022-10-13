/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:34:32 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/13 11:34:55 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrchr(char *s, int c)
{       
        int     i;

        i = 0;
        while (s[i])
        {
                if (s[i] == c)
                        return (pointeur sur memoire derniere occurence int c dans string(char*) s);                     i++;
        }       
        return (s[i]?? a tester);
}   
