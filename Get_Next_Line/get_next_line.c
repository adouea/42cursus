/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:38:55 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/01 13:44:57 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*stock;
	int		i;

	i = 0;
	while (src[i])
		i++;
	stock = (char *)malloc(i + 1);
	if (!stock)
		return (0);
	i = 0;
	while (src[i])
	{
		stock[i] = src[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

int	get_line(int fd)
{
	static int s = 0;
	if (all ok)
	{
		printf(s line);
		s++;
	}
	return (s);
}


char	*get_next_line(int fd)
{
	int		rr;
	char	*str;

	rr = 0;
//	if (rien a lire ou pb)
//		return (NULL);
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL); 
	rr = read(fd, str, BUFFER_SIZE);
	if (rr > 0)
	{
		str[rr - 1] = '\n';
		str[rr] = '\0';
		return (str);
	}
	if (rr == 0) //end of file
	{
		str[rr] = '\0';
		return (str);
	}
	if (rr == -1) //error or signal interrupt
		return (NULL);
}

int	main()
{
	printf("%s\n", get_next_line(0));
	return (0);
}

/* Simple steps :
	- check fd and BUFFER_SIZE declared in .h, return NULL if pb;
	- read static s line of file or directly on buffer;
	- strdup str "...\n\0" ou "...\0";
	- s++;
	- return str
*/

	//lecture sur fichier ou entree standard toujours termine par '\n' sauf si derniere ligne du fichier et ne se terminant pas par '\n'

	//le programme doit lire le moins possible de chaque fichier pour eviter les latences, donc je 
//suppose que lire jusqu a la rencontre d'un '\n' est a envisager 

	//la taille du buffer sera determinee a la compilation avec -D BUFFER_SIZE=... , c'est necessaire
//pour les appels a READ 

	//verifier si fichier readable avec read(fd, &line, 0) < 0 (bad) vs open() O_RDONLY dans le main, donc on a pas a gerer ca dans la fonction gnl

	//pas de main, pas de Makefile

	//c'est l'utilisateur qui free la ligne recue de gnl, je dois liberer uniquement la static si je l'ai malloc, mais pas oblige dapres averdon 

	//bonus = une seule variable statique dans le scope du pseudo "main" ET capacite de gerer plusieurs fd (???pokonpri...)

	//Au dela : 
- usleep() in ms ??
- --track-origins=yes est utile pour essayer de comprendre quelle valeur n'est pas initialisée



	//Liens :
// https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
// https://gitlab.com/hydrasho/gnl_tester
