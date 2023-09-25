/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:56 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 15:44:57 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_env(int fd)
{
	t_env	*env;
	env = ft_get_all_env();
	while (env)
	{
		ft_putstr_fd(fd, env->var);
		write(fd, "\n", 1);
		env = env->next;
	}
	return (g_error = 0, true);
}
