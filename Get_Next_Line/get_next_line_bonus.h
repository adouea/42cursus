/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:40 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/10 12:45:57 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *start);
char	*ft_new_start(char *start);
char	*ft_strchr(char *s, int c);
char	*ft_joinprep(char *s1, char *s2);
char	*ft_joinning(char *stock, char *s1, char *s2);

#endif
