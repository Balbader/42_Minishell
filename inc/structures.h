/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/08 10:27:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

enum	e_status
{
	SUCCESS = 0,
	FAILURE = -1
};

enum	e_start
{
	START = 0,
	END
};

typedef struct s_token
{
	char			*word;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_exec
{
	char	**cmd;
	char	*path;
}	t_exec;

typedef struct s_data
{
	char	*input;
	t_token	*cmd_line;
	char	**env;
	bool	subgect_flag;
}	t_data;

/************************** basil stuff*/
typedef struct s_env
{
	char			*key;
	char			*value;
	// struct s_env	*next;
}	t_env;

/*
function(t_list *list)
{
	t_env env = (t_env)list->content;
}
*/

#endif // !STRUCTURES_H
