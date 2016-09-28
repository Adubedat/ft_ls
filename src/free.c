/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:03:10 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 16:24:37 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_options(t_op *option)
{
	t_files *tmp;
	t_files *tmp_next;

	tmp = option->files;
	if (option->path != NULL)
		free(option->path);
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		if (tmp->file_name != NULL)
			free(tmp->file_name);
		free(tmp);
		tmp = tmp_next;
	}
}
