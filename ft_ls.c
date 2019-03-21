/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/03/21 01:36:18 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

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

void	ft_ls(int flag, char *str)
{
	DIR *dir;

	dir = opendir(str);
	if (dir != NULL)
	{
		ft_affls(dir, flag);
		closedir(dir);
	} //Penser a PE free dir en cas d'erreur
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
	if (argv[i])
	{
		while (argv[i])
			ft_ls(flag, argv[i++]);
	}
	else
	{
		ft_ls(flag, "./");
	}
}
