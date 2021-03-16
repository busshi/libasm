/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:24:50 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/16 18:07:36 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	check_neg_size(void)
{
	ssize_t	mine;
	ssize_t	real;

	real = write(1, "error", -5);
	mine = ft_write(1, "error", -5);
	printf("ft_write(1, \"error\", -5)\t[%zd]\tvs\t[%zd]\twrite\t\t",
			mine, real);
	perror("");
	if (mine == real)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
}

static void	check_neg_fd(void)
{
	ssize_t	mine;
	ssize_t	real;

	real = write(-1, "error", 5);
	mine = ft_write(-1, "error", 5);
	printf("ft_write(-1, \"error\", 5)\t[%zd]\tvs\t[%zd]\twrite\t\t",
			mine, real);
	perror("");
	if (mine == real)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
	check_neg_size();
}

static void	check_null_string(void)
{
	ssize_t	mine;
	ssize_t	real;

	printf("\033[0;35m -------------------\n|    write_error    |\n\n\033[0;m");
	real = write(1, NULL, 3);
	mine = ft_write(1, NULL, 3);
	printf("ft_write(1, NULL, 3)\t\t[%zd]\tvs\t[%zd]\twrite\t\t", mine, real);
	perror("");
	if (mine == real)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
	check_neg_fd();
}

void		check_write(void)
{
	int		mine;
	int		real;
	int		i;
	char	*s[8];

	s[0] = "mot\n";
	s[1] = "plusieurs mots font une phrase...\n";
	s[2] = "";
	s[3] = "\0";
	s[4] = "caractères spéciaux : &é'(§è!çà)°$*`£%ù^¨=+:/;.,?∞…÷≠@#\x17\xFF\n";
	s[5] = "👉\n";
	s[6] = "test nul\n\0byte";
	s[7] = "test tabulations\t\r\t\v\ntabulations\n";
	i = -1;
	while (++i < 8)
	{
		mine = ft_write(1, s[i], strlen(s[i]));
		real = write(1, s[i], strlen(s[i]));
		printf("ft_write [%d]\tvs\t[%d] write\t\t", mine, real);
		if (mine == real)
			printf("[\033[0;32m ok \033[0m]\n\n");
		else
			printf("[\033[0;31m ko \033[0m]\n\n");
	}
	check_null_string();
}
