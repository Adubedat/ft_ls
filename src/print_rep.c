/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:42:15 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/11 23:30:14 by adubedat         ###   ########.fr       */
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
}

static void	get_rep_files(char *rep)
{
	DIR				*dir;
	struct dirent	*file;
	t_files			*file_list;

	if ((dir = opendir(rep)) == NULL)
		open_error(rep);
	while ((file = readdir(dir)) != NULL)
		create_file_elem(&file_list, file->d_name);
	t_files *temp;
	temp = file_list;
	while (temp != NULL)
	{
		ft_printf("%s\n", temp->file_name);
		temp = temp->next;
	}
}

void			print_rep(t_options options)
{
	int i;
	char **tab;
	int		len;

	i = 0;
	len = 0;
	while (options.rep[i] != NULL)
	{
			ft_putchar('\n');
		if (count_files(options, &len) > 1)
			ft_printf("%s:\n", options.rep[i]);
		get_rep_files(options.rep[i]);
		i++;
	}
}


/////////// SEGFAUUUUULT
