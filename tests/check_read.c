/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:24:50 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 00:40:40 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	read_stdin(void)
{
	int		fd;
	char	*buf;
	ssize_t	mine;

	buf = (char *)malloc(sizeof(char) * 201);
	fd = STDIN_FILENO;
	mine = ft_read(fd, buf, 200);
	printf("%s\n", buf);
	free(buf);
	close(fd);
	buf = (char *)malloc(sizeof(char) * 200);
}

static void	loop_read(char *s, size_t size)
{
	char	*buf;
	ssize_t	mine;
	ssize_t	real;
	int		fd;

	buf = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(s, O_RDONLY);
	mine = ft_read(fd, buf, size);
	printf("file [%s]\nmine:\n%s\n", s, buf);
	free(buf);
	close(fd);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(s, O_RDONLY);
	real = read(fd, buf, size);
	printf("real:\n%s\n", buf);
	free(buf);
	close(fd);
	printf("\nft_read\t\t[%zd]\tvs\t[%zd]\tread\t\t", mine, real);
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
	s[3] = "tests/check_strdup.c";
	i = -1;
	size = 50;
	while (++i < 4)
	{
		loop_read(s[i], size);
		size *= 2;
	}
	printf("\033[0;35m -------------------\n|    read_error    |\n\n\033[0;m");
	read_error();
	printf("\033[0;35mCheck STDIN now :\n");
	printf("==> Hit something and then hit Enter to finish...\n\033[0;m");
	read_stdin();
}
