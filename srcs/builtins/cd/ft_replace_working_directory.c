/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_working_directory.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:05:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:05:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_working_directory(void)
{
	static const char	old_pwd[9] = "OLDPWD=\0";
	static const char	cur_pwd[5] = "PWD=\0";
	char				*wd;
	char				*o_wd;
	char				*tmp;

	o_wd = ft_find_value("PWD");
	wd = getcwd(NULL, 0);
	if (!wd)
		return (g_error = 127, (void)error_msg("getcwd fail\n"));
	tmp = wd;
	wd = ft_strjoin(cur_pwd, wd);
	free(tmp);
	o_wd = ft_strjoin(old_pwd, o_wd);
	ft_del_from_env("OLDPWD");
	ft_add_to_env(o_wd);
	free(o_wd);
	ft_del_from_env("PWD");
	ft_add_to_env(wd);
	free(wd);
}
