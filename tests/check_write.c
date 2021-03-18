/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:24:50 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 21:09:25 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	check_neg_size(void)
{
	ssize_t	mine;
	ssize_t	real;
	int		error1;
	int		error2;

	real = write(1, "error", -5);
	perror("mine");
	error1 = errno;
	mine = ft_write(1, "error", -5);
	perror("real");
	error2 = errno;
	printf("errno:\t\t\t\t[%d]\tvs\t[%d]\n", error1, error2);
	printf("ft_write(1, \"error\", -5)\t[%zd]\tvs\t[%zd]\twrite\t\t",
			mine, real);
	ok_or_ko(mine, real);
}

static void	check_neg_fd(void)
{
	ssize_t	mine;
	ssize_t	real;
	int		error1;
	int		error2;

	real = write(-1, "error", 5);
	perror("mine");
	error1 = errno;
	mine = ft_write(-1, "error", 5);
	perror("real");
	error2 = errno;
	printf("errno:\t\t\t\t[%d]\tvs\t[%d]\n", error1, error2);
	printf("ft_write(-1, \"error\", 5)\t[%zd]\tvs\t[%zd]\twrite\t\t",
			mine, real);
	ok_or_ko(mine, real);
	check_neg_size();
}

static void	check_null_string(void)
{
	ssize_t	mine;
	ssize_t	real;
	int		error1;
	int		error2;

	printf("\033[0;35m -------------------\n|    write_error    |\n\n\033[0;m");
	real = write(1, NULL, 3);
	error1 = errno;
	perror("mine");
	mine = ft_write(1, NULL, 3);
	perror("real");
	error2 = errno;
	printf("errno:\t\t\t\t[%d]\tvs\t[%d]\n", error1, error2);
	printf("ft_write(1, NULL, 3)\t\t[%zd]\tvs\t[%zd]\twrite\t\t", mine, real);
	ok_or_ko(mine, real);
	check_neg_fd();
}

void		check_write(void)
{
	ssize_t	mine;
	ssize_t	real;
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
		printf("ft_write [%zd]\tvs\t[%zd] write\t\t", mine, real);
		ok_or_ko(mine, real);
	}
	check_null_string();
}
