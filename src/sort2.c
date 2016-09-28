/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:35:14 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 17:40:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	compare_time(t_files *tmp, t_files *elem, t_op o)
{
	if (o.u == 1 && o.c == 0
		&& (elem->check.st_atimespec.tv_sec < tmp->check.st_atimespec.tv_sec
		|| (elem->check.st_atimespec.tv_sec == tmp->check.st_atimespec.tv_sec
		&& elem->check.st_atimespec.tv_nsec < tmp->check.st_atimespec.tv_nsec)
		|| (elem->check.st_atimespec.tv_sec == tmp->check.st_atimespec.tv_sec
		&& elem->check.st_atimespec.tv_nsec == tmp->check.st_atimespec.tv_nsec
		&& ft_strcmp(tmp->file_name, elem->file_name) < 0)))
		return (0);
	else if (o.c == 1 && o.u == 0
		&& (elem->check.st_ctimespec.tv_sec < tmp->check.st_ctimespec.tv_sec
		|| (elem->check.st_ctimespec.tv_sec == tmp->check.st_ctimespec.tv_sec
		&& elem->check.st_ctimespec.tv_nsec < tmp->check.st_ctimespec.tv_nsec)
		|| (elem->check.st_ctimespec.tv_sec == tmp->check.st_ctimespec.tv_sec
		&& elem->check.st_ctimespec.tv_nsec == tmp->check.st_ctimespec.tv_nsec
		&& ft_strcmp(tmp->file_name, elem->file_name) < 0)))
		return (0);
	else if ((elem->check.st_mtimespec.tv_sec < tmp->check.st_mtimespec.tv_sec
	|| (elem->check.st_mtimespec.tv_sec == tmp->check.st_mtimespec.tv_sec
	&& elem->check.st_mtimespec.tv_nsec < tmp->check.st_mtimespec.tv_nsec)
	|| (elem->check.st_mtimespec.tv_sec == tmp->check.st_mtimespec.tv_sec
	&& elem->check.st_mtimespec.tv_nsec == tmp->check.st_mtimespec.tv_nsec
	&& ft_strcmp(tmp->file_name, elem->file_name) < 0)) && o.c == 0 && o.u == 0)
		return (0);
	else
		return (1);
}

void		insert_time_sorted(t_files **new, t_files *elem, t_op o)
{
	t_files	*tmp;

	tmp = *new;
	if (tmp == NULL)
	{
		*new = elem;
		return ;
	}
	else if (compare_time(tmp, elem, o) == 1)
	{
		elem->next = (*new);
		*new = elem;
		return ;
	}
	while (tmp->next != NULL && compare_time(tmp->next, elem, o) == 0)
		tmp = tmp->next;
	elem->next = tmp->next;
	tmp->next = elem;
}

static int	compare_revert_time(t_files *tmp, t_files *elem, t_op o)
{
	if (o.u == 1 && o.c == 0
		&& (elem->check.st_atimespec.tv_sec > tmp->check.st_atimespec.tv_sec
		|| (elem->check.st_atimespec.tv_sec == tmp->check.st_atimespec.tv_sec
		&& elem->check.st_atimespec.tv_nsec > tmp->check.st_atimespec.tv_nsec)
		|| (elem->check.st_atimespec.tv_sec == tmp->check.st_atimespec.tv_sec
		&& elem->check.st_atimespec.tv_nsec == tmp->check.st_atimespec.tv_nsec
		&& ft_strcmp(tmp->file_name, elem->file_name) > 0)))
		return (0);
	else if (o.c == 1 && o.u == 0
		&& (elem->check.st_ctimespec.tv_sec > tmp->check.st_ctimespec.tv_sec
		|| (elem->check.st_ctimespec.tv_sec == tmp->check.st_ctimespec.tv_sec
		&& elem->check.st_ctimespec.tv_nsec > tmp->check.st_ctimespec.tv_nsec)
		|| (elem->check.st_ctimespec.tv_sec == tmp->check.st_ctimespec.tv_sec
		&& elem->check.st_ctimespec.tv_nsec == tmp->check.st_ctimespec.tv_nsec
		&& ft_strcmp(tmp->file_name, elem->file_name) > 0)))
		return (0);
	else if ((elem->check.st_mtimespec.tv_sec > tmp->check.st_mtimespec.tv_sec
	|| (elem->check.st_mtimespec.tv_sec == tmp->check.st_mtimespec.tv_sec
	&& elem->check.st_mtimespec.tv_nsec > tmp->check.st_mtimespec.tv_nsec)
	|| (elem->check.st_mtimespec.tv_sec == tmp->check.st_mtimespec.tv_sec
	&& elem->check.st_mtimespec.tv_nsec == tmp->check.st_mtimespec.tv_nsec
	&& ft_strcmp(tmp->file_name, elem->file_name) > 0)) && o.c == 0 && o.u == 0)
		return (0);
	else
		return (1);
}

void		insert_revert_time(t_files **new, t_files *elem, t_op o)
{
	t_files	*tmp;

	tmp = *new;
	if (tmp == NULL)
	{
		*new = elem;
		return ;
	}
	else if (compare_revert_time(tmp, elem, o) == 1)
	{
		elem->next = (*new);
		*new = elem;
		return ;
	}
	while (tmp->next != NULL && compare_revert_time(tmp->next, elem, o) == 0)
		tmp = tmp->next;
	elem->next = tmp->next;
	tmp->next = elem;
}
