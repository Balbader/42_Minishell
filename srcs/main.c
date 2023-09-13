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
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*env_list;
	int		env_len;

	env_len = ft_get_env_len(env);
	env_list = NULL;
	env_list = ft_convert_env_to_list(env_len, env_list, env);
	ft_exec_env(env_list, 1);
	ft_del_env(env_list);
	return (0);
}
