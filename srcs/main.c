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
	t_env	*env_lst;
	t_env	*head;

	env_lst = NULL;
	env_lst = ft_create_env_list(env);
	head = env_lst;
	while (env_lst)
	{
		printf("env->var : %s\n", env_lst->var);
		env_lst = env_lst->next;
	}
	env_lst = head;
	ft_free_all_env(env_lst);
	return (g_error);
}
