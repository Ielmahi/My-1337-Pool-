/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:43 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/10 11:58:49 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	guess;

	guess = 0;
	while (guess * guess <= nb)
	{
		if (guess * guess == nb)
			return (guess);
		guess++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_sqrt(16));
	return (0);
}*/
