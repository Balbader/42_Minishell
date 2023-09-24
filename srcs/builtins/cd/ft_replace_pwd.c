/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:47:59 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 14:48:01 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_pwd(void)
{
	static const char	old_pwd[9] = "OLDPWD=\0";
	static const char	cur_pwd[5] = "PWD=\0";
	char				*pwd;
	char				*o_pwd;
	char				*tmp;

	o_pwd = ft_find_value("PWD");
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (g_error = 127, (void)error_msg("getcwd fail\n"));
	tmp = pwd;
	pwd = ft_strjoin(cur_pwd, pwd);
	free(tmp);
	o_pwd = ft_strjoin(old_pwd, o_pwd);
	ft_del_from_env("OLDPWD");
	ft_add_to_env(o_pwd);
	free(o_pwd);
	ft_del_from_env("PWD");
	ft_add_to_env(pwd);
	free(pwd);
}
