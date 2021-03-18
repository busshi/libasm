/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:50:34 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/17 17:23:09 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

static void	loop_strdup(char *s, char *my_dup, char *true_dup)
{
	printf("src: %s\nft_strdup [%s]\nvs\nstrdup    [%s]\n",
			s, my_dup, true_dup);
	if (strcmp(my_dup, true_dup) == 0)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
	free(my_dup);
	free(true_dup);
}

void		check_strdup(void)
{
	int		i;
	char	*s[10];
	char	*my_dup;
	char	*true_dup;

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
		my_dup = ft_strdup(s[i]);
		true_dup = strdup(s[i]);
		loop_strdup(s[i], my_dup, true_dup);
	}
}
