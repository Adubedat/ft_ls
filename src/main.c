/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 16:13:54 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_op	options;

	options = get_options(argc, argv);
	sort(&options);
	if (options.l == 1)
		print_files_l(options);
	else
		print_files(options);
	print_rep(options);
	free_options(&options);
	return (0);
}
