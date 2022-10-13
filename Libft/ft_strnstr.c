/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:11:32 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/13 15:14:38 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *big, char *little, int n)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = 0;
	len = 0;
	while (little[len])
		len++;
	if (len == 0)
		return (big);
	while (big[++i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (j + 1 == len)
				return (&big[i]);
			j++;
		}
	}
	return (0);
}
