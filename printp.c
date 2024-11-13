/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:12:25 by tcarlier          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:28 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	nb_len16(unsigned long long n)
{
	int			count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count + 1);
}

char	*int_to_hexa(unsigned long long n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((nb_len16(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = nb_len16(n) - 1;
	while (n > 0)
	{
		if (n % 16 > 9)
			str[i--] = n % 16 + 'W';
		else
			str[i--] = n % 16 + '0';
		n = n / 16;
	}
	str[nb_len16(n)] = '\0';
	return (str);
}

int	printp(unsigned long long nb)
{
	char	*str;
	int		len;

	if (!nb)
		prints("(nul)");
	str = int_to_hexa(nb);
	len = 0;
	if (str && ft_strlen(str) > 0)
		len += prints("0x");
	len += prints(str);
	free(str);
	return (len);
}
