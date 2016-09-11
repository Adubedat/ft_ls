/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:01:34 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/11 20:45:32 by adubedat         ###   ########.fr       */
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

static int	test_blk_chr(struct stat check)
{
	if (S_ISBLK(check.st_mode))
		return (5);
	else if (S_ISCHR(check.st_mode))
		return (6);
	else if (S_ISSOCK(check.st_mode))
		return (7);
	else
		return (8);
}

static int	test_lnk(char *join, char *name, t_op *o)
{
	struct stat	check;

	if (o->path == NULL)
		stat(name, &check);
	else
		stat(ft_strjoin(join, name), &check);
	if (S_ISDIR(check.st_mode))
		return (3);
	else
		return (4);
}

void		create_new_elem(t_op *o, char	*name)
{
	t_files		*new;
	char		*join;
	int			ok;

	ok = is_valid(o, name);
	new = (t_files *)malloc(sizeof(t_files));
	join = ft_strjoin(o->path, "/");
	if ((o->path == NULL && lstat(name, &(new->check)) == -1)
	|| (o->path != NULL && lstat(ft_strjoin(join, name), &(new->check)) == -1))
		new->type = -1;
	else if ((S_ISCHR(new->check.st_mode) || S_ISBLK(new->check.st_mode) 
	|| S_ISSOCK(new->check.st_mode) || S_ISFIFO(new->check.st_mode)) && ok == 1)
		new->type = test_blk_chr(new->check);
	else if (S_ISLNK(new->check.st_mode) && ok == 1)
		new->type = test_lnk(join, name, o);
	else if (new->check.st_mode & S_IFDIR && ok == 1)
		new->type = 0;
	else if ((new->check.st_mode & S_IFREG && ok == 1) || o->flag == 0)
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
** 3 = symbolic link repertory
** 4 = symbolic link file
** 5 = bloc mode
** 6 = caractere mode
** 7 = socket mode
** 8 = FIFO mode
*/
