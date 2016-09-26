/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:30:37 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/26 18:12:33 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_len	init_len(void)
{
	t_len	len;

	len.blk = 0;
	len.lnk = 1;
	len.owner = 1;
	len.group = 1;
	len.bytes = 1;
	len.major = 0;
	len.minor = 0;
	return (len);
}

static t_len	count_len2(t_len len, t_files *tmp)
{
	if ((tmp->type == 5 || tmp->type == 6)
			&& ft_intlen(minor(tmp->check.st_rdev)) > len.minor)
		len.minor = ft_intlen(minor(tmp->check.st_rdev));
	return (len);
}

static t_len	count_len(t_files *files)
{
	t_files *tmp;
	t_len	len;

	len = init_len();
	tmp = files;
	while (tmp != NULL)
	{
		tmp->gid = getgrgid(tmp->check.st_gid);
		tmp->uid = getpwuid(tmp->check.st_uid);
		len.blk  = len.blk + tmp->check.st_blocks;
		if (ft_intlen(tmp->check.st_nlink) > len.lnk)
			len.lnk = ft_intlen(tmp->check.st_nlink);
		if (ft_strlen(tmp->uid->pw_name) > len.owner)
			len.owner = ft_strlen(tmp->uid->pw_name);
		if (ft_strlen(tmp->gid->gr_name) > len.group)
			len.group = ft_strlen(tmp->gid->gr_name);
		if (ft_intlen(tmp->check.st_size) > len.bytes)
			len.bytes = ft_intlen(tmp->check.st_size);
		if ((tmp->type == 5 || tmp->type == 6)
				&& ft_intlen(major(tmp->check.st_rdev)) > len.major)
			len.major = ft_intlen(major(tmp->check.st_rdev));
		len = count_len2(len, tmp);
		tmp = tmp->next;
	}
	return (len);
}

static void		print_files_l2(t_len len, t_files *tmp)
{
	if (len.minor != 0)
	{
		if (tmp->type == 5 || tmp->type == 6)
			ft_printf("%*d ", len.minor, minor(tmp->check.st_rdev));
		else
			ft_printf("%*d ", len.minor, tmp->check.st_size);
	}
	else
		ft_printf("%*d ", len.bytes, tmp->check.st_size);
	print_time(tmp);
	print_name(tmp);
}

void			print_files_l(t_op options)
{
	t_len	len;
	t_files	*tmp;

	len = count_len(options.files);
	if (options.flag && len.blk != 0)
		ft_printf("total %d\n", len.blk);
	tmp = options.files;
	while (tmp != NULL)
	{
		if (options.flag == 1 || (tmp->type != 0 && tmp->type != 3))
		{
			print_type(tmp);
			ft_printf("%-*d%-*s%-*s", len.lnk + 1, tmp->check.st_nlink,
			len.owner + 2, tmp->uid->pw_name, len.group + 2, tmp->gid->gr_name);
			if (len.major != 0)
			{
				if (tmp->type == 5 || tmp->type == 6)
					ft_printf(" %*d, ", len.major, major(tmp->check.st_rdev));
				else
					ft_printf(" %*s  ", len.major, " ");
			}
			print_files_l2(len, tmp);
		}
		tmp = tmp->next;
	}
}
