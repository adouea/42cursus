/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:18:04 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:18:05 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char_num(char *char_num)
{
	int	i;

	i = 0;
	if (char_num[i] == '+' || char_num[i] == '-')
		i++;
	if (! char_num[i])
		return (0);
	while (char_num[i])
	{
		if (! ft_isdigit(char_num[i++]))
			return (0);
	}
	return (! (ft_atoi(char_num) - ft_atol(char_num)));
}

int	check_and_fill_stack(int argc, char **argv, t_stack **stk)
{
	char	*number;
	int		i;
	int		j;

	i = argc;
	while (i--)
	{
		number = argv[i];
		if (! check_char_num(number))
			return (0);
		j = argc - 1;
		while (j > i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(number))
				return (0);
			j--;
		}
		if (! append_node(ft_atoi(number), stk))
			return (0);
	}
	return (1);
}

int	check_triple(t_stack *stk)
{
	int	first;
	int	second;
	int	third;

	first = stk->value;
	second = stk->next->value;
	third = stk->next->next->value;
	if (first < second)
	{
		if (second < third)
			return (0);
		else if (third > first)
			return (1);
		else
			return (2);
	}
	else
	{
		if (second > third)
			return (3);
		else if (third < first)
			return (4);
		else
			return (5);
	}
}
