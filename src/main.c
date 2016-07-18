/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/18 18:55:55 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_op	options;

	options = get_options(argc, argv);
	sort_by_ascii(options.files, 0);
	sort_by_ascii(options.rep, 0);
	print_files(options);
	options.flag = 1;
	print_rep(options);
//	stat(options.files[0], &info);
//	if (info.st_mode & S_IFDIR)
//		ft_printf("C'est un repertoire.\n");
//	if (info.st_mode & S_IFREG)
//		ft_printf("%s\n", options.files[0]);
	return (0);
}
