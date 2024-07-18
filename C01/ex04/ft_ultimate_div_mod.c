/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:55:28 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/27 21:02:16 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}
/*
int	main(void)
{
	int	a;
	int	b;

    a = 20;
    b = 10;
    ft_ultimate_div_mod(&a,&b);
    printf("a / b = %d\n a %% b = %d\n",a,b);
}
*/
