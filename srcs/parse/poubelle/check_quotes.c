/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:26:19 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/31 14:48:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//This function screens inputs for having correctly closed quotes
bool	check_quotes(char *input)
{
	bool	singl_open;
	bool	doubl_open;
	int		i;

	i = -1;
	singl_open = false;
	doubl_open = false;
	while (input[++i])
	{
		if (input[i] == '\'' && doubl_open == false)
			singl_open = !singl_open;
		else if (input[i] == '\"' && singl_open == false)
			doubl_open = !doubl_open;
	}
	return (!singl_open && !doubl_open);
}
/*
int	main(int ac, char **av)
{
	char *str;

	(void)av;
	str = "$> echo \"'$'\"\"\""; 
	if (ac != 1)
		return (0);
	if (check_quotes(str))
		printf("%s is correct\n", str);
	else
		printf("%s IS NOT correct\n", str);
	return (0);
}
*/
