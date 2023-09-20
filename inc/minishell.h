/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/20 15:53:18 by ftuernal         ###   ########.fr       */
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
# include "../libft/includes/libft.h"

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
# include <stdio.h>

/*
*******************************************************************************
******************************************************************** PARSER
*******************************************************************************
*/
t_token		*add_all_words_nodes( char **tab);
void		addback_cmdline_node(t_token **cmd_line, t_token *new);
int			append_cmd_node(t_token *cmd_line, char *line);
bool		check_quotes(char *input);
int			count_token(char *line);
void		delall(t_data *in);
t_token		*cmdline_new_node(char *input);
t_token		*goto_last_node(t_token *ptr);
int			parse_input(t_data *in);
bool		quote_on(const char *input, int index);
char 		**sep_cmdline(char *line);
int 		set_end_word(char *line, int start);
int 		set_start_word(char *line, int i);
int			split_into_words(t_data *in);
void	    tokenizer(t_token *cmd_line);

//DEBUG FUNCTIONS
void		print_all_words(t_token *cmd_line);
//void		delall(t_data *in);


/*
*******************************************************************************
******************************************************************** EXPANDER
*******************************************************************************
*/
int			expand(t_token *cmd_line);
int			expand_noquote_word(t_token *cmd_line, char *word);
int			expand_quote_word(t_token *cmd_line, char *word);
char		*expand_var(char *word);
char		*quote_remove(char *str);
char		*replace_by_env_value(char *word);
char		*replace_by_last_ret(char *word);
char		*replace_var_by_value(char *ptr);
t_quote		set_quote_type(char quote);
void		substitute_word(t_token *cmd_line, char *substitute);

/*
*******************************************************************************
******************************************************************** EXEC
*******************************************************************************
*/
void		exec_cmd(t_data *in, t_exec *cmd);

/*
*******************************************************************************
******************************************************************** BUILTINS
*******************************************************************************
*/
// env
int			ft_get_env_len(char **env);
int			ft_env_err(char **env, t_env *env_cpy, int output_fd);
int			ft_exec_env(t_env *env, int fd_out);
int			ft_get_key_len(char *str);
int			ft_get_value_len(char *str);
char		*ft_copy_key(char *env_elem, char *key_cpy, char stop);
char		*ft_copy_value(char *env_elem, char *value_cpy);
void		ft_env_fail(const char *message, char **env);
t_env		*ft_create_new_env_node(int id, char *key_cpy, char *value_cpy);
t_env		*ft_convert_env_to_list(int env_len, t_env *env_lst, char **env);
void		ft_env_fail(const char *message, char **env);
void        ft_del_env(t_env *env);




/*
*******************************************************************************
******************************************************************** UTILS
*******************************************************************************
*/
void		ft_free_tabs(char **tab);
void    	free_2_tabs(char **s1, char **s2);
t_env		**get_env(char **env);
int 		get_tab_len(char **tab);
char		*join_all_str(char **split);
char		*join_free(char *s1, char *s2, char *ptr);
int 		read_sigval(void);
int 		set_sigval(int new_sig);






//DEBUG
int ft_printenv(t_env *env);




















#endif // !MINISHELL_H
