/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:38:59 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/04 17:39:39 by ftuernal         ###   ########.fr       */
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
	printf("%zu\n", sizeof(t_cmd));
	ft_free_cmd(cmd);
	// ft_delete_all(&token);
	ft_del_env();
	rl_clear_history();
	close(0);
	// exit(exit_value);// TODO UNCOMMENT THIS
	return (g_error = 1, true);
}
