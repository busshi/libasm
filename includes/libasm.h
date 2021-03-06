/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:01 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 21:11:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
void	check_strdup(void);
ssize_t	ft_write(int fd, const void *buff, size_t count);
void	check_write(void);
ssize_t	ft_read(int fd, void *buff, size_t count);
void	check_read(void);
void	read_error();
void	ok_or_ko(ssize_t mine, ssize_t real);
void	ok_or_ko_double(int error1, int error2, ssize_t mine, ssize_t real);

#endif
