/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:51 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/27 16:08:17 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int len_tot(int size, char **strs)
{
	int i;
	int j;
	int lentot;

	i = 0;
	j = 0;
	lentot = 0;
	while (i < size)
	{
		while(strs[i][j])
			j++;
		lentot = lentot + j;
		j = 0;
		i++;
	}
	return (lentot);
}



char    *ft_strjoin(int size, char **strs, char *sep)
{       
        char *join;
        int i;
        int j;
        int k;

	i = 0;
	j = 0;
	k = 0;
        join = NULL;
        if (((join = malloc((size + len_tot(size, strs)) * sizeof(char))) == NULL )|| size == 0)
                return join;
        while(i < size)
        {
                while(strs[i][j])
                {
                        join[k++] = strs[i][j];
                        j++;
                }
                i++;
                j = -1;
		while (sep[++j] && i < size)
			join[k++] = sep[j];
		j = 0;
       }
       join[k] = '\0';
       return (join);
}

int main(int argc, char **argv)
{       
   
	if (argc == 1)
		return 0;

        char *sep = "PmLFCdFhxDX624awBt53W7wr";
        char *strs[50];
        
        strs[0] = argv[1];
        strs[1] = argv[2];
        strs[2] = argv[3];
        strs[3] = argv[4];
        strs[4] = argv[5];
        strs[5] = argv[6];
        strs[6] = argv[7];
        strs[7] = argv[8];
        strs[8] = argv[9];
        strs[9] = argv[10];
        strs[10] = argv[11];
        strs[11] = argv[12];
        strs[12] = argv[13];
        strs[13] = argv[14];
        strs[14] = argv[15];
        strs[15] = argv[16];
        strs[16] = argv[17];
        strs[17] = argv[18];
        strs[18] = argv[19];
        strs[19] = argv[20];
        strs[20] = argv[21];
        
        printf("%s\n", ft_strjoin(25, strs, sep));
        return (0);
} 
