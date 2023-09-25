/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:25:44 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:25:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_cd_path(char **path)
{
	char	*cdpath;
	int		fd;

	cdpath = ft_find_value("CDPATH");
	if (!cdpath)
		return ;
	if (cdpath[ft_strlen(cdpath)] == '/' || *cdpath == '/')
		cdpath = ft_strjoin(cdpath, *path);
	else
		cdpath = ft_add_slash(cdpath, *path);
	free(*path);
	*path = cdpath;
	fd = open(*path, O_DIRECTORY);
	if (!fd)
	{
		free(*path);
		*path = NULL;
		return ;
	}
	write(STDOUT_FILENO, *path, ft_strlen(*path));
	write(STDOUT_FILENO, "\n", 1);
	return ((void)close(fd));
}
