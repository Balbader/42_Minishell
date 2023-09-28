/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_working_directory.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:18:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:18:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_working_directory(void)
{
	char	*wd;

	wd = ft_find_value("OLDPWD");
	if (!wd)
	{
		g_error = 1;
		printf("minishell: cd: OLDPWD not set\n");
	}
	else
	{
		chdir(wd);
		ft_putstr_fd(wd, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		ft_replace_working_directory();
	}
}
