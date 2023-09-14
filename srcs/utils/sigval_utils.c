/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigval_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:58:10 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/14 15:58:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

int	read_sigval(void)
{
	return (sigval);
}

int	set_sigval(int new_sig)
{
	return (sigval = new_sig);
}

int	catch_sigval()
{}
