/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:56:37 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/26 14:56:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

int	main(int ac, char **av, char **env)
{
	char	*line;

	line = NULL;
	ft_init_env(ac, av, env);
	init_signal(false);
	while (true)
	{
		line = readline("Minishell :");
		if (line == NULL)
			break ;
		if (*line)
		{
			add_history(line);
			// shell_split(line);
		}
	}
	ft_del_env();
	rl_clear_history();
	write(STDOUT_FILENO, "exit\n", 5);
	return (g_error);
}

