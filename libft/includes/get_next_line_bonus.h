/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:54 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/24 14:42:13 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
int					get_line(char **res, char **line, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strrchr_gnl(const char *s, int c);
int					ft_strchr_gnl(const char *s, int c);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);

#endif
