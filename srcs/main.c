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
	t_env	*env_lst = NULL;
	char	*new_lst = "NAME=basil";

	env_lst = *(ft_get_env(env, NULL, NULL));
	ft_add_var_to_env(env_lst, new_lst);
	env_lst = ft_del_node(env_lst, new_lst);
	ft_exec_env(1);
	ft_del_env();
	return (0);
}
