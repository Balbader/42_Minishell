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
	t_env	*env_list;
	int		env_len;
	int		i;

	env_len = ft_get_env_len(env);
	printf("env_len : %d\n", env_len);
	printf("\n");
	env_list = NULL;
	env_list = ft_convert_env_to_list(env_len, env_list, env);
	i = 0;
	while (i < env_len)
	{
		printf("env id : %d\n", env_list->id);
		printf("env->key : %s\n", env_list->key);
		printf("env->value : %s\n", env_list->value);
		printf("\n");
		env_list = env_list->next;
		++i;
	}
	return (0);
}
