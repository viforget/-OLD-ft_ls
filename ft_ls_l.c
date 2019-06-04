/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:20:19 by viforget          #+#    #+#             */
/*   Updated: 2019/06/04 19:43:00 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** return a str[10] with de right of the file
*/

char	*setright(int mode, char c)
{
	char	right[11];

	if (S_ISLNK(mode) && c == 'c')
		c = 'l';
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
	right[10] = '\0';
	return (ft_strdup(right));
}

/*
** Put the date information in the str "itab"
*/

char	**setdate(char **date, char **itab, time_t ct)
{
	int i;

	i = 0;
	date[4][4] = '\0';
	date[3][5] = '\0';
	if ((ct - time(NULL) > -15778800) && (ct - time(NULL) < 3600))
		itab[7] = ft_strdup(date[3]);
	else
		itab[7] = ft_strdup(date[4]);
	itab[6] = ft_strdup(date[2]);
	itab[5] = ft_strdup(date[1]);
	while (i < 6)
	{
		free(date[i]);
		i++;
	}
	free(date);
	return (itab);
}

/*
** Put informations in itab
** type is the idex of the macro TYPE
** str is the name of the file/directory
** pat is the path of the file/directory
*/

size_t	ft_addinfo(char **itab, unsigned char type, char *pat)
{
	struct stat		stt;
	struct passwd	*ginfo;
	struct group	*group;
	char			**date;

	lstat(pat, &stt);
	ginfo = getpwuid(stt.st_uid);
	itab[0] = setright(stt.st_mode, TYPE[type]);
	date = ft_strsplit(ctime(&stt.st_mtime), ' ');
	setdate(date, itab, stt.st_mtime);
	if (itab[0][0] == 'c' || itab[0][0] == 'b')
		itab[4] = majmin(stt.st_rdev);
	else
		itab[4] = ft_itoa(stt.st_size);
	if ((group = getgrgid(stt.st_gid)))
		itab[3] = ft_strdup(group->gr_name);
	else
		itab[3] = NULL;
	if (ginfo == NULL)
		itab[2] = ft_strdup("502");
	else
		itab[2] = ft_strdup(ginfo->pw_name);
	itab[1] = ft_itoa(stt.st_nlink);
	ft_strdel(&pat);
	return (stt.st_blocks);
}

/*
** addinfotab is a loop that call addinfo for each file
*/

void	ft_addinfotab(char **tab, size_t ct, unsigned char *type, char *str)
{
	int		i;
	size_t	tot;
	char	***itab;

	tot = 0;
	i = 0;
	itab = (char ***)ft_memalloc(sizeof(char **) * ct);
	while ((size_t)i < ct)
	{
		itab[i] = (char **)ft_memalloc(sizeof(char *) * 8);
		tot += ft_addinfo(itab[i], type[i], ft_strjoin(str, tab[i]));
		if (itab[i][3] == NULL)
		{
			tab[0] = ft_strdup("");
			ft_freeitab(itab);
			return ;
		}
		i++;
	}
	tab = fullinfo(itab, tab, ct);
	ft_putstr("total ");
	ft_putnbr(tot);
	ft_putchar('\n');
}

void	ft_addinfotab2(char **tab, size_t ct, unsigned char *type, char *str)
{
	int		i;
	size_t	tot;
	char	***itab;

	tot = 0;
	i = 0;
	itab = (char ***)ft_memalloc(sizeof(char **) * ct);
	while ((size_t)i < ct)
	{
		itab[i] = (char **)ft_memalloc(sizeof(char *) * 8);
		tot += ft_addinfo(itab[i], type[i], tab[i][0] == '/' ?
				ft_strdup(tab[i]) : ft_strjoin(str, tab[i]));
		i++;
	}
	tab = fullinfo(itab, tab, ct);
	ft_strdel(&str);
}
