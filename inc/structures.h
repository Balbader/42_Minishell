/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>

typedef enum	e_type
{
	APPEND = 0,
	HEREDOC, //anything after <<
	LIMITOR, //anything after >>
	FD, // anithing after > or <
	PIPE, // '|'
	R_IN, // <
	R_OUT, // >
	WORD // anything else
}				t_type;

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

/*
enum e_token
{
	WORD,
	FD,
	LIMITOR,
	R_IN,
	HEREDOC,
	R_OUT,
	APPEND,
	PIPE,
};
*/

typedef struct s_token
{
	char			*word;
	t_type			type; // why not use an int ???
	struct s_token	*next;
}	t_token;

typedef struct s_exec
{
	char	**cmd;
	char	*path;
}	t_exec;

/************************** basil stuff*/

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char	*input;
	t_token	*cmd_line;
	t_env	*env;
}	t_data;

#endif // !STRUCTURES_H
