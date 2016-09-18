/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 17:18:11 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/18 19:31:40 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_all_rights(t_files *tmp)
{
	if (tmp->check.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_ISVTX && !(tmp->check.st_mode & S_IXOTH))
		ft_putchar('T');
	else if (tmp->check.st_mode & S_ISVTX && tmp->check.st_mode & S_IXOTH)
		ft_putchar('t');
	else if (tmp->check.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putstr("  ");
}

static void	print_grp_rights(t_files *tmp)
{
	if (tmp->check.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_ISGID && !(tmp->check.st_mode & S_IXGRP))
		ft_putchar('S');
	else if (tmp->check.st_mode & S_ISGID && tmp->check.st_mode & S_IXGRP)
		ft_putchar('s');
	else if (tmp->check.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	print_all_rights(tmp);
}

static void	print_usr_rights(t_files *tmp)
{
	if (tmp->check.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (tmp->check.st_mode & S_ISUID && !(tmp->check.st_mode & S_IXUSR))
		ft_putchar('S');
	else if (tmp->check.st_mode & S_ISUID && tmp->check.st_mode & S_IXUSR)
		ft_putchar('s');
	else if (tmp->check.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	print_grp_rights(tmp);
}

void		print_type(t_files *tmp)
{
	if (tmp->type == 0)
		ft_putchar('d');
	else if (tmp->type == 3 || tmp->type == 4)
		ft_putchar('l');
	else if (tmp->type == 5)
		ft_putchar('b');
	else if (tmp->type == 6)
		ft_putchar('c');
	else if (tmp->type == 7)
		ft_putchar('s');
	else if (tmp->type == 8)
		ft_putchar('p');
	else
		ft_putchar('-');
	print_usr_rights(tmp);
}
