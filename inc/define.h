/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 13:55:47 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* To be completed */

#ifndef DEFINE_H
# define DEFINE_H

# define ERROR_FILE "Error filename after redir -> function to do\n"
# define ERROR_PARSING "$> bash : syntax error near unexpected token"
# define ERROR_RED "No such file or directory\n"
# define ERROR_EXP_START "export: "
# define ERROR_EXP_END "': not a valid identifier\n"
# define ERROR_CMD ": command not found\n"
# define ERROR_ARG_CD "Wrong number of argument\n"
# define ERROR_TO_MANY "$> bash: exit: too many arguments\n"
# define ERROR_POINT "$> bash: .: filename argument required\n"
# define ERROR_DOUBLE_POINT "..: command not found\n"
# define ERROR_POINT_SLASH "$> bash: ./: Is a directory\n"
# define ERROR_FORK "$> bash: fork() function error\n"

#endif // !DEFINE_H
