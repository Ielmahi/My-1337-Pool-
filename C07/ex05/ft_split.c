/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:10:06 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/07/13 22:10:08 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		str++;
	}
	return (count);
}

char	*copy_words(char *word_start, int word_len, int *in_word, int *wrd_len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = word_start[i];
		i++;
	}
	word[i] = '\0';
	*in_word = 0;
	*wrd_len = 0;
	return (word);
}

void	process_string(char *str, char *charset, char **result, int *index)
{
	char	*word_start;
	int		word_len;
	int		in_word;

	word_len = 0;
	in_word = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset) && in_word)
			result[(*index)++] = copy_words(word_start, word_len, &in_word,
					&word_len);
		else if (!is_in_charset(*str, charset))
		{
			if (!in_word)
			{
				word_start = str;
				in_word = 1;
			}
			word_len++;
		}
		str++;
	}
	if (in_word)
		result[(*index)++] = copy_words(word_start, word_len, &in_word,
				&word_len);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	char	**result;
	int		index;

	len = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	index = 0;
	process_string(str, charset, result, &index);
	result[index] = NULL;
	return (result);
}
/*
int	main(void)
{
	char	str[] = "ilias elmahi a7san wake ";
	char	charset[] = " ";
	char	**result;
	int		i;

	result = ft_split(str, charset);
	i = 0;
	while (result[i])
	{
		printf("result[%d]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/