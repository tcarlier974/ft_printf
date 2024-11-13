/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:36 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/13 22:06:15 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printx(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	if (!n)
		return (prints("(nul)"));
	str = int_to_hexa(n);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] += 'A' - 'a';
		i++;
	}
	len += prints(str);
	free(str);
	return (len);
}

int	print_x(unsigned int nb)
{
	char	*str;
	int		len;

	if (!nb)
		prints("(nul)");
	str = int_to_hexa(nb);
	len = 0;
	len += prints(str);
	free(str);
	return (len);
}
