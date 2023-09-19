/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 11:32:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>

typedef enum	e_type
{
	APPEND = 0, // >>
	HEREDOC, // <<
	LIMITOR, //anything after a HEREDOC
	FD, //anything after > or <
	PIPE, // '|'
	R_IN, // <
	R_OUT, // >
	WORD, // anything else
}				t_type;

typedef enum	e_quote
{
	NOQUOTE = 0,
	SQUOTE,
	DQUOTE
}				t_quote;

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
	t_type			type;
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
	int				id;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/*
function(t_list *list)
{
	t_env env = (t_env)list->content;
}
*/

#endif // !STRUCTURES_H
