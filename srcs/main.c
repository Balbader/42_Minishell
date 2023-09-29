/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 14:09:30 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

static void	init_in(t_data **in)
{
	*in = ft_calloc(1, sizeof(t_data));
	if (!(*in))
		return ;
	(*in)->input = NULL;
	(*in)->cmd_line = NULL;
	(*in)->cmd = NULL;
}

int	display_prompt(t_data *in)
{
	while (1) //replace by signal management
	{
		ft_putstr_fd("$> ", 1);
		in->input = readline("");
		if (parse_input(in) == SUCCESS)
		{
			if (expand(in->cmd_line) == SUCCESS)
				exec(in);
		}
		add_history(in->input);
		rl_on_new_line();//do I need that function to respawn the readline ?
		free(in->input);//do I need to keep input allocated to get history
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_data	*in;
	t_env	*env_lst;

	(void) av;
	if (ac != 1)
		return (0);
	in = NULL;
	init_in(&in);
	if (!in)
		return (0);
	env_lst = NULL;
	env_lst = *ft_get_env(env, 0, 0);
	ft_init_signal(false);
	if (display_prompt(in) != SUCCESS)
		ft_putstr_fd("Something wrong happened forcing Minishell to stop!\n", 2);
	ft_del_env();
	rl_clear_history();
//delall
	printf("Minishell stopped normally\n");
	return (0);
}
