/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:44:08 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 11:44:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	lst_size_env(t_env *lst)
// {
// 	int		i;
// 	t_env	*tmp;

// 	i = 0;
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }

int	exec_env(t_cmdlst *cmd, int fd_out, t_env *env)
{
	t_env	*tmp;

	if (!cmd || !env)
		return (ft_putstr_fd("bash: env: env not defined\n", 2),
			EXIT_FAILURE);
	tmp = env;
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			ft_putstr_fd(tmp->key, fd_out);
			ft_putstr_fd("=", fd_out);
			ft_putendl_fd(tmp->value, fd_out);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}