/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:42:15 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 16:14:56 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_rep_files(char *rep, t_op *o)
{
	DIR				*dir;
	struct dirent	*file;
	int				file_nbr;

	errno = 0;
	file_nbr = 0;
	if ((dir = opendir(rep)) == NULL)
	{
		perror(rep);
		return ;
	}
	while ((file = readdir(dir)) != NULL)
		create_new_elem(o, file->d_name);
	sort(o);
	if (o->l == 1)
		print_files_l((*o));
	else
		print_files((*o));
	if (closedir(dir) == -1)
	{
		perror(rep);
		return ;
	}
}

static int		count_files2(t_op options)
{
	t_files *tmp;
	int		file_nbr;

	file_nbr = 0;
	tmp = options.files;
	while (tmp != NULL)
	{
		file_nbr++;
		tmp = tmp->next;
	}
	return (file_nbr);
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
		if ((tmp->type == 0 || (tmp->type == 3 && options.flag == 0))
			&& (ft_strcmp(tmp->file_name, ".") != 0 || options.flag == 0)
			&& ft_strcmp(tmp->file_name, "..") != 0)
		{
			copy_options(&o, options, tmp->file_name);
			if (options.flag == 1 || count_files2(options) > 1)
				ft_printf("\n%s:\n", o.path);
			get_rep_files(o.path, &o);
			if (options.maj_r == 1)
			{
				print_rep(o);
				free_options(&o);
			}
		}
		tmp = tmp->next;
	}
}
