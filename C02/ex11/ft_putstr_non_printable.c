/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:22:22 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/02 23:40:54 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		a;
	int		b;

	hex = "0123456789abcdef";
	while (*str)
	{
		if ((*str >= 0 && *str <= 31) || *str == 127
			|| (unsigned char)*str > 127)
		{
			ft_putchar('\\');
			a = ((unsigned char)*str / 16);
			b = ((unsigned char)*str % 16);
			ft_putchar(hex[a]);
			ft_putchar(hex[b]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
/*
int	main(void)
{
	char	*str;

	str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}
*/
