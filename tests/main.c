/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:48 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/18 00:41:54 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	check_strcpy(void)
{
	int		i;
	char	dest[50];
	char	*s[10];

	s[0] = "test";
	s[1] = "test simple";
	s[2] = "test                avec        espaces   ";
	s[3] = "test\t\t\v\rtabulations\n";
	s[4] = "nul byte\0";
	s[5] = "nul\0byte";
	s[6] = "caractères spéciaux 👉 &é'(§è!çà)-ù^¨$`*=+:/;.,?";
	s[7] = "caractères spéciaux 👉 &-)àçç!éè'§&";
	s[8] = "";
	s[9] = "\0";
	i = -1;
	while (++i < 10)
	{
		bzero(dest, 50);
		printf("src: %s\nft_strcpy [%s]\nvs\nstrcpy    [%s]\n",
			s[i], ft_strcpy(dest, s[i]), strcpy(dest, s[i]));
		if (strcmp(ft_strcpy(dest, s[i]), strcpy(dest, s[i])) == 0)
			printf("[\033[0;32m ok \033[0m]\n\n");
		else
			printf("[\033[0;31m ko \033[0m]\n\n");
	}
}

static void	check_strcmp(void)
{
	int		i;
	char	*s[10];

	s[0] = "test identique";
	s[1] = "test identique";
	s[2] = "test basique avec moins d'espaces  ";
	s[3] = "test basique avec moins d'espaces     ";
	s[4] = "nul byte";
	s[5] = "nul\0byte";
	s[6] = "caractères spéciaux 👉 \xFF \xAE&é'(§è!çà)-ù^¨$`*=+:/;.,?";
	s[7] = "caractères spéciaux 👉 \xFF \xAE&-)àçç!éè'§&";
	s[8] = "";
	s[9] = "\0";
	i = 0;
	while (i < 9)
	{
		printf("s1: %s\ns2: %s\n\033[20Gft_strcmp [%d]\tvs\t[%d] strcmp\t\t",
			s[i], s[i + 1], ft_strcmp(s[i], s[i + 1]), strcmp(s[i], s[i + 1]));
		if (ft_strcmp(s[i], s[i + 1]) == strcmp(s[i], s[i + 1]))
			printf("[\033[0;32m ok \033[0m]\n\n");
		else
			printf("[\033[0;31m ko \033[0m]\n\n");
		i += 2;
	}
}

static void	check_strlen(void)
{
	int		i;
	char	*s[10];

	s[0] = "mot";
	s[1] = "deux mots";
	s[2] = "plusieurs mots font une phrase...";
	s[3] = "";
	s[4] = "\0";
	s[5] = "caractères spéciaux : &é'(§è!çà)°$*`£%ù^¨=+:/;.,?∞…÷≠@#\x17\xFF";
	s[6] = "👉";
	s[7] = "test nul\0byte";
	s[8] = "test tabulations\t\r\t\v\ntabulations";
	s[9] = "fin des tests ft_strlen";
	i = -1;
	while (++i < 10)
	{
		printf("%s\n\033[20Gft_strlen [%zu]\tvs\t[%zu] strlen\t\t",
				s[i], ft_strlen(s[i]), strlen(s[i]));
		if (ft_strlen(s[i]) == strlen(s[i]))
			printf("[\033[0;32m ok \033[0m]\n\n");
		else
			printf("[\033[0;31m ko \033[0m]\n\n");
	}
}

int			main(void)
{
	printf("\033[0;33m ------------------------\n");
	printf("|      LIBASM TESTS      |\n");
	printf(" ------------------------\n\n\033[0;m");
	printf("\033[0;35m -------------------\n|     ft_strlen     |\n\n\033[0;m");
	check_strlen();
	printf("\033[0;35m -------------------\n|     ft_strcmp     |\n\n\033[0;m");
	check_strcmp();
	printf("\033[0;35m -------------------\n|     ft_strcpy     |\n\n\033[0;m");
	check_strcpy();
	printf("\033[0;35m -------------------\n|     ft_strdup     |\n\n\033[0;m");
	check_strdup();
	printf("\033[0;35m -------------------\n|     ft_write      |\n\n\033[0;m");
	check_write();
	printf("\033[0;35m -------------------\n|      ft_read      |\n\n\033[0;m");
	check_read();
        printf("\033[0;33m[ MANDATORY PART FINISHED ]\n\n");
	printf("Run make bonus to compile bonus...\n\033[0;m");
	return (0);
}
