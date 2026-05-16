/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehorvat <ehorvat@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:41:26 by ehorvat           #+#    #+#             */
/*   Updated: 2026/05/16 14:58:37 by ehorvat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static size_t	ft_countwords(char *str, char separator)
{
	size_t	n_words;

	n_words = 0;
	while (*str)
	{
		while (*str && *str == separator)
			str++;
		if (*str)
			n_words++;
		while (*str && *str != separator)
			str++;
	}
	return (n_words);
}

static char	*ft_strndup(char *str, int size)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	dup = malloc (sizeof(char) * size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char separator)
{
	char	**splited_str;
	char	**i_ptr;
	char	*start_word;

	splited_str = malloc(sizeof(char *) * (ft_countwords(str, separator) + 1));
	if (!splited_str)
		return (NULL);
	i_ptr = splited_str;
	while (*str)
	{
		while (*str && *str == separator)
			str++;
		start_word = str;
		while (*str && *str != separator)
			str++;
		*i_ptr = ft_strndup(start_word, str - start_word);
		if (*i_ptr == NULL)
			return (ft_free_split(splited_str), NULL);
		i_ptr++;
	}
	*i_ptr = NULL;
	return (splited_str);
}
