/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:17:13 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 15:42:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../minishell.h"
# include "../EXECER/exec.h"

t_token		*add_all_words_nodes(char **tab);
void		addback_cmdline_node(t_token **cmd_line, t_token *new);
int			alloc_parse_struct(t_data *in);
int			append_cmd_node(t_token *cmd_line, char *line);
bool		check_quotes(char *input);
int			count_token(char *line);
void		del_all_nodes(t_data *in);
t_token		*cmdline_new_node(char *input);
int			cust_getenv(t_data *in, char **env);
t_token		*goto_last_node(t_token *ptr);
int			parse_input(t_data *in/*, char **env*/);
bool		quote_on(const char *input, int index);
//int 		sep_cmdline(char ***tab, char *line, int idx, int *(*set_lim)(char *, int *));
char 		**sep_cmdline(char *line);
int 		set_end_word(char *line, int start);
int 		set_start_word(char *line, int i);
int			split_into_words(t_data *in);
void	    tokenizer(t_token *cmd_line);
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
#endif
