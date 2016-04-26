/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:09:13 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/26 14:56:54 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	initialize_options(t_options *options)
{
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->a = 0;
	options->t = 0;
	options->G = 0;
	options->u = 0;
	options->f = 0;
	options->g = 0;
	options->d = 0;
}

static void	error_option(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ls [-lrRatgGufd] ", c);
	ft_putendl("[file ...]");
	exit(1);
}

static void	flag_options(t_options *options, char c)
{
	if (c == 'l')
		options->l = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'R')
		options->R = 1;
	else if (c == 'a')
		options->a = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == 'G')
		options->G = 1;
	else if (c == 'u')
		options->u = 1;
	else if (c == 'f')
		options->f = 1;
	else if (c == 'g')
		options->g = 1;
	else if (c == 'd')
		options->d = 1;
}

t_options	get_options(int argc, char **argv)
{
	int			i;
	int			j;
	t_options	options;

	i = 1;
	initialize_options(&options);
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] != '-')
			return (options);
		j++;
		while (argv[i][j])
		{
			if (ft_strchr("lrRatGufgd", argv[i][j]) == NULL)
				error_option(argv[i][j]);
			flag_options(&options, argv[i][j]);
			j++;
		}
		i++;
	}
	return (options);
}
