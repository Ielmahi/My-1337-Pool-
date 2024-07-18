/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:09:46 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/16 10:17:13 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (1);
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nbr_index(long res, int len_base)
{
	int	len;

	len = 0;
	if (res < 0)
	{
		res *= -1;
		len++;
	}
	while (res > 0)
	{
		res /= len_base;
		len++;
	}
	return (len);
}

char	*ft_zero(char *base)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	str[0] = base[0];
	str[1] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	res;
	char	*str;
	int		len_nbr;

	res = ft_atoi_base(nbr, base_from);
	if (check_base(base_to) || check_base(base_from))
		return (NULL);
	if (res == 0)
		return (ft_zero(base_to));
	len_nbr = nbr_index(res, ft_strlen(base_to));
	str = (char *)malloc((len_nbr + 1) * sizeof(char));
	str[len_nbr] = '\0';
	len_nbr--;
	if (res < 0)
	{
		str[0] = '-';
		res *= -1;
	}
	while (res > 0)
	{
		str[len_nbr--] = base_to[res % ft_strlen(base_to)];
		res /= ft_strlen(base_to);
	}
	return (str);
}
/*
int	main(void)
{
	char	*result;

	result = ft_convert_base("9223372036854775807", "0123456789", "01");
	printf("Large number 9223372036854775807 to Binary: %s\n", result);
	free(result);
	result = ft_convert_base("   +++---133742", "0123456789", "01");
	printf("%s\n", result);
	free(result);
	result = ft_convert_base("   ---101010", "01", "0123456789");
	printf("%s\n", result);
	free(result);
	result = ft_convert_base("   +---539", "0123456789abcdef", "0123456789");
	printf("%s\n", result);
	free(result);
	result = ft_convert_base(NULL, "0123456789abcdef", "0123456789");
	printf("%s\n", result);
	free(result);
	return (0);
}
*/