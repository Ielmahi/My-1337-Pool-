/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:07:23 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/09 14:30:03 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_recursive(long num, char *base, int base_len)
{
	if (num >= base_len)
	{
		ft_putnbr_base_recursive(num / base_len, base, base_len);
		ft_putnbr_base_recursive(num % base_len, base, base_len);
	}
	else
		ft_putchar(base[num]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	num;

	if (!is_valid_base(base))
		return ;
	base_len = 0;
	while (base[base_len])
		base_len++;
	num = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	ft_putnbr_base_recursive(num, base, base_len);
}
/*
int	main(void)
{
	ft_putnbr_base(42, "012346789");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n", 1);
    ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n", 1);
    ft_putnbr_base(0, "01");
	write(1, "\n", 1);
*/
