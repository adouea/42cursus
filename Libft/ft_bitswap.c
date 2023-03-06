/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:09:40 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/22 15:34:52 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_bitswap(unsigned char octet)
{
	unsigned char	result;
	int				byte_len;

	byte_len = 8;
	result = 0;
	while (byte_len--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}
