* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigval_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:58:10 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/21 15:44:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_sig(int sig)
{
	(void)sig;
	close(STDIN_FILENO);
	global_err = 128;
	return ;
}

static void	sighandler(int sig)
{
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGINT)
	{
		global_err = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	siginit(int type)
{
	if (!type)
	{
		signal(SIGINT, &sighandler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}


//provisoire 
#define WRITE 42

int	set_sigval(int new_sig)
{
	static int	sigval = -42;

	if (sigval == WRITE)
		sigval = new_sig;
	return (sigval);
}

//////





