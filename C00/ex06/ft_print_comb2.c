/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:15:39 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/26 19:04:13 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2_helper(char i, char j, char k, char l)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, " ", 1);
	write(1, &k, 1);
	write(1, &l, 1);
	if (!(i == '9' && j == '8' && k == '9' && l == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb2_inner(char i, char j)
{
	char	k;
	char	l;

	k = i;
	while (k <= '9')
	{
		if (k == i)
			l = j + 1;
		else
			l = '0';
		while (l <= '9')
		{
			ft_print_comb2_helper(i, j, k, l);
			l++;
		}
		k++;
	}
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			ft_print_comb2_inner(i, j);
			j++;
		}
		i++;
	}
}
/*
int main()
{
    ft_print_comb2();
}
*/
