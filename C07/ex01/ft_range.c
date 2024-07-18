/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:09:18 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/15 20:53:48 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	ptr = (int *)malloc(sizeof(int) * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	*arr;

	arr = ft_range(-3,0);
	for (int i=0;i<=3;i++)
	{
		printf("%d\n",arr[i]);
	}
	free(arr);
}
*/
