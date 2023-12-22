/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_redir_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:55:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 16:55:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_redir_error(char *file) {
  write(STDERR_FILENO, "$> ", 4);
  write(STDERR_FILENO, file, ft_strlen(file));
  write(STDERR_FILENO, ": ", 2);
  write(STDERR_FILENO, ERROR_RED, ft_strlen(ERROR_RED));
  g_error = 1;
}
