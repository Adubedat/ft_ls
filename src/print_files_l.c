/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:30:37 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/11 22:04:53 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_len	init_len(t_len len)
{
	len.blk = 0;
	len.lnk = 1;
	len.owner = 1;
	len.group = 1;
	len.bytes = 1;
	len.day = 1;
	len.date = 4;
	return (len);
}

static t_len	count_len(t_files *files)
{
	t_files *tmp;
	t_len	len;

	len = init_len(len);
	tmp = files;
	while (tmp != NULL)
	{
		len.blk  = len.blk + tmp->check.st_blocks;
		if (ft_intlen(tmp->check.st_nlink) > len.lnk)
			len.lnk = ft_intlen(tmp->check.st_nlink);
		if (ft_strlen(tmp->check.st_uid) > len.owner)
			len.owner = ft_strlen(tmp->check.st_uid);
		if (ft_strlen(tmp->check.st_gid) > len.group)
			len.group = ft_strlen(tmp->check.st_gid);
		if (ft_intlen(tmp->check.st_size) > len.bytes)
			len.bytes = ft_strlen(tmp->check.st_size);
		tmp = tmp->next;
	}
	return (len);
}

void			print_files_l(t_op options)
{
	t_len	len;
	t_files	*tmp;

	len = count_len(options.files);
	if (options.flag && blk_nbr != 0)
		ft_printf("total %d\n", len.blk);
	tmp = options.files;
	while (tmp != NULL)
	{
		if (options.flag == 1 || (tmp->type != 0 && tmp->type != 3))
			print_type(tmp);
		tmp = tmp->next;
	}
}
