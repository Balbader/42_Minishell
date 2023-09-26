/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sig_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:55:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 15:55:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_sig_error(void)
{
	if (g_error == 128 + SIGTERM)
		ft_putstr_fd("Terminated\n", STDERR_FILENO);
	else if (g_error == 128 + SIGSEGV)
		ft_putstr_fd("Segmentation fault (core dumped)\n", STDERR_FILENO);
	else if (g_error == 128 + SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	else if (g_error == 128 + SIGABRT)
		ft_putstr_fd("Aborted (core dumped)\n", STDERR_FILENO);
}
