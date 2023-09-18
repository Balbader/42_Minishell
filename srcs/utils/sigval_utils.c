/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigval_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:58:10 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/18 16:52:06 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define WRITE 42

int	set_sigval(int new_sig)
{
	static int	sigval = -42;

	if (sigval == WRITE)
		sigval = new_sig;
	return (sigval);
}
