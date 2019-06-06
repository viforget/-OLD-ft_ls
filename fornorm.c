/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fornorm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:11:05 by viforget          #+#    #+#             */
/*   Updated: 2019/06/06 20:16:06 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		freeandret(char **s)
{
	ft_strdel(s);
	return (0);
}

void	ft_freedom(char **s, char **tab, size_t ct, unsigned char **type)
{
	ft_strdel(s);
	ft_puttab(tab, ct);
	ft_memdel((void **)type);
	ft_tabdel(tab, ct);
}

void	ft_sorting(char **tab, size_t ct, int flag)
{
	flag % 11 == 0 ? ft_sort_ls_t(tab, 0, ct) : ft_sort_ls(tab, 0, ct);
	flag % 5 == 0 ? ft_reverse_tab(tab, ct, 0) : 19;
}

void	readdir2(DIR *dir)
{
	readdir(dir);
	readdir(dir);
}

void	ft_afffile(char **tab, int j, unsigned char *type, int flag)
{
	ft_addinfotab2(tab, j, type, ft_strdup("./"));
	ft_puttab(tab, j);
	flag % 17 == 0 ? ft_putchar('\n') : 0;
}
