/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_for_builtins.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:55 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 14:57:57 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_cmd_for_builtins(char *path, char *cmd)
{
	if (ft_strcmp(cmd, "export") || ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "pwd")
		|| ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "unset")
		|| ft_strcmp(cmd, "exit") || ft_strcmp(cmd, "env"))
	{
		if (path)
			free(path);
		return (ft_strdup(cmd));
	}
	if (!path)
		return (error_cmd(cmd), path);
	return (path);
}
