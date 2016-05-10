/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:09:13 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/10 19:03:01 by adubedat         ###   ########.fr       */
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
	options->files = NULL;
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

static void	get_files(int i, t_options *options, int argc, char **argv)
{
	int			j;
	int			k;
	struct stat check;

	j = 0;
	k = 0;
	options->files = (char**)malloc(sizeof(char*) * (argc - i) + 1);
	options->rep = (char**)malloc(sizeof(char*) * (argc - i) + 1);
	if (argc - i == 0)
	{
		options->rep = (char**)malloc(sizeof(char*) * 2);
		options->rep[j++] = ft_strdup(".");
	}
	while (argv[i])
	{
		if (stat(argv[i], &check) == -1)
			ft_printf("ls: %s: No such file or directory\n", argv[i]);
		else if (check.st_mode & S_IFDIR)
			options->rep[j++] = ft_strdup(argv[i]);
		else if (check.st_mode & S_IFREG)
			options->files[k++] = ft_strdup(argv[i]);
		i++;
	}
	options->rep[j] = NULL;
	options->files[k] = NULL;
}

t_options	get_options(int argc, char **argv)
{
	int			i;
	int			j;
	t_options	options;

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
			if (ft_strchr("lrRatGufgd", argv[i][j]) == NULL)
				error_option(argv[i][j]);
			flag_options(&options, argv[i][j]);
		}
		i++;
	}
	get_files(i, &options, argc, argv);
	return (options);
}
