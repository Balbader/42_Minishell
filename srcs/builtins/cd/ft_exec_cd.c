/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:34:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:34:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_cd(t_token *token, int in, int out)
{
	char	*wd;

	wd = NULL;
	g_error = 0;
	if (in != STDIN_FILNO || out != STDOUT_FILENO)
		return (true);
	if (!token || ft_get_token_len(token) > 1)
		return (g_error = 1, error_msg(ERROR_ARG_CD), true);
	if (!ft_find_value("PWD"))
		ft_create_working_directory();
	if (ft_strcmp("-", token->word))
		ft_change_working_directory();
	else
	{
		ft_get_cd_path(&token->word);
		if (chdir(token->word) == -1)
		{
			g_error = 1;
			perror(wd);
		}
		ft_replace_working_directory();
	}
	return (true);
}
