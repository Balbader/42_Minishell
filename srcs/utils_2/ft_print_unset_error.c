/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unset_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:40:57 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 16:40:58 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_unset_error(char *err)
{
	g_error = 1;
	ft_putstr_fd(STDERR_FILENO, "Minishell : unset:");
	ft_putstr_fd(STDERR_FILENO, "`");
	ft_putstr_fd(STDERR_FILENO, err);
	ft_putstr_fd(STDERR_FILENO, "'");
	ft_putstr_fd(STDERR_FILENO, ": not a valid identifier\n");
}
