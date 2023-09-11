/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:44:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 11:44:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	in case of err:
 *	. print err message
 *	. free **env
 *	. free *env_lst
*/

int	env_err(char **env, t_env *env_cpy, int output_fd)
{
	(void)output_fd;
	ft_putstr_fd("bash: export: `", 2);
	if (env[0])
	{
		ft_putstr_fd(env[0], 2);
		if (env[1])
		{
			ft_putstr_fd("=", 2);
			ft_putstr_fd(env[1], 2);
		}
	}
	ft_putstr_fd("': not a valid identifier\n", 2);
	ft_free_tabs(env);
	ft_del_env(env_cpy);
	return (EXIT_FAILURE);
}
