/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:20:19 by viforget          #+#    #+#             */
/*   Updated: 2019/04/13 11:30:35 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*setright(int mode, char c)
{
	char	right[13];

	right[0] = c;
	mode % 2 == 1 ? right[9] = 'x' :
		(right[9] = '-');
	mode % 4 >= 2 ? right[8] = 'w' :
		(right[8] = '-');
	mode % 8 >= 4 ? right[7] = 'r' :
		(right[7] = '-');
	mode % 16 >= 8 ? right[6] = 'x' :
		(right[6] = '-');
	mode % 32 >= 16 ? right[5] = 'w' :
		(right[5] = '-');
	mode % 64 >= 32 ? right[4] = 'r' :
		(right[4] = '-');
	mode % 128 >= 64 ? right[3] = 'x' :
		(right[3] = '-');
	mode % 256 >= 128 ? right[2] = 'w' :
		(right[2] = '-');
	mode % 512 >= 256 ? right[1] = 'r' :
		(right[1] = '-');
	right[10] = ' ';
	right[11] = ' ';
	right[12] = '\0';
	return (ft_strdup(right));
}

char	*setdate(char **date, char *str, char *size, time_t ct)
{
	date[4][4] = '\0';
	date[3][5] = '\0';
	str = ft_strjoin("  ", str);
	if ((ct - time(NULL) > -15778800) && (ct - time(NULL) < 3600))
		str = ft_strjoindele(date[3], str);
	else
		str = ft_strjoindele(date[4], str);
	str = ft_strjoindele("  ", str);
	str = ft_strjoindele(date[2], str);
	str = ft_strjoindele("  ", str);
	str = ft_strjoindele(date[1], str);
	str = ft_strjoindele("  ", str);
	str = ft_strjoindel2(size, str);
	str = ft_strjoindele("  ", str);
	//ft_putendl(date[3]);
	str = ft_strjoindele(date[4], str);
	//ft_strdel(&size);
	return (str);
}

void	ft_addinfo(char **str, unsigned char type)
{
	struct stat		 stt;
	struct passwd	*ginfo;
	char			*right;
	char			**date;

	stat(*str, &stt);
	ginfo = getpwuid(stt.st_uid);
	right = setright(stt.st_mode, TYPE[type]);
	date = ft_strsplit(ctime(&stt.st_mtime), ' ');
	*str = setdate(date, *str, ft_itoa(stt.st_size), stt.st_mtime);
	*str = ft_strjoindele("  ", *str);
	*str = ft_strjoindele(ginfo->pw_name, *str);
	*str = ft_strjoindele("  ", *str);
	*str = ft_strjoindel2(ft_itoa(stt.st_nlink), *str);
	*str = ft_strjoindel2(right, *str); //END
}

void	ft_addinfotab(char **tab, size_t ct, unsigned char *type)
{
	int i;

	i = 0;
	while (i < ct)
	{
		ft_addinfo(&tab[i], type[i]);
		i++;
	}
	//ft_puttab(tab, ct);
}
