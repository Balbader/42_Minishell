/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:40:38 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/31 13:40:40 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	cust_getenv(t_data *in, char **env)
{
	in->env = super_strdup(env);
	if (in->env == 0)
		return (manage_err(ENV, in, NULL));
	return (0);
	//replace by environnement management
}
