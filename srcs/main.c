/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/04 17:10:45 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

// void	clear_all(t_data *in)
// {
// 	if (in->cmd_line)
// 		ft_delete_all(&in->cmd_line);
// 	if (in->cmd)
// 		ft_free_cmd(in->cmd);
// 	if (in->input)
// 		free(in->input);
// 	free(in);
// }

int	display_prompt(void)
{
	char *in;
	while (1)
	{
		// ft_putstr_fd("$> ", 1);
		in = readline("$>");
		if (in == NULL)
			break ;
		if (parse_input(in) == SUCCESS)
			// do nothing // BUG TO FIX
		
		// if (parse_input(in) == SUCCESS)
		// {
			// if (expand(in->cmd_line) == SUCCESS)
			// 	exec(in);
		// }
		// else
		// 	ft_putstr_fd("\n", 1);
		add_history(in);
		rl_on_new_line();
		free(in);
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	// t_env	*env_lst;

	(void) av;
	if (ac != 1)
		return (0);
	ft_get_env(env, 0, 0);
	ft_init_signal(false);
	if (display_prompt() != SUCCESS)
		ft_putstr_fd("Something wrong happened forcing Minishell to stop!\n", 2);
	ft_del_env();
	// clear_all(in);
	rl_clear_history();
	printf("Minishell stopped normally\n");
	return (0);
}
