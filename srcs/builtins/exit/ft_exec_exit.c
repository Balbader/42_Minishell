/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:38:59 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/05 09:01:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_exit(t_token *token, t_cmd *cmd)
{
	int	exit_value;

	if (cmd->fd[0] != STDIN_FILENO || cmd->fd[1] != STDOUT_FILENO)
		return (g_error = 0, true);
	exit_value = g_error;
	if (token)
	{
		if (ft_str_is_digit(&token->word))
			exit_value = ft_atoi(token->word);
		else
			exit(ft_print_exit_error(cmd, token->word));
	}
	if (ft_get_token_len(token) > 1)
		return (g_error = 1, ft_putstr_fd(ERROR_TO_MANY, STDERR_FILENO), true);
	ft_free_cmd(cmd);
	ft_del_env();
	rl_clear_history();
	exit(exit_value);
	return (g_error = 1, true);
}
