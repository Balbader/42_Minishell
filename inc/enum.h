/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:40:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 13:41:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_type
{
	APPEND = 0,
	HEREDOC,
	LIMITOR,
	FD,
	PIPE,
	R_IN,
	R_OUT,
	WORD,
}				t_type;

typedef enum e_quote
{
	NOQUOTE = 0,
	SQUOTE,
	DQUOTE
}				t_quote;

enum e_status
{
	SUCCESS = 0,
	FAILURE = -42
};

enum e_start
{
	START = 0,
	END
};

enum e_fd
{
	IN = 0,
	OUT
};

#endif
