/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:09:13 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 17:53:27 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initialize_options(t_op *options)
{
	options->l = 0;
	options->r = 0;
	options->maj_r = 0;
	options->a = 0;
	options->t = 0;
	options->u = 0;
	options->g = 0;
	options->c = 0;
	options->p = 0;
	options->one = 0;
	options->flag = 0;
	options->path = NULL;
	options->files = NULL;
}

static void	error_option(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ls [-lrRatguc1p] ", c);
	ft_putendl("[file ...]");
	exit(1);
}

static void	flag_options(t_op *options, char c)
{
	if (c == 'l')
		options->l = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'R')
		options->maj_r = 1;
	else if (c == 'a')
		options->a = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == 'u')
	{
		options->u = 1;
		options->c = 0;
	}
	else if (c == 'g')
	{
		options->g = 1;
		options->l = 1;
	}
	flag_options2(options, c);
}

static void	get_files(int i, t_op *options, int argc, char **argv)
{
	if (argc - i == 0)
		create_new_elem(options, ".");
	while (argv[i])
		create_new_elem(options, argv[i++]);
}

t_op		get_options(int argc, char **argv)
{
	int			i;
	int			j;
	t_op		options;

	i = 1;
	initialize_options(&options);
	while (argv[i])
	{
		j = -1;
		if (argv[i][0] != '-')
		{
			get_files(i, &options, argc, argv);
			return (options);
		}
		j++;
		while (argv[i][++j])
		{
			if (ft_strchr("lrRatucg1p", argv[i][j]) == NULL)
				error_option(argv[i][j]);
			flag_options(&options, argv[i][j]);
		}
		i++;
	}
	get_files(i, &options, argc, argv);
	return (options);
}
