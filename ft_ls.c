/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/03/20 14:21:21 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*rep;

	if (argc > 1)
		dir = opendir(argv[1]);
	else 
		dir = opendir("./");
	rep = readdir(dir);
	while (rep != NULL)
	{
		if (rep->d_name[0] != '.')
		printf("%s\n", rep->d_name);
		rep = readdir(dir);
	}
}
