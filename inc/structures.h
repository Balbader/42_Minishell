/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/04 17:35:28 by ftuernal         ###   ########.fr       */
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
	FAILURE = -42
};

enum	e_start
{
	START = 0,
	END
};

enum	e_fd
{
	IN = 0,
	OUT
};

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;


typedef struct	s_cmd
{
	t_token			*args;
	t_token			*rdir;
	int				fd[2]; //for the fuction pipe()
	int				pid; //for the function fork()
	struct s_cmd	*next;
}				t_cmd;

// typedef struct s_data
// {
// 	char	*input;
// 	t_token	*cmd_line;
// 	t_env	**env;
// 	t_cmd	*cmd;
// 	bool	subgect_flag;
// }	t_data;
#endif // !STRUCTURES_H
