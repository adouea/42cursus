/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:28:52 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 14:46:00 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pretrimmer(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] != set[j])
                return ((char *)s1);
			if (s1[i] == set[j])
				s1 += 1;
			j++;
		}
		i++;
	}
	return ((char *)s1);
}

static char	*posttrimmer(char const *set, char *trim)
{
	int		i;
	size_t	j;

	i = ft_strlen(trim) - 1;
	j = 0;
	while (i >= 0)
	{	
		while (set[j] != '\0')
		{
			//if (trim[i] != set[j])
              //  return (trim);
			if (trim[i] == (char)set[j])
			{
				trim[i] = 'a';
			}
			j++;
			i--;
		}
		i--;
	}
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	trim = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!trim)
		return (trim);
	trim = pretrimmer(s1, set);
	trim = posttrimmer(set, trim);
	return (trim);
}

#include <stdio.h>

int	main()
{
printf("%s\n", ft_strtrim("Hello World", "d"));
return (0);
}
