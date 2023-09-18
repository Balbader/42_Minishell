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

/*
 * Welcome to the builtins branch
 * new
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*env_list = NULL;
	int		env_len;
	// t_env	*new_lst = NULL;

	env_len = ft_get_env_len(env);
	env_list = *(ft_get_env(env, 0, 0));
	// new_lst = ft_add_var_to_env("mimi=balou", env_list);
	// new_lst = ft_add_var_to_env("balou=mimi", env_list);
	// ft_exec_env(new_lst, 1);
	ft_exec_env(env_list, 1);
	ft_del_env(env_list);
	return (0);
}
