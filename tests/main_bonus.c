/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:48 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/19 15:05:57 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm_bonus.h"

static void	print_list(t_list *lst)
{
	if (!lst)
		printf("List is empty\n");
	while (lst)
	{
		printf("%s -> ", (char *)lst->data);
		lst = lst->next;
	}
	printf("(null)\n");
}

static void	check_list(int max)
{
	int		size;
	int		i;
	t_list	*lst;
	char	*s[5];

	lst = NULL;
	size = 0;
	i = 0;
	s[0] = "1st push";
	s[1] = "2nd push";
	s[2] = "3rd push";
	s[3] = "4th push";
	s[4] = "5th push";
	while (i < max)
	{
		ft_list_push_front(&lst, s[i]);
		i++;
	}
	print_list(lst);
	size = ft_list_size(lst);
	printf("List size: [%d]\t\t\t\t\t\t", size);
	if (size == max)
		printf("[\033[0;32m ok \033[0m]\n\n");
	else
		printf("[\033[0;31m ko \033[0m]\n\n");
}

int			main(void)
{
	printf("\033[0;33m ------------------------\n");
	printf("|   LIBASM_BONUS TESTS   |\n");
	printf(" ------------------------\n\n\033[0;m");
	printf("\033[0;35m ------------------------\n");
	printf("|   ft_list_push_front   |\n\n\033[0;m");
	check_list(1);
	check_list(3);
	check_list(5);
	check_list(0);
	printf("\033[0;33m[ END OF TESTS ]\n\n");
	return (0);
}
