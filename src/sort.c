/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:09:25 by adubedat          #+#    #+#             */
/*   Updated: 2016/07/21 19:56:42 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	clean_list(t_files *files)
{
	t_files	*tmp;
	t_files	*temp;

	tmp = files;
	if (tmp->type == -1)
		ft_printf("ls : %s: No such file or directory\n", tmp->file_name);
	while (tmp->next != NULL)
	{
		if (tmp->next->type == -1 || tmp->next->type == 2)
		{
			temp = tmp->next->next;
			if (tmp->next->type == -1)
				ft_printf("ls : %s: No such file or directory\n",
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

void		sort_by_ascii(t_files **files)
{
	t_files	*tmp;
	char	*temp;
	int		type_tmp;

	tmp = *files;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->file_name, tmp->next->file_name) > 0)
		{
			type_tmp = tmp->type;
			temp = tmp->file_name;
			tmp->file_name = tmp->next->file_name;
			tmp->type = tmp->next->type;
			tmp->next->file_name = temp;
			tmp->next->type = type_tmp;
			return (sort_by_ascii(files));
		}
		tmp = tmp->next;
	}
	clean_list(*files);
	if ((*files)->type == -1)
		remove_first_elem(files);
}
