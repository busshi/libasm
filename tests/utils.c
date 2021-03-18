/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:01:30 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 21:04:06 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

void	ok_or_ko_double(int error1, int error2, ssize_t mine, ssize_t real)
{
	if (mine == real && error1 == error2)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
}

void	ok_or_ko(ssize_t mine, ssize_t real)
{
	if (mine == real)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
}
