/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/10 23:50:39 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_options	options;
	int			i = 0;

	options = get_options(argc, argv);
	sort_by_ascii(options.files, 0);
	sort_by_ascii(options.rep, 0);
	while (options.files[i] != NULL)
	{
		ft_printf("%s\n", options.files[i]);
		i++;
	}
	i = 0;
	while (options.rep[i] != NULL)
	{
		ft_printf("%s\n", options.rep[i]);
		i++;
	}
//	sort_by_ascii(option->files);
//	stat(options.files[0], &info);
//	if (info.st_mode & S_IFDIR)
//		ft_printf("C'est un repertoire.\n");
//	if (info.st_mode & S_IFREG)
//		ft_printf("%s\n", options.files[0]);
	return (0);
}