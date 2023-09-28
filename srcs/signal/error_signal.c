/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 15:10:09 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_signal(void)
{
	if (g_error == 128 + SIGTERM)
		ft_putstr_fd("Terminated\n", STDERR_FILENO);
	else if (g_error == 128 + SIGSEGV)
		ft_putstr_fd("Segmentation fault. (core dumped)\n", STDERR_FILENO);
	else if (g_error == 128 + SIGQUIT)
		ft_putstr_fd("Quit. (core dumped)\n", STDERR_FILENO);
	else if (g_error == 128 + SIGABRT)
		ft_putstr_fd("Abort. (core dumped)\n", STDERR_FILENO);
}
