/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/26 19:30:41 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_op	options;
//	t_files	*tmp;

	options = get_options(argc, argv);
	sort_by_ascii(&options.files);
//	tmp = options.files;
//	while (tmp != NULL)
//	{
//		ft_printf("name : %s\ntype : %d\n", tmp->file_name, tmp->type);
//		tmp = tmp->next;
//	}
	print_files(options);
	print_rep(options);
	return (0);
}
