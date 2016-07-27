/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:09:25 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/27 19:08:12 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	clean_list(t_files *files)
{
	t_files	*tmp;
	t_files	*temp;

	tmp = files;
	if (tmp->type == -1)
		ft_printf("ls: %s: No such file or directory\n", tmp->file_name);
	while (tmp->next != NULL)
	{
		if (tmp->next->type == -1 || tmp->next->type == 2)
		{
			temp = tmp->next->next;
			if (tmp->next->type == -1)
				ft_printf("ls: %s: No such file or directory\n",
				   	tmp->next->file_name);
			free(tmp->next->file_name);
			free(tmp->next);
			tmp->next = temp;
		}
		else
			tmp = tmp->next;
	}
}

static void		remove_first_elem(t_files **files)
{
	t_files *tmp;

	tmp = *files;
	*files = (*files)->next;
	free(tmp->file_name);
	free(tmp);
}

static void		insert_sorted(t_files **new, t_files *elem)
{
	t_files *tmp;

	tmp = *new;
	if (tmp == NULL)
	{
		*new = elem;
		return ;
	}
	else if (ft_strcmp(tmp->file_name, elem->file_name) > 0)
	{
		elem->next = (*new);
		*new = elem;
		return ;
	}
	while (tmp->next != NULL && ft_strcmp(tmp->next->file_name, elem->file_name) < 0)
		tmp = tmp->next;
	elem->next = tmp->next;
	tmp->next = elem;
}

static void		insert_revert_sorted(t_files **new, t_files *elem)
{
	t_files *tmp;

	tmp = *new;
	if (tmp == NULL)
	{
		*new = elem;
		return ;
	}
	else if (ft_strcmp(tmp->file_name, elem->file_name) < 0)
	{
		elem->next = (*new);
		*new = elem;
		return ;
	}
	while (tmp->next != NULL && ft_strcmp(tmp->next->file_name, elem->file_name) > 0)
		tmp = tmp->next;
	elem->next = tmp->next;
	tmp->next = elem;
}

void			sort(t_op *options)
{
	t_files	*tmp;
	t_files	*next;
	t_files *new_list;

	tmp = options->files;
	new_list = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		tmp->next = NULL;
		if (options->r == 1)
			insert_revert_sorted(&new_list, tmp);
//		else if (options->t = 1)
//			insert_time_sorted(&new_list, tmp);
		else
			insert_sorted(&new_list, tmp);
		tmp = next;
	}
	options->files = new_list;
	clean_list(options->files);
	if (options->files->type == -1 || options->files->type == 2)
		remove_first_elem(&(options->files));
}
