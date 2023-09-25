/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exit_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:09:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 16:09:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_exit_error(t_cmd *cmd, char *var)
{
	ft_del_env();
	rl_clear_history();
	ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	free_cmd(cmd);
	ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	return (2);
}
