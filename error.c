/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:27:08 by viforget          #+#    #+#             */
/*   Updated: 2019/05/28 15:07:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_putillop(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-Ralrt1] [file ...]\n");
	return (0);
}

void	errpermden(char *str)
{
	int i;

	i = ft_strlen(str);
	while(str[i] != '/' && i > 0)
		i--;
	if (ft_strrchr(str, '/') == NULL || i == 0)
		i = -1;
	ft_putstr("ft_ls: ");
	ft_putstr(str + i + 1);
	ft_putstr(": Permission denied\n");
}

void	ft_enoent(char *str)
{
	int i;

	i = ft_strlen(str);
	while(str[i] != '/' && i > 0)
		i--;
	if (ft_strrchr(str, '/') == NULL || i == 0)
		i = -1;
	ft_putstr("ft_ls: ");
	ft_putstr(str + i + 1);
	ft_putstr(": No such file or directory\n");
}

void	ft_enotdir(char *str, int flag)
{
	char **itab;

	itab = NULL;
	if (flag % 3 == 0)
	{
		ft_addinfo(itab, str, DT_REG, str);
	}
	else
		ft_putendl(str);
}

void	ft_puterror(char *str, int e, int flag)
{
	int i;//Just for -Werror

	i = flag;//Just for -Werror
	e == EACCES ? errpermden(str) : 3000 ;
	//e == ENOTDIR ? ft_enotdir(str, flag) : 19;
	e == ENOENT ? ft_enoent(str): 42 ;

}
