/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:01 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/21 18:07:13 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

typedef struct			s_list
{
	void			*data;
	struct s_list	*next;
}						t_list;

size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *s);
void					check_strlen(void);
void					check_strcpy(void);
void					check_strcmp(void);
void					check_strdup(void);
ssize_t					ft_write(int fd, const void *buff, size_t count);
void					check_write(void);
ssize_t					ft_read(int fd, void *buff, size_t count);
void					check_read(void);
void					read_error();
int						ft_list_size(t_list *begin_list);
void					ft_list_push_front(t_list **begin_list, void *data);
void					ok_or_ko(ssize_t mine, ssize_t real);
void					ok_or_ko_double(int error1, int error2,
		ssize_t mine, ssize_t real);

#endif
