/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <ilelmahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:07:26 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/13 22:19:22 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*start;
	char	*ptr;

	src_len = 0;
	if (src == NULL)
		return (NULL);
	while (src[src_len])
		src_len++;
	ptr = (char *)malloc(sizeof(char) * src_len + 1);
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (*src)
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\0';
	return (start);
}
/*
int	main(void)
{
	char	*s;
	char	*t;

	s = "ilias";
	t = ft_strdup(s);
	printf("this is the duplicate string : %s\n",t);
}
*/
