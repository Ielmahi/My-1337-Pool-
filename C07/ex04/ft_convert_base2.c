/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:09:56 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/15 23:52:48 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);
int	check_base(char *base);

int	is_spaces(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_includet_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	index_ele(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	conver_to_dicimal(char *str, char *base)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = ft_strlen(base);
	while (is_includet_base(str[i], base) && str[i])
	{
		res = (res * len) + index_ele(str[i], base);
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	len = ft_strlen(base);
	if (check_base(base) || len < 2)
		return (0);
	while (is_spaces(str[i]) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign * conver_to_dicimal(&str[i], base));
}
