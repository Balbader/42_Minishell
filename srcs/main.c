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
	char *key_cpy;
	char *value_cpy;

	key_cpy = NULL;
	key_cpy = ft_copy_key(env[1], key_cpy, '=');

	value_cpy = NULL;
	value_cpy = ft_copy_value(env[1], value_cpy);

	printf("env[0] : %s\n", env[1]);
	printf("key_cpy : %s\n", key_cpy);
	printf("value_cpy : %s\n", value_cpy);
	return (0);
}
