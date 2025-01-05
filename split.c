/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:07:29 by msokolov          #+#    #+#             */
/*   Updated: 2025/01/02 15:12:39 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while ((s[cursor] == c))
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		+len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		word_counts;
	char	**res_arr;
	int		i;

	i = 0;
	word_counts = count_words(s, c);
	if (!word_counts)
		exit(1);
	res_arr = malloc(sizeof(char *) * (size_t)(word_counts + 2));
	if (!res_arr)
		return (NULL);
	while (word_counts-- >= 0)
	{
		if (i == 0)
		{
			res_arr[i] = malloc(sizeof(char));
			if (!res_arr[i])
				return (NULL);
			res_arr[i++][0] = '\0';
			continue ;
		}
		res_arr[i++] = get_next_word(s, c);
	}
	res_arr[i] = NULL;
	return (res_arr);
}

int main()
{
	char *str = "HelloWorlditisatest";
	char delimiter = ' ';
	char **result;

	result = split(str, delimiter);

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word: %s\n", result[i]);
		free(result[i]);
	}
	free(result);

	return 0;
}
