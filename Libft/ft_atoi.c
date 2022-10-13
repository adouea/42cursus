/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:26:43 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/12 13:30:45 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	result = 0;
	minus = 1;
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * minus);
}
