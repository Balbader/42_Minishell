/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:39:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 15:39:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_pwd(int fd)
{
	char	*wd;

	wd = getcwd(NULL, 0);
	if (!wd)
		return (g_error = 127, ft_print_error_msg("getcwd fail\n"), true);
	ft_putstr_fd(wd, fd);
	write(fd, "\n", 1);
	free(wd);
	return (g_error = 0, true);
}
