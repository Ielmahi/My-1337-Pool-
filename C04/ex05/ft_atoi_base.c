/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:03:45 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/09 14:29:38 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13) || base[i] == '+'
			|| base[i] == '-')
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
	return (i > 1);
}

char	*skip_whitespace_and_signs(char *str, int *sign)
{
	*sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	get_index_in_base(char c, char *base)
{
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int	calculate_result(char *str, char *base, int base_len)
{
	int	result;
	int	index;

	result = 0;
	while (*str)
	{
		index = get_index_in_base(*str, base);
		if (index == -1)
			break ;
		result = result * base_len + index;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;
	int	result;

	if (!is_valid_base(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	str = skip_whitespace_and_signs(str, &sign);
	result = calculate_result(str, base, base_len);
	return (result * sign);
}
/*
int main()
{
	printf("%d\n", ft_atoi_base("   +++---101010", "01"));
	printf("%d\n", ft_atoi_base("   -101010", "01"));
	printf("%d\n", ft_atoi_base("   +2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("   -2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("   42", "0123456789"));
}
*/
