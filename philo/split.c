/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:55:28 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 16:43:13 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static size_t	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_sp(char const *s, char *str, size_t i, size_t j)
{
	size_t	idx;

	idx = 0;
	while (j < i + 1)
	{
		str[idx] = s[j];
		j++;
		idx++;
	}
	str[idx] = '\0';
}

static void	ft_ss(char const *s, char c, char **str)
{
	size_t	i;
	size_t	stri;
	size_t	j;

	i = 0;
	stri = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str[stri] = (char *)malloc(sizeof(char) * (i - j + 2));
			if (str[stri] == NULL)
				return ;
			ft_sp(s, str[stri], i, j);
			stri++;
		}
		if (s[i] == c)
			j = i + 1;
		i++;
	}
}

static void	ft_allfree(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	wc;
	size_t	i;

	if (s == NULL)
		return (0);
	wc = ft_word_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (wc + 1));
	if (str == NULL)
		return (0);
	ft_ss(s, c, str);
	i = 0;
	while (i < wc)
	{
		if (str[i] == NULL)
		{
			ft_allfree(str);
			return (0);
		}
		i++;
	}
	str[wc] = 0;
	return (str);
}
