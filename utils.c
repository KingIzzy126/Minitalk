/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:38:24 by ismailalash       #+#    #+#             */
/*   Updated: 2024/03/15 16:50:22 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printfchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printfstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printfstr("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		ft_printfchar((int)*str);
		str++;
		i++;
	}
	return (i);
}

int	ft_printfint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_printfstr("-2147483648"));
	}
	else if (n < 0)
	{
		count += ft_printfchar('-');
		n = -n;
	}
	else if (n == 0)
	{
		return (ft_printfchar('0'));
	}
	if (n >= 10)
	{
		count += ft_printfint(n / 10);
	}
	count += ft_printfchar((n % 10) + '0');
	return (count);
}
