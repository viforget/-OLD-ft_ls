/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/03/22 15:27:15 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	ft_ls(int flag, char *str);

int		alprime(char *str)
{
	int i;
	int nbr;

	i = 1;
	nbr = 1;
	while(str[i])
	{
		if (str[i] == 'a' && nbr % 2 != 0)
			nbr *= 2;
		else if (str[i] == 'l' && nbr % 3 != 0)
			nbr *= 3;
		else if (str[i] == 'r' && nbr % 5 != 0)
			nbr *= 5;
		else if (str[i] == 'R' && nbr % 7 != 0)
			nbr *= 7;
		else if (str[i] == 't' && nbr % 11 != 0)
			nbr *= 11;
		i++;
	}
	return (nbr);
}

void	ft_affls(DIR *dir, int flag)
{
	struct dirent *rep;

	rep = readdir(dir);
	while(rep)
	{
		if (!(rep->d_name[0] == '.' && flag % 2 != 0))
			ft_putendl(rep->d_name);
		rep = readdir(dir);
	}
}

void	ft_recursive_ls(char *str, int flag)
{
	DIR				*dir;
	struct dirent	 *rep;

	dir = opendir(str);
	str = ft_strjoin(str, "/");
	rep = readdir(dir);
	rep = readdir(dir);
	rep = readdir(dir);
	while(rep)
	{
		if (rep->d_type == 4 && !(flag % 2 != 0 && rep->d_name[0] == '.'))
		{
			ft_putchar('\n');
			ft_ls((flag % 13 == 0) ? flag : flag * 13, ft_strjoin(str, rep->d_name)); //Malloc Warning
		}
		rep = readdir(dir);
	}
}

void	ft_ls(int flag, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (flag % 13 == 0)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	if (dir != NULL)
	{
		ft_affls(dir, flag);
		closedir(dir);
	} //Penser a PE free dir en cas d'erreur
	if (flag % 7 == 0)
	{
		ft_recursive_ls(str, flag);
	}
}

void	ft_sort_tab(char **tab, int i)
{
	int j;
	char *st;

	j = i;
	while(tab[j + 1])
	{
		if (ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			st = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = st;
			j = i;
		}
		else
			j++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		flag *= alprime(argv[i]);
		i++;
	}
	if (i < argc - 1)
		flag *= 13;
	if (argv[i])
	{
		ft_sort_tab(argv, i);
		while (argv[i])
		{
			ft_ls(flag, argv[i++]);
			if (argv[i])
				ft_putchar('\n');
		}
	}
	else
		ft_ls(flag, ".");
}
