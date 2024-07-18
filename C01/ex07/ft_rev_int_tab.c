/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:03:48 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/27 21:04:26 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
/*
int	main(void)
{
	int	arr[5];
	int	i;

    arr[5] = {0,1,2,3,4};
    ft_rev_int_tab(arr,5);
    i = 0;
    while(i < 5)
    {
        printf("%d ",arr[i]);
        i++;
    }
}
*/
