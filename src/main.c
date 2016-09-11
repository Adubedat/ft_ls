/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/11 17:10:23 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_op	options;
//	t_files	*tmp;

	options = get_options(argc, argv);
//	tmp = options.files;
//	while (tmp != NULL)
//	{
//		ft_printf("name : %s\ntype : %d\ntime : %ld\n", tmp->file_name, tmp->type, tmp->check.st_atime);
//		tmp = tmp->next;
//	}
	sort(&options);
	if (options.l == 1)
		print_files_l(options);
	else
		print_files(options);
	print_rep(options);
	return (0);
}
