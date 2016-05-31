/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:02:15 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/31 20:14:05 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_files *list)
{
	t_files *tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->file_name);
		free(list);
		list = tmp;
	}
}

void	free_options(t_op *options)
{
	int		i;

	i = 0;
	free(options->path);
	while (options->files[i])
	{
		free(options->files[i]);
		i++;
	}
	free(options->files);
	i = 0;
	while (options->rep[i])
	{
		free(options->rep[i]);
		i++;
	}
	free(options->rep);
}
