/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 02:27:22 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/02 23:40:29 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	check;
	int	i;

	check = 1;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (check && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!check && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			check = 0;
		}
		else
			check = 1;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[];

	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s\n",str);
}
*/
