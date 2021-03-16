/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:24:50 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/17 00:39:12 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	read_stdin(void)
{
	int		fd;
	char	*buf;
	ssize_t	mine;

	buf = (char *)malloc(sizeof(char) * 200);
	fd = STDIN_FILENO;
	mine = ft_read(fd, buf, 200);
	printf("%s\n", buf);
	free(buf);
	close(fd);
	buf = (char *)malloc(sizeof(char) * 200);
	printf("\033[0;33mMANDATORY PART FINISHED\n\033[0;m");
}

static void	loop_read(char *s, size_t size)
{
	char	*buf;
	ssize_t	mine;
	ssize_t	real;
	int		fd;

	buf = (char *)malloc(sizeof(char) * size);
	fd = open(s, O_RDONLY);
	mine = ft_read(fd, buf, size);
	printf("mine:\n%s\n", buf);
	free(buf);
	close(fd);
	buf = (char *)malloc(sizeof(char) * size);
	fd = open(s, O_RDONLY);
	real = read(fd, buf, size);
	printf("real:\n%s\n", buf);
	free(buf);
	close(fd);
	printf("ft_read [%zd]\tvs\t[%zd] read\t\t", mine, real);
	if (mine == real)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
}

void		check_read(void)
{
	char	*s[4];
	size_t	size;
	int		i;

	s[0] = "Makefile";
	s[1] = "tests/main.c";
	s[2] = "tests/check_write.c";
	s[3] = "unknown file";
	i = -1;
	size = 50;
	while (++i < 4)
	{
		loop_read(s[i], size);
		size += 50;
	}
	printf("\033[0;35mCheck STDIN now :\n");
	printf("==> Hit something and then hit Enter to finish...\n\033[0;m");
	read_stdin();
//	read_error();
}
