/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:33:49 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/26 14:56:52 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_options	options;

	options = get_options(argc, argv);
	ft_printf("option l : %d\n", options.l);
	ft_printf("option r : %d\n", options.r);
	ft_printf("option R : %d\n", options.R);
	ft_printf("option a : %d\n", options.a);
	ft_printf("option t : %d\n", options.t);
	ft_printf("option G : %d\n", options.G);
	ft_printf("option u : %d\n", options.u);
	ft_printf("option f : %d\n", options.f);
	ft_printf("option g : %d\n", options.g);
	ft_printf("option d : %d\n", options.d);
	return (0);
}
