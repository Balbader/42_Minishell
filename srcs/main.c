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

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*env_lst = NULL;
	int		env_len;
	// char	*new_lst = "NAME=basil";
	char	*replace = "EDITOR=mimi";

	env_len = ft_get_env_len(env);
	env_lst = *(ft_get_env(env));
	// ft_export_var_to_env(new_lst, &env_lst);
	ft_exec_env(env_lst, 1);
	ft_find_and_replace(replace, &env_lst);
	return (0);
}
