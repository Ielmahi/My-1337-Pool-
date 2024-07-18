/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:41:43 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/02 23:41:20 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(unsigned char c)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	print_hex(unsigned char c)
{
	char	*hex;
	char	buff[2];

	hex = "0123456789abcdef";
	buff[0] = hex[c / 16];
	buff[1] = hex[c % 16];
	write(1, buff, 2);
}

void	print_address(unsigned long addr)
{
	char	*hex;
	char	buff[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buff[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buff, 16);
}

void	print_line(unsigned char *ptr, unsigned int size, unsigned int i)
{
	unsigned int	j;

	j = 0;
	print_address((unsigned long)(ptr + i));
	write(1, ": ", 2);
	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_hex(ptr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
	j = 0;
	while (j < 16 && i + j < size)
	{
		print_char(ptr[i + j]);
		j++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		print_line(ptr, size, i);
		i += 16;
	}
	return (addr);
}
/*
int	main(void)
{
	char	str[] = "ilias elmahi wake up .";
	printf("%p\n",str);
	printf("%p\n",str);
	ft_print_memory(str, sizeof(str) - 1);
}
*/
