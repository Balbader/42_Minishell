/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:44:27 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 11:44:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * in case of failure
 * . free **env
 * . free *env_cpy
*/

void	ft_env_fail(const char *message, char **env, t_env *env_cpy)
{
	int	i;

	i = 0;
	while (env && env[i])
		free(env[i++]);
	if (env)
		free(env);
	ft_del_env(env_cpy);
	perror(message);
	exit(EXIT_FAILURE);
}
