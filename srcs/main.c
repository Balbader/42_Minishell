/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	global_err;

int	display_prompt(t_data *in, t_exec *exec, char **env)
{
	while (1) //replace by signal management
	{
		ft_putstr_fd("$> ", 1);
		in->input = readline("");
		if (parse_input(in, env) != 0)
			return (free(in->input), 2);//replace by exec_err_msg to avoid quitting program
		if (ft_strncmp(in->input, "STOP", 4) == 0)
			break ;
		exec_cmd(in, exec);
		add_history(in->input);
		rl_on_new_line();
		free(in->input);
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_data	in;

	in = NULL;
	(void) av;
	if (ac != 1)
		return (0);
	init_env(env);
	siginit(false);
	if (display_prompt(in) != SUCCESS)
		ft_putstr_fd("Something wrong happened forcing Minishell to stop!\n");
	ft_printf("Minishell stopped normally\n");
	return (0);
}
