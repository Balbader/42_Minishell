/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:17:04 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 14:17:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * if no token : returns "\n"
 * check for -n flag
 * runs through tokens
 * if there is a variable to be printed to the console, will print the variable
 * to the console and move to the next token
 * once it reaches the end, will print "\n"
*/

int	ft_exec_echo(t_token *token, int fd)
{
	int	end_line;

	end_line = true;
	if (!token)
		return (write(fd, "\n", 1), true);
	while (token && token->word && ft_check_n_flag(token->word))
	{
		end_line = false;
		token = token->next;
	}
	while (token)
	{
		if (token->word)
			ft_putstr_fd(fd, token->word);
		token = token->next;
		if (token)
			write(fd, " ", 1);
	}
	if (end_line)
		write(fd, "\n", 1);
	return (g_error = 0, true);
}
