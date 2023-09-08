/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/08 10:27:20 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
# include "../TOOLS/libtools/libtools.h"
# include "../TOOLS/ft_printf/ft_printf.h"
# include "../TOOLS/minishelltools/minishelltools.h"
*/
# include "structures.h"
# include "define.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <stdbool.h>

/*
*******************************************************************************
******************************************************************** PARSER
*******************************************************************************
*/
int			add_all_words_nodes(t_token **cmd_line, char **tab);
void		addback_cmdline_node(t_token **cmd_line, t_token *new);
int			alloc_parse_struct(t_data *in);
int			append_cmd_node(t_token *cmd_line, char *line);
bool		check_quotes(char *input);
void		del_all_nodes(t_data *in);
t_token		*cmdline_new_node(char *input);
int			cust_getenv(t_data *in, char **env);
t_token		*goto_last_node(t_token *ptr);
int			parse_input(t_data *in/*, char **env*/);
bool		quote_on(const char *input, int index);
//int 		sep_cmdline(char ***tab, char *line, int idx, int *(*set_lim)(char *, int *));
int 		sep_cmdline(char ***tab, char *line, int (*set_start)(char *), int (*set_end)(char *, int));
int 		set_end_word(char *line, int start);
int 		set_start_word(char *line);
int			split_into_words(t_data *in);
/*
//to be DEBUGGED
void		del_all_words(t_cmdlst *cmd_line);
int 		sep_in_words(t_data *in);
int 		split_in_words(t_cmdlst *cmd_line, char *line);
void		addback_word_node(t_token **words, t_token *new);
int			append_word_node(t_cmdlst *cmd_line, const char *line, int start, int len);
t_token		*goto_last_word(t_token *ptr);
int			process_qoff(t_cmdlst *cmd_line, const char *line, int start);
int			process_qon(t_cmdlst *cmd_line, const char *line, int start);
t_token		*word_new_node(char *line, int start, int len);
*/

//DEBUG FUNCTIONS
void	print_all_words(t_token *cmd_line);
void	delall(t_data *in);

/*
*******************************************************************************
******************************************************************** PARSER
*******************************************************************************
*/
void	exec_cmd(t_data *in, t_exec *cmd);


































#endif // !MINISHELL_H
