/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:44:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 09:44:12 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_fail(const char *message, char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		free(env[i++]);
	if (env)
		free(env);
	perror(message);
	exit(EXIT_FAILURE);
}
