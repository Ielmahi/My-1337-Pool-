/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:03:10 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/27 21:03:34 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len_str;

	len_str = 0;
	while (str[len_str])
		len_str++;
	return (len_str);
}
/*
int	main(void)
{
	char	*str;
	int		len;

    str = "ilias";
    len = ft_strlen(str);
    printf("%d\n", len);
}
*/
