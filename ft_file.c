/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:37:52 by viforget          #+#    #+#             */
/*   Updated: 2019/05/10 15:27:57 by viforget         ###   ########.fr       */
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
	while(i < ct)
	{
		dir = opendir(argv[i]);
		if (dir == NULL && errno == ENOTDIR)
		{
			b = 1;
			ft_putendl(argv[i]);
		}
		dir != NULL ? b2 = 1: 19;
		i++;
		
	}
	if (b == 1 && b2 == 1)
		ft_putchar('\n');
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
		ft_memset(type, DT_REG, ct - i);
		while (i < ct)
		{
			dir = opendir(argv[i]);
			if(errno == ENOTDIR && dir == NULL)
			{
				tab[j++] = argv[i];
			}
			i++;
		}
		ft_addinfotab(tab, j, type, ft_strdup("./"));
		ft_putchar('Z');
	}
	else
		ft_just_name_of_file(argv, i, ct);
	/*while(i < ct)
	{
		dir = opendir(argv[i]);
		if (errno == ENOTDIR)
		{
			if (flag % 3 == 0)
				tab[j++] = ft_strdup(argv[i]);
			else
			{
				ft_putendl(argv[i]);
				j = 1;
			}
		}
		i++;
	}*/
}
