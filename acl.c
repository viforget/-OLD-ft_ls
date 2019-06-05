/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:19:19 by viforget          #+#    #+#             */
/*   Updated: 2019/06/05 19:28:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_acl(char *pat)
{
	ssize_t	tmp;
	acl_t	acl;

	if ((acl = acl_get_file(pat, ACL_TYPE_EXTENDED)) != (acl_t)NULL)
	{
		acl_free((void*)acl);
		return ('+');
	}
	else if ((tmp = listxattr(pat, NULL, 0, XATTR_NOFOLLOW)) > 0)
		return ('@');
	return (' ');
}
