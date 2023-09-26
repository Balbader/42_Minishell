/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:31:52 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/08 10:31:53 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_error;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// ft_init_env(ac, av, env);
	t_env	*env_lst;

	env_lst = NULL;
	// env_lst = *(ft_get_env(env, NULL, NULL));
	env_lst = ft_create_env_list(env);
	while (env_lst)
	{
		printf("%s\n", env_lst->var);
		env_lst = env_lst->next;
	}
	ft_free_all_env(env_lst);
	// ft_del_env();
	return (g_error);
}
