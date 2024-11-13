/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:15 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/12 17:06:18 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printu(unsigned int n)
{
	int		len;
	char	*res;

	res = ft_itoa(n);
	len = prints(res);
	free(res);
	return (len);
}
