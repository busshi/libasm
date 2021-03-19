/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:01 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/19 15:01:27 by aldubar          ###   ########.fr       */
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

int						ft_list_size(t_list *begin_list);
void					ft_list_push_front(t_list **begin_list, void *data);
void					ok_or_ko(ssize_t mine, ssize_t real);

#endif
