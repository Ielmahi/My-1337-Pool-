/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:25:00 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/15 15:25:03 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_sep_length(char *sep)
{
	int	sep_len;

	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	return (sep_len);
}

int	calculate_total_length(int size, char **strs, int sep_len)
{
	int	total_length;
	int	i;
	int	j;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			total_length++;
			j++;
		}
		if (i < size - 1)
			total_length += sep_len;
		i++;
	}
	return (total_length);
}

char	*allocate_result(int total_length)
{
	char	*result;

	result = (char *)malloc(total_length + 1);
	if (result == NULL)
		return (NULL);
	return (result);
}

void	concatenate_strings(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	j;
	int	k;
	int	sep_len;

	i = 0;
	k = 0;
	sep_len = get_sep_length(sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[k++] = strs[i][j++];
		}
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				result[k++] = sep[j++];
		}
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		sep_len;
	int		total_length;

	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	sep_len = get_sep_length(sep);
	total_length = calculate_total_length(size, strs, sep_len);
	result = allocate_result(total_length);
	if (result == NULL)
		return (NULL);
	concatenate_strings(size, strs, sep, result);
	return (result);
}
/*
int	main(void)
{
	char	*strs[] = {"Hello", "world", "this", "is", "a", "test"};
	char	*sep;
	int		size;
	char	*result;

	sep = " --> ";
	size = 6;
	result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("Concatenated string: %s\n", result);
		free(result);
	}
	else
		printf("Memory allocation failed\n");
	return (0);
}*/
