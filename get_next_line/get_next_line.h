/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:08:51 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/20 14:50:12 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

char	*get_next_line(int fd);
char	*ft_parse_line(char **keep, char **tmp);
void	ft_read_line(int fd, char **keep, char **tmp);
char	*get_after_nl(const char *s);
char	*get_before_nl(const char *s);
char	*ft_strdup(const char *s);
char	*ft_join(const char *s1, const char *s2);
int		ft_nl_found(const char *s);
void	ft_free(char **s1, char **s2, char **s3);
void	*ft_malloc_zero(size_t count, size_t size);

#endif
