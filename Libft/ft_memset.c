/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:08:25 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/13 14:28:09 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(char *s, int c, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (0);
}