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
