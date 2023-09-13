#ifndef EXPAND_H
# define EXPAND_H

typedef enum	e_quote
{
	NOQUOTE = 0,
	DQUOTE,
	SQUOTE
}				t_quote;

char	*quote_remove(char *str);
#endif
