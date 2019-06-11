/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:50:42 by viforget          #+#    #+#             */
/*   Updated: 2019/06/11 09:56:59 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** When the flag "-l" is activate, this function count the maximum number of
**character in each column
** ***itab is a tab of tab of str, the function will count in it
** ct is the number of line, the max value of **itab
*/

int		*cntlen(char ***itab, int ct)
{
	int		i;
	int		j;
	int		*len;

	len = ft_memalloc(sizeof(int) * 8);
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < ct && itab[i][j])
		{
			if (ft_strlen(itab[i][j]) > (size_t)len[j])
			{
				len[j] = ft_strlen(itab[i][j]);
			}
			i++;
		}
		if (j == 1 || j == 3 || j == 4)
			len[j] += len[j - 1] + 2;
		else if (j != 0)
			len[j] += len[j - 1] + 1;
		j++;
	}
	return (len);
}

void	ft_sort_tab_dir(struct dirent **tr, int flag)
{
	int				j;
	struct dirent	*st;
	struct stat		b1;
	struct stat		b2;

	j = 0;
	while (tr[j + 1])
	{
		if (flag % 11 == 0)
		{
			stat(tr[j]->d_name, &b1);
			stat(tr[j + 1]->d_name, &b2);
		}
		if ((flag % 11 == 0 ? b1.st_mtime < b2.st_mtime :
					ft_strcmp(tr[j]->d_name, tr[j + 1]->d_name) > 0) +
					(flag % 5 == 0) % 2)
		{
			st = tr[j];
			tr[j] = tr[j + 1];
			tr[j + 1] = st;
			j > 0 ? j-- : (j = 0);
		}
		else
			j++;
	}
}

void	ft_sort_ls_t(char **tab, size_t i, size_t ct)
{
	size_t		j;
	char		*st;
	struct stat	bf1;
	struct stat	bf2;

	j = i;
	while (j - i <= ct && tab[j + 1])
	{
		if ((lstat(tab[j], &bf1) == -1) || (lstat(tab[j + 1], &bf2) == -1))
			return ;
		if (bf1.st_mtime < bf2.st_mtime)
		{
			st = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = st;
			j > i ? j-- : (j = i);
		}
		else
			j++;
	}
}

void	ft_sort_ls(char **tab, size_t i, size_t ct)
{
	size_t		j;
	char		*st;

	j = i;
	while (j - i < ct - 1 && tab[j + 1])
	{
		if (ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			st = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = st;
			j > i ? j-- : (j = i);
		}
		else
		{
			j++;
		}
	}
}

/*
** Reverse the result if the flag "-r" is activated
*/

void	ft_reverse_tab(char **tab, size_t ct, int i)
{
	char	*buf;

	ct--;
	while ((size_t)i < ct)
	{
		buf = tab[i];
		tab[i] = tab[ct];
		tab[ct] = buf;
		i++;
		ct--;
	}
}
