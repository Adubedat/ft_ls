/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:42:15 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/26 19:32:13 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			open_error(char *str)
{
	ft_printf("Open directory %s failed", str);
	exit(1);
}

static void	get_rep_files(char *rep, t_op *o)
{
	DIR				*dir;
	struct dirent	*file;
	int				file_nbr;

	file_nbr = 0;
	if ((dir = opendir(rep)) == NULL)
		open_error(rep);
	while ((file = readdir(dir)) != NULL)
		create_new_elem(o, file->d_name);
	sort_by_ascii(&o->files);
	print_files((*o));
}

void			print_rep(t_op options)
{
	t_files		*tmp;
	int			len;
	t_op		o;

	tmp = options.files;
	len = 0;
	while (tmp != NULL)
	{
		if (tmp->type == 0)
		{
			copy_options(&o, options, tmp->file_name);
			if (options.flag == 1)
				ft_printf("\n%s:\n", o.path);
			get_rep_files(o.path, &o);
			if (options.maj_r == 1)
				print_rep(o);
		//	free_options(&o);
		}
		tmp = tmp->next;
	}
}
