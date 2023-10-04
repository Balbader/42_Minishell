/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:20:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/04 12:27:48 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int n)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		nb = -n;
		len += 1;
	}
	else if (n == 0)
		return (1);
	else
		nb = n;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	unsigned int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	len = len_nbr(n);
	nbr = malloc(sizeof(char) * len + 1);
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	nbr[len] = '\0';
	len -= 1;
	while (nb > 0)
	{
		nbr[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (nbr);
}

/*
static int	ft_get_n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_get_n_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = len - 1;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}
*/
