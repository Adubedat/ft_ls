/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:01:34 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/20 17:42:47 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	create_new_elem(t_op *options, char	*name)
{
	struct stat	check;
	t_files		*new;

	new = (t_files *)malloc(sizeof(t_files));
	if (stat(name, &check) == -1)
		new->type = -1;
	else if (check.st_mode & S_IFDIR)
		new->type = 0;
	else if (check.st_mode & S_IFREG)
		new->type = 1;
	new->file_name = ft_strdup(name);
	new->next = options->files;
	options->files = new;
}
