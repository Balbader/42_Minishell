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
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int i = 0;
	int env_len = 0;

	env_len = ft_get_env_len(env);
	printf("env length : %d\n", env_len);

	while (env[i])
		{
			printf("env[%d] : %s\n", i, env[i]);
			++i;
		}
	return (0);
}
