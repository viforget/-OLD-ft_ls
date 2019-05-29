/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:37:52 by viforget          #+#    #+#             */
/*   Updated: 2019/05/28 16:40:38 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_just_name_of_file(char **argv, int i, int ct)
{
	char	b;
	char	b2;
	DIR		*dir;

	b = 0;
	b2 = 0;
	while (i < ct)
	{
		dir = opendir(argv[i]);
		if (dir == NULL && errno == ENOTDIR)
		{
			b = 1;
			ft_putendl(argv[i]);
		}
		dir != NULL ? b2 = 1 : 19;
		i++;
	}
	if (b == 1 && b2 == 1)
		ft_putchar('\n');
}

char	puttype(char *str)
{
	struct stat buf;

	lstat(str, &buf);
	if (S_ISREG(buf.st_mode))
		return (8);
	else if (S_ISDIR(buf.st_mode))
		return (4);
	else if (S_ISCHR(buf.st_mode))
		return (2);
	else if (S_ISBLK(buf.st_mode))
		return (3);
	else if (S_ISFIFO(buf.st_mode))
		return (1);
	else if (S_ISLNK(buf.st_mode))
		return (10);
	else if (S_ISSOCK(buf.st_mode))
		return (12);
	return (0);
}

void	ft_file(char **argv, int i, int ct, int flag)
{
	DIR				*dir;
	char			**tab;
	unsigned char	*type;
	int				j;

	j = 0;
	if (flag % 3 == 0)
	{
		tab = (char **)ft_memalloc(sizeof(char *) * (ct - i + 1));
		type = (unsigned char *)ft_memalloc(sizeof(unsigned char) * ct - i);
		//ft_memset(type, DT_REG, ct - i);
		while (i < ct)
		{
			dir = opendir(argv[i]);
			if (errno == ENOTDIR && dir == NULL)
			{
				type[j] = puttype(argv[i]);
				tab[j] = ft_strdup(argv[i]);
				j++;
			}
			i++;
		}
		if (j != 0)
		{
			ft_addinfotab2(tab, j, type, ft_strdup("./"));
			ft_puttab(tab, j);
		}
		while (ct > i)
		{
			if (tab[ct - 1])
				ft_strdel(&tab[ct - 1]);
			ct--;
		}
		//free(&tab);
	}
	else
		ft_just_name_of_file(argv, i, ct);
}
