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
	char	*new_lst = "NAME=basil";
	t_env	*to_del = NULL;
	// char	*replace = "NAME=mimi";

	to_del = ft_convert_char_to_node(new_lst);
	printf("to_del->key : %s\n", to_del->key);
	printf("to_del->value : %s\n", to_del->value);
	printf("to_del->var : %s\n", to_del->var);
	printf("\n\n\n");

	env_lst = *(ft_get_env(env));
	ft_exec_env(env_lst, 1);
	printf("\n\n\n");

	ft_add_var_to_env(new_lst, &env_lst);
	ft_exec_env(env_lst, 1);
	printf("\n\n\n");

	ft_del_var_in_env(to_del, &env_lst);
	ft_exec_env(env_lst, 1);

	ft_del_env(env_lst);
	return (0);
}
