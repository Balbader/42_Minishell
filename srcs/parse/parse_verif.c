/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:29 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 13:22:37 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	strerr_parsing(char *str)
{
	g_error = 2;
	ft_print_error_msg(ERROR_PARSING);
	write(STDERR_FILENO, " '", 2);
	ft_putstr_fd(str, STDERR_FILENO);
	write(STDERR_FILENO, "'", 1);
	write(STDERR_FILENO, "\n", 1);
}

int	verif_token(t_type type, t_type last_token)
{
	if (last_token == HEREDOC && type != LIMITOR)
		return (FAILURE);
	if ((last_token == R_OUT || last_token == APPEND) && type != FD)
		return (FAILURE);
	if (type == PIPE && (last_token == PIPE || last_token == R_IN
			|| last_token == APPEND || last_token == HEREDOC))
		return (FAILURE);
	if (type == PIPE && last_token == 42)
		return (FAILURE);
	return (SUCCESS);
}

int	verif_last_token(t_type last_token, t_type type)
{
	if ((last_token == PIPE || last_token == R_IN || last_token == R_OUT
			|| last_token == APPEND || last_token == HEREDOC) && type == 42)
		return (FAILURE);
	return (SUCCESS);
}

int	parsing_verif(t_token *cmd_line)
{
	t_token	*ptr;
	t_type	last_token;

	last_token = -1;
	ptr = cmd_line;
	while (cmd_line != NULL)
	{
		if (verif_token(cmd_line->type, last_token) == FAILURE)
		{
			strerr_parsing(cmd_line->word);
			return (FAILURE);
		}
		last_token = cmd_line->type;
		ptr = cmd_line;
		cmd_line = cmd_line->next;
	}
	if (!cmd_line)
		if (verif_last_token(last_token, 42) == FAILURE)
			return (strerr_parsing(ptr->word), FAILURE);
	return (SUCCESS);
}
