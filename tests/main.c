/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:48 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/15 21:23:17 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

void	check_strlen(void)
{
	int		i;
	char	*s[10];

	s[0] = "mot";
	s[1] = "deux mots";
	s[2] = "plusieurs mots font une phrase...";
	s[3] = "";
	s[4] = "\0";
	s[5] = "caractères spéciaux : &é'(§è!çà)°$*`£%ù^¨=+:/;.,?∞…÷≠@#\x17";
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

int		main(void)
{
	printf(" ------------------------\n");
	printf("|      LIBASM TESTS      |\n");
	printf(" ------------------------\n\n");
	check_strlen();
	return (0);
}
