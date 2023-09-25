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

int	ft_print_exit_error(t_data *data, char *var)
{
	ft_del_env();
	rl_clear_history();
	ft_putstr_fd(STDERR_FILENO, "Minishell: exit: ");
	ft_putstr_fd(STDERR_FILENO, var);
	free_cmd(cmd);
	ft_putstr_fd(STDERR_FILENO, " : numeric argument required\n");
	return (2);
}
