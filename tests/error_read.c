/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 00:33:33 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 21:16:50 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	read_nul_buf(char *file, int size)
{
	int		error1;
	int		error2;
	int		fd;
	ssize_t	mine;
	ssize_t	real;

	fd = open(file, O_RDONLY);
	mine = ft_read(fd, NULL, size);
	perror("mine");
	error1 = errno;
	close(fd);
	fd = open(file, O_RDONLY);
	real = read(fd, NULL, size);
	perror("real");
	error2 = errno;
	printf("Errno:\t\t\t\t\t[%d]\tvs\t[%d]\n", error1, error2);
	printf("ft_read_nul_buf(%d, %s, %d)\t[%zd]\tvs\t[%zd]\tread\t\t",
			fd, file, size, mine, real);
	close(fd);
	ok_or_ko_double(error1, error2, mine, real);
}

static void	loop_error(char *file, int size)
{
	int		error1;
	int		error2;
	char	*buf;
	int		fd;
	ssize_t	mine;
	ssize_t	real;

	buf = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(file, O_RDONLY);
	mine = ft_read(fd, buf, size);
	perror("mine");
	error1 = errno;
	free(buf);
	close(fd);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(file, O_RDONLY);
	real = read(fd, buf, size);
	perror("real");
	error2 = errno;
	printf("Errno:\t\t\t\t\t[%d]\tvs\t[%d]\n", error1, error2);
	printf("ft_read(%d, %s, %d)\t\t\t[%zd]\tvs\t[%zd]\tread\t\t",
			fd, file, size, mine, real);
	free(buf);
	close(fd);
	ok_or_ko_double(error1, error2, mine, real);
}

void		read_error(void)
{
	loop_error("error", 50);
	loop_error("Makefile", -50);
	loop_error(NULL, 50);
	read_nul_buf("Makefile", 50);
}
