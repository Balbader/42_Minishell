/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 16:04:28 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export_error(char *err)
{
	g_error = 1;
	ft_putstr_fd(STDERR_FILENO, ERROR_EXP_START);
	ft_putstr_fd(STDERR_FILENO, "`");
	ft_putstr_fd(STDERR_FILENO, err);
	ft_putstr_fd(STDERR_FILENO, "'");
	ft_putstr_fd(STDERR_FILENO, ERROR_EXP_END);
}
