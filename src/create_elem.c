/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:01:34 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/27 16:27:05 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_valid(t_op *o, char *name)
{
	if (o->a == 1 || o->flag == 0 || (o->a == 0 && name[0] != '.'))
		return (1);
	else
		return (0);
}

void		create_new_elem(t_op *o, char	*name)
{
	struct stat	check;
	t_files		*new;
	char		*join;
	int			valid;

	valid = is_valid(o, name);
	new = (t_files *)malloc(sizeof(t_files));
	join = ft_strjoin(o->path, "/");
	if ((o->path == NULL && lstat(name, &check) == -1)
		|| (o->path != NULL && lstat(ft_strjoin(join, name), &check) == -1))
		new->type = -1;
	else if (S_ISLNK(check.st_mode) && valid == 1)
		new->type = 3;
	else if (check.st_mode & S_IFDIR && valid == 1)
		new->type = 0;
	else if ((check.st_mode & S_IFREG && valid == 1) || o->flag == 0)
		new->type = 1;
	else
		new->type = 2;
	new->file_name = ft_strdup(name);
	new->next = o->files;
	o->files = new;
	free(join);
}

/* -1 = wrong file
** 0 = Directory
** 1 = Normal file
** 2 = File to clean
** 3 = symbolic link
*/
