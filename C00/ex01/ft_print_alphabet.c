/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:17:43 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/26 10:20:39 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	start;

	start = 'a';
	while (start <= 'z')
	{
		write(1, &start, 1);
		start++;
	}
}
