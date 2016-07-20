/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:42:15 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/19 18:14:22 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			open_error(char *str)
{
	ft_printf("Open directory %s failed", str);
	exit(1);
}

static void		create_file_elem(t_files **file_list, char *name)
{
	t_files *new;

	new = (t_files *)malloc(sizeof(t_files));
	new->file_name = ft_strdup(name);
	new->next = (*file_list);
	(*file_list) = new;
}

static void		get_files_list(int f_nb, t_files *f_list, t_op *o, t_op op)
{
	t_files		*tmp;
	struct stat	check;
	int			j;
	int			k;

	j = 0;
	k = 0;
	tmp = f_list;
	o->files = (char**)malloc(sizeof(char*) * f_nb + 1);
	o->rep = (char**)malloc(sizeof(char*) * f_nb + 1);
	while (tmp != NULL)
	{
		if (stat(ft_strjoin(o->path, tmp->file_name), &check) == -1)
			ft_printf("ls: %s: No such file or directory\n", tmp->file_name);
		else if (check.st_mode & S_IFDIR && (op.a == 1 || (op.a == 0 
					&& tmp->file_name[0] != '.')))
			o->rep[j++] = ft_strdup(tmp->file_name);
		else if (check.st_mode & S_IFREG && (op.a == 1 || (op.a == 0
					&& tmp->file_name[0] != '.')))
			o->files[k++] = ft_strdup(tmp->file_name);
		tmp = tmp->next;
	}
	o->rep[j] = NULL;
	o->files[k] = NULL;
	free_list(f_list);
}
	
static void	get_rep_files(char *rep, t_op *o, t_op options)
{
	DIR				*dir;
	struct dirent	*file;
	t_files			*file_list;
	int				file_nbr;
	t_files			*temp;

	file_list = NULL;
	file_nbr = 0;
	if ((dir = opendir(rep)) == NULL)
		open_error(rep);
	while ((file = readdir(dir)) != NULL)
		create_file_elem(&file_list, file->d_name);
	temp = file_list;
	while (temp != NULL)
	{
		file_nbr++;
		temp = temp->next;
	}
	get_files_list(file_nbr, file_list, o, options);
	sort_by_ascii(o->files, 0);
	sort_by_ascii(o->rep, 0);
	print_files((*o));
}

void			print_rep(t_op options)
{
	int			i;
	int			len;
	t_op		o;

	i = 0;
	len = 0;
	while (options.rep[i] != NULL)
	{
		copy_options(&o, options);
	//	o.flag = 1;
	//	o.path = ft_strjoin(options.rep[i], "/");
		ft_printf(" test : %s\n", o.path);
		if (count_files(options, &len) > 1)
			ft_printf("\n%s:\n", o.path);
		get_rep_files(options.rep[i], &o, options);
		if (options.maj_r == 1)
		{
		//	o.path = ft_strjoin(options.path, "/");
			o.path = ft_strjoin(o.path, options.rep[i]);
		//	add_path(&o, i);		/// a faire
			print_rep(o);
		}
		free_options(&o);
		i++;
	}
}
