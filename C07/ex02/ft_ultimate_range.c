/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:09:25 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/13 22:09:26 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*ptr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	ptr = (int *)malloc(sizeof(int) * size);
	if (ptr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		ptr[i] = min + i;
		i++;
	}
	*range = ptr;
	return (size);
}
/*
int	main(void)
{
	int	*arr;
	int	size;

	size = ft_ultimate_range(&arr,5,10);
	if (size>0)
	{
		for (int i = 0;i<size;i++)
			printf("%d\n",arr[i]);
		free(arr);
	}
}
*/
