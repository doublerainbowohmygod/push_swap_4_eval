/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:30:00 by aoneil            #+#    #+#             */
/*   Updated: 2025/11/14 20:30:56 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_countwords(char const *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	wordcount;

	flag = 0;
	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			wordcount++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (wordcount);
}

static char	*ft_newword(char const *s, size_t *i, char c)
{
	char			*newword;
	unsigned int	wordstart;
	size_t			wordlen;
	size_t			k;

	wordlen = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	wordstart = *i;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*i)++;
		wordlen++;
	}
	newword = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!newword)
		return (NULL);
	k = 0;
	while (k < wordlen)
		newword[k++] = s[wordstart++];
	newword[k] = '\0';
	return (newword);
}

static void	ft_freearrarr(size_t *j, char **arrarr)
{
	while (*j > 0)
	{
		free(arrarr[*j - 1]);
		(*j)--;
	}
	free(arrarr);
}

static char	**fill_arrarr(char const *s, char **arr, size_t wc, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < wc)
	{
		arr[j] = ft_newword(s, &i, c);
		if (!arr[j])
		{
			ft_freearrarr(&j, arr);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arrarr;
	size_t	wordcount;
	size_t	i;

	if (!s)
		return (NULL);
	wordcount = ft_countwords(s, c);
	arrarr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!arrarr)
		return (NULL);
	i = 0;
	while (i <= wordcount)
		arrarr[i++] = NULL;
	arrarr = fill_arrarr(s, arrarr, wordcount, c);
	return (arrarr);
}
